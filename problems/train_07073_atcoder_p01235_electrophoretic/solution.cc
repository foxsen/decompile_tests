#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

using namespace std;

typedef complex<double> P;
const double EPS = 1e-8;

// 誤差を加味した符号判定
int sign(double a){
    if(a > EPS) return +1;
    if(a < -EPS) return -1;
    return 0;
}

// 内積・外積
double dot(P a, P b){return real(conj(a) * b);}
double cross(P a, P b){return imag(conj(a) * b);}

// OAとOBのなす符号付き角度 [-pi, pi]
// example : (1, 0), (0, 1) -> pi/2
double angle(P a, P b){return arg(conj(a) * b);}

// aをc中心にb[rad]回転
// verify : not yet.
P rotate(P a, double b, P c = P()){return (a - c) * polar(1.0, b) + c;}

// 直線ABに対する点Cの位置
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > +EPS)   return +1; // 反時計回り
    if (cross(b, c) < -EPS)   return -1; // 時計回り
    if (dot(b, c) < 0)     return +2; // c--a--b の順番で一直線上
    if (norm(b) < norm(c)) return -2; // a--b--c の順番で一直線上
    return 0;                         // 点が線分ab上にある
}

enum{ OUT, ON, IN };

typedef vector<P> L;
P vec(L l){return l[1] - l[0];}

// 注意: 端点で交わったり直線が重なったりする場合も交差していると判定する

// 二直線の平行判定
// verify : AOJ0021
bool paralell(L l, L m){return sign(cross(vec(l), vec(m))) == 0;}

// 二直線の同一判定
bool equalLL(L l, L m){return paralell(l, m) && sign(cross(vec(l), m[0] - l[0])) == 0;}

// 直線と点の交差判定
// 直線lとl[0]からpへの直線が平行
bool iLP(L l, P p) {return sign(cross(vec(l), p - l[0])) == 0;}

// 線分と点の交差判定(端点の処理に注意)
// verify : AOJ1279, AOJ2506
bool iSP(L s, P p) {return ccw(s[0], s[1], p) == 0;}

// 直線と線分の交差判定(線分が重なっている時に注意)
// 直線lについて、線分sの端点が異なる側にある
bool iLS(L l, L s) {return sign(cross(vec(l), s[0] - l[0]) * cross(vec(l), s[1] - l[0])) <= 0;}

// 二つの線分の交差判定(線分が重なっている時や端点の処理に注意)
bool iSS(L s, L t) {
    auto ok = [](L a, L b){return ccw(a[0],a[1],b[0]) * ccw(a[0],a[1],b[1]) <= 0;};
    return ok(s,t) && ok(t,s);
}


// 点pから直線lに対する射影
P proj(L l, P p){
    double t = dot(p - l[0], vec(l)) / norm(vec(l));
    return l[0] + t * vec(l);
}

// 点pの直線lに関する反射
P refl(L l, P p){return 2.0 * proj(l, p) - p;}

// 直線と点の距離
// Verified: AOJ 2201
double dLP(L l, P p){return abs(cross(vec(l), p - l[0])) / abs(vec(l));}

// 線分と点の距離
double dSP(L s, P p){
    if(sign(dot(vec(s), p - s[0])) <= 0) return abs(p - s[0]);
    if(sign(dot(-vec(s), p - s[1])) <= 0) return abs(p - s[1]);
    return dLP(s, p);
}

// 直線と直線の距離
double dLL(L l, L m){
    // 平行でないときは0, 平行のときは垂線の長さ
    return paralell(l, m) ? dLP(l, m[0]) : 0;
}

// 直線と線分の距離
double dLS(L l, L s){return iLS(l,s) ? 0.0 : min(dLP(l, s[0]), dLP(l, s[1]));}

// 線分と線分の距離
// Verified: AOJ 1157
double dSS(L s, L t){return iSS(s,t) ? 0.0 : min({dSP(s, t[0]), dSP(s, t[1]), dSP(t, s[0]), dSP(t, s[1])});}

// 直線と直線の交点
// Verified: AOJ2579
P pLL(L l, L m){
    double A = cross(vec(l), vec(m));
    double B = cross(vec(l), l[1] - m[0]);
    if(sign(A) == 0 && sign(B) == 0) return m[0]; // 二直線が重なっている
    if(sign(A) == 0) assert(false); // 直線が交わらない
    return m[0] + vec(m) * B / A;
}
typedef vector<P> Pol; // 反時計回りを仮定

