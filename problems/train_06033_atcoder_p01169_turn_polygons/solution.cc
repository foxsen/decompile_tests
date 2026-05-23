#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef complex<double> Point;
const double EPS = 1e-6;
double dot(Point a, Point b){
    return real(conj(a) * b);
}
double cross(Point a, Point b){
    return imag(conj(a) * b);
}
int ccw(Point a, Point b, Point c) {
    b -= a; c -= a;
    double len = abs(b) * abs(c); // 速さが気になるときは1にする
    if (cross(b, c) > +len * EPS)   return +1; // 反時計回り
    if (cross(b, c) < -len * EPS)   return -1; // 時計回り
    if (dot(b, c) < 0)     return +2; // c--a--b の順番で一直線上
    if (norm(b) < norm(c)) return -2; // a--b--c の順番で一直線上
    return 0;                         // 点が線分ab上にある
}

double angle(Point a, Point b){
    double res = arg(conj(a) * b);
    if(res < 0) res += 2 * M_PI;
    return res;
}

struct Line : public vector<Point> {
    Line(const Point& a, const Point& b) {
        push_back(a); push_back(b);
    }
    Point vector() const {
        return back() - front();
    }
};
struct Circle {
    Point p;
    double r;
    Circle() {}
    Circle(Point p, double r) : p(p), r(r) { }
};
bool intersectSP(Line s, Point p) {
    return ccw(s[0], s[1], p) == 0;
}

Point projection(Line l, Point p){
    double t = dot(p - l[0], l.vector()) / norm(l.vector());
    return l[0] + t * l.vector();
}

vector<Point> crosspointLC(const Line &l, const Circle &c) {
    vector<Point> res;
    Point center = projection(l, c.p);
    double d = abs(center - c.p);
    double tt = c.r * c.r - d * d;
    if(tt < 0 && tt > -EPS) tt = 0;
    if(tt < 0) return res;
    double t = sqrt(tt);
    Point vect = l.vector();
    vect /= abs(vect);
    res.push_back(center - vect * t);
    if (t > EPS) {
        res.push_back(center + vect * t);
    }
    return res;
}

vector<Point> crosspointSC(const Line &s, const Circle &c) {
    vector<Point> ret;
    vector<Point> nret = crosspointLC(s, c);
    for (int i = 0; i < nret.size(); i++) {
        if (intersectSP(s, nret[i])) ret.push_back(nret[i]);
    }
    return ret;
}

int main(){
    int M, N;
    while(cin >> M >> N && M){
        vector<Point> ps(M);
        vector<Point> qs(N);
        REP(i, M){
            double x, y;
            cin >> x >> y;
            ps[i] = Point(x, y);
        }
        REP(i, N){
            double x, y;
            cin >> x >> y;
            qs[i] = Point(x, y);
        }
        double cx, cy;
        cin >> cx >> cy;
        Point cp(cx, cy);
        double ans = 2.0 * M_PI;
        for(int i = 0; i < N; i++){
            Circle C(cp, abs(qs[i] - cp)); // qs[i]の軌道
            for(int j = 0; j < M; j++){
                Line s(ps[j], ps[(j == M - 1 ? 0 : j + 1)]);
                vector<Point> crosspv = crosspointSC(s, C);
                for(Point crossp : crosspv){
                    //cout << "Circle : " << C.p << " " << C.r << " cross with " << s[0] << " " << s[1] << " at " << crossp << endl;
                    ///cout << "angle : " << angle(qs[i] - cp, crossp - cp) << endl;
                    ans = min(ans, angle(qs[i] - cp, crossp - cp));
                }
            }
        }
        for(int i = 0; i < M; i++){
            Circle C(cp, abs(ps[i] - cp)); // ps[i]の軌道
            for(int j = 0; j < N; j++){
                Line s(qs[j], qs[(j == N - 1 ? 0 : j + 1)]);
                vector<Point> crosspv = crosspointSC(s, C);
                for(Point crossp : crosspv){
                    //cout << "Circle : " << C.p << " " << C.r << " cross with " << s[0] << " " << s[1] << " at " << crossp << endl;
                    //cout << "angle : " << angle(crossp - cp, ps[i] - cp) << endl;
                    ans = min(ans, angle(crossp - cp, ps[i] - cp));
                }
            }
        }
        printf("%.7f\n", ans / M_PI * 180.0);
    }
    return 0;
}