// 点が多角形のどこにあるのか判定する
// verify : AOJ0012
int contains(const Pol& A, P p){
    // 点pから半直線をひき、辺と交差する回数を数える
    int in = 0;
    int n = A.size();
    for(int i = 0; i < n; i++){
        P a = A[i] - p;
        P b = A[(i + 1) % n] - p;
        if(a.imag() > b.imag()) swap(a, b);
        // aからbの直線がy=0と交わり、その交点は原点の右側である
        in ^= a.imag() <= 0 && 0 < b.imag() && cross(a, b) < 0;

        if(sign(cross(a, b)) == 0 && sign(dot(a, b)) <= 0) return ON;
    }
    return in ? IN : OUT;
}

// 多角形の面積
// verify : AOJ0079 AOJ1100
double area(const Pol& A) {
    double res = 0;
    int n = A.size();
    for(int i = 0; i < n; i++){
        res += cross(A[i], A[(i + 1) % n]);
    }
    return abs(res) / 2.0;
}
// 凸包
Pol convex_hull(vector<P> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end(),[](const P&a, const P&b){
            return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
            });

    vector<P> ch(2*n);
    for (int i = 0; i < n; ch[k++] = ps[i++]){ // lower-hull
        while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    }
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]){ // upper-hull
        while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    }
    ch.resize(k-1);
    return ch;
}

bool is_convex(const Pol& A){
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(ccw(A[i], A[(i + 1) % n], A[(i + 2) % n]) > 0) return false;
    }
    return true;
}

// 凸多角形の直線による切断。直線の左側だけ残す
// verify : aoj1283
Pol convex_cut(const Pol& A, L l){
    int n = A.size();
    Pol B;
    for(int i = 0; i < n; i++){
        P a = A[i], b = A[(i + 1) % n];
        if(ccw(l[0], l[1], a) != -1) B.push_back(a); //Aが直線lの右側でない
        if(ccw(l[0], l[1], a) * ccw(l[0], l[1], b) < 0)
            B.push_back(pLL(l, {a, b}));
    }
    return B;
}
// 垂直二等分線
// verify: maximamcup2013 D
L bisector(P a, P b){
    P mid = (a + b) / 2.0;
    P vec = (mid - a) * P(0.0, 1.0);
    return {mid, mid + vec};
}
// 点集合psのうちs番目のボロノイ領域
// verify: maximamcup2013 D
Pol voronoi_cell(Pol A, const vector<P>& ps, int s){
    for(int i = 0; i < ps.size(); i++){
        if(i != s) A = convex_cut(A, bisector(ps[s], ps[i]));
    }
    return A;
}
struct C{P p;double r;};

// 円と点の内外判定
// Verified: AOJ2181, AOJ2579
int contains(C c, P p){
    double d = abs(c.p - p);
    if(sign(d - c.r) > 0) return OUT;
    if(sign(d - c.r) == 0) return ON;
    return IN;
}

// 円と線分の交差判定(境界を含む)
// 接するときに注意!!
// Verified: AOJ0129, AOJ2506, AOJ2579
bool iCS(C c, L l){
    int c1 = contains(c, l[0]);
    int c2 = contains(c, l[1]);
    if(c1 > c2) swap(c1, c2);

    // (OUT, OUT) (OUT, ON) (OUT, IN) (ON, ON) (ON, IN) (IN, IN) の6通り
    if(c1 == OUT && c2 == IN) return true;
    if(c1 == IN  && c2 == IN) return false;
    if(c1 == ON) return true; // (接するとき) 
    double d = dSP(l, c.p);
    if(sign(d - c.r) < 0) return true;
    if(sign(d - c.r) == 0) return true; // (接するとき)
    if(sign(d - c.r) > 0) return false;
    assert(false);
}

// 二つの円の交差判定(接する時を含む)
// verified: AOJ 2181
bool iCC(C c, C d){
    // 円の中心同士の距離が、半径の和以下であり、半径の差以上である
    double e = abs(d.p - c.p);
    return sign(e - (c.r + d.r)) <= 0 && sign(e - abs(c.r - d.r)) >= 0;
}

// 円cに対して円dがどの位置にあるか(IN:内側, ON: 交差, OUT: それ以外)
// Verified: AOJ 2181
int contains(C c, C d) {
    double e = abs(c.p - d.p);
    if(sign(c.r - d.r) > 0 && sign(c.r - (d.r + e)) > 0) return IN;
    if(iCC(c, d)) return ON;
    return OUT;
}

// 円と直線の交点
// verify : AOJ2045
vector<P> pCL(C c, L l) {
    vector<P> res;
    P center = proj(l, c.p);
    double d = abs(center - c.p);
    double tt = c.r * c.r - d * d;
    if(tt < 0 && tt > -EPS) tt = 0;
    if(tt < 0) return res;
    double t = sqrt(tt);
    P vect = vec(l);
    vect /= abs(vect);
    res.push_back(center - vect * t);
    if (t > EPS) {
        res.push_back(center + vect * t);
    }
    return res;
}

// 円と線分の交点
vector<P> pCS(C c, L s) {
    vector<P> ret;
    vector<P> nret = pCL(c, s);
    for (int i = 0; i < nret.size(); i++) {
        if (iSP(s, nret[i])) ret.push_back(nret[i]);
    }
    return ret;
}

// 円と円の交点
// verify : AOJ1183
vector<P> pCC(C a, C b){
    vector<P> res;

    double l = abs(b.p - a.p);

    if(sign(l) == 0 && sign(a.r - b.r) == 0) assert(false); // 解が無限に存在する
    if(sign(l - abs(a.r - b.r)) < 0 || sign(l - (a.r + b.r)) > 0) return res; // 解が存在しない

    double th1 = arg(b.p - a.p);
    if(sign(l - abs(a.r - b.r)) == 0 || sign(l - (a.r + b.r)) == 0){
        res.push_back(a.p + polar(a.r, th1));
    }else {
        double th2 = acos( (a.r * a.r - b.r * b.r + l * l) / (2 * a.r * l) );
        res.push_back(a.p + polar(a.r, th1 - th2));
        res.push_back(a.p + polar(a.r, th1 + th2));
    }
    return res;
}

// 2点を通る半径rの円の中心
// verify : AOJ1132
vector<P> touching_circle2(P a, P b, double r){
    vector<P> res;

    double d = abs(b - a);
    if(d > 2 * r) return res;

    P mid = 0.5 * (a + b);
    P dir = polar(sqrt(r * r - d * d / 4), arg(b - a) + M_PI / 2);
    res.push_back(mid + dir);
    res.push_back(mid - dir);
    return res;
}

// 3点を通る円
C touching_circle3(P a, P b, P c){
    // ２つの垂直二等分線の交点が円の中心
    P mid_ab = (a + b) / 2.0;
    L bis_ab = {mid_ab, (mid_ab - a) * P(0.0, 1.0)};
    P mid_bc = (b + c) / 2.0;
    L bis_bc = {mid_bc, (mid_bc - b) * P(0.0, 1.0)};

    assert(!paralell(bis_ab, bis_bc)); 

    P center = pLL(bis_ab, bis_bc);
    return {center, abs(a - center)};
}

// 円と円の共通部分の面積を求める．
// ref: nya3j
double cc_area(C c1, C c2) {
    double d = abs(c1.p - c2.p);
    if (c1.r + c2.r < d + EPS) {
        return 0.0;
    } else if (d < abs(c1.r - c2.r) + EPS) {
        double r = min(c1.r, c2.r); // 元は c1.r >? c2.r だった．
        return r * r * M_PI;
    } else {
        double rc = (d*d + c1.r*c1.r - c2.r*c2.r) / (2*d);
        double theta = acos(rc / c1.r);
        double phi = acos((d - rc) / c2.r);
        return c1.r*c1.r*theta + c2.r*c2.r*phi - d*c1.r*sin(theta);
    }
}

// 円の接線 (中心から偏角thの点で接する接線)
// verified: AOJ 2201
L circle_tangent(const C& c, double th){
    P p0 = c.p + polar(c.r, th);
    P p1 = p0 + polar(1.0, th + M_PI / 2);
    return {p0, p1};
}

// 二つの円の共通接線 (cの中心から接点へのベクトルの偏角を返す)
// verified: AOJ 2201
// 参考: http://geom.web.fc2.com/geometry/circle-circle-tangent.html
vector<double> common_tangents(const C& c, const C& d){
    vector<double> res;
    P v = d.p - c.p;
    double l = abs(v); // 二円の中心間の距離
    double a = arg(v); // 二円の中心間の偏角
    if(sign(l - abs(c.r - d.r)) > 0){
        // 交わる or 外接 or 離れている
        // 二つの外側接線
        double a1 = acos((c.r - d.r) / l);
        res.push_back(a + a1);
        res.push_back(a - a1);
        if(sign(l - (c.r + d.r)) > 0){
            // 離れている
            // 二つの内側接線
            double a2 = acos((c.r + d.r) / l);
            res.push_back(a + a2);
            res.push_back(a - a2);
        }
    }
    if((sign(l - abs(c.r - d.r)) == 0 || sign(l - (c.r + d.r)) == 0) && sign(l) != 0){
        // 内接 or 外接
        // 一つの接線
        res.push_back(a);
    }
    return res;
}

// 1点を通る円の接線( pがcの外側にあることが前提条件 )
// verified : AOJ 2579
vector<L> tangents_through_point(const C& c, const P& p){
    vector<L> tangents;
    double d = abs(c.p - p);
    // d ^ 2 == r ^ 2 + e ^ 2
    double e = sqrt(d * d - c.r * c.r); // 点pと円の接点の距離
    // d * sin(th) = r
    double th = asin(c.r / d);
    P q1 = p + (c.p - p) * polar(1.0, +th) * e / d;
    P q2 = p + (c.p - p) * polar(1.0, -th) * e / d;
    tangents.push_back({p, q1});
    tangents.push_back({p, q2});
    return tangents;
}
// 三角形の内心
// verify : aoj 1301
P incenter(P p1, P p2, P p3){
    double a = abs(p2 - p3);
    double b = abs(p3 - p1);
    double c = abs(p1 - p2);
    return (a * p1 + b * p2 + c * p3) / (a + b + c);
}


P input(){
    double x, y;
    cin >> x >> y;
    return {x, y};
}
struct S{
    int cur, prev;
    double cost;
    bool operator < (const S& s) const {
        if(cost != s.cost) return cost > s.cost;
        return make_pair(cur, prev) < make_pair(s.cur, s.prev);
    }
    void print(){
        printf("%d -> %d : %f\n", prev, cur, cost);
    }
};
int main(){
    int N;
    int casenum = 0;
    while(cin >> N && N){
        P sp = input();
        P gp = input();
        vector<L> elec(N);
        REP(i, N) {
            P pa = input();
            P pb = input();
            elec[i] = {pa, pb};
        }

        vector<L> route;
        REP(i, N) {
            P v = vec(elec[i]) * P(0, 1);
            L l = {sp, sp + v};
            if(iLS(l, elec[i])) {
                route.push_back(l);
            }
        }
        priority_queue<S> que;
        int M = route.size();
        REP(i, N) {
            P v = vec(elec[i]) * P(0, 1);
            route.push_back({elec[i][0], elec[i][0] + v});
            route.push_back({elec[i][1], elec[i][1] + v});
        }
        REP(i, N) {
            P v = vec(elec[i]) * P(0, 1);
            L l = {gp, gp + v};
            if(iLS(l, elec[i])) {
                route.push_back(l);
            }
        }
        // REP(i, route.size()){
        //     cout << "route " << i << " " << route[i][0] << " " << route[i][1] << endl;
        // }
        bool adj[500][500] = {};
        P cpp[500][500] = {};
        REP(i, route.size()) REP(j, route.size()) {
            if(!paralell(route[i], route[j])){
                cpp[i][j] = pLL(route[i], route[j]);
                adj[i][j] = true;
            }
        }
        double res = DBL_MAX;
        double mind[500][500] = {};
        REP(i, route.size()) REP(j, route.size()) {
            mind[i][j] = DBL_MAX;
        }

        // [0, M) [M, M + 2 * N) [M + 2 * N, route.size())
        for(int i = 0; i < M; i++) {
            for(int j = M; j < route.size(); j++){
                if(adj[i][j]) {
                    // mind[j][i] = abs(sp - cpp[j][i]);
                    que.push({j, i, abs(sp - cpp[j][i])});
                }
                if(equalLL(route[i], route[j])){
                    assert(paralell(route[i], route[j]));
                    cpp[i][j] = cpp[j][i] = sp;
                    // mind[j][i] = 0;
                    que.push({j, i, 0.0});
                }
            }
        }

        while(!que.empty()){
            S s = que.top(); que.pop();
            // s.print();
            if(s.cur >= M + 2 * N) {
                res = min(res, s.cost + abs(gp - cpp[s.cur][s.prev]));
                continue;
            }
            if(mind[s.cur][s.prev] < s.cost) {
                continue;
            }
            for(int i = M; i < route.size(); i++) if(adj[i][s.cur]) {
                double ncost = s.cost + abs(cpp[s.cur][s.prev] - cpp[i][s.cur]);
                if(ncost < mind[i][s.cur]){
                    mind[i][s.cur] = ncost;
                    que.push({i, s.cur, ncost});
                }
            }
        }
        if(res < DBL_MAX) {
            printf("Case %d: %.5f\n", ++casenum, res);
        }else {
            printf("Case %d: Impossible\n", ++casenum);
        }

    }
    return 0;
}