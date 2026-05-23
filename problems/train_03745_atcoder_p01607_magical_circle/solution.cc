#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
using namespace std;
const double EPS = 1e-10;
const double INF = 1e12;
const double PI = acos(-1);
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define X real()
#define Y imag()

typedef complex<double> P;
typedef vector<P> VP;
struct L : array<P, 2>{
    L(const P& a, const P& b){ at(0)=a; at(1)=b; }
    L(){}
};
struct C{
    P p;
    double r;
    C(const P& p, const double& r) : p(p), r(r) {}
    C(){}
};

namespace std{
    bool operator < (const P& a, const P& b){
        return !EQ(a.X,b.X) ? a.X<b.X : a.Y+EPS<b.Y;
    }
    bool operator == (const P& a, const P& b){
        return abs(a-b) < EPS;
    }
}

double dot(P a, P b){
    return (conj(a)*b).X;
}
double cross(P a, P b){
    return (conj(a)*b).Y;
}
int ccw(P a, P b, P c){
    b -= a;
    c -= a;
    if(cross(b,c) > EPS) return +1; //ccw
    if(cross(b,c) < -EPS) return -1; //cw
    if(dot(b,c) < -EPS) return +2; //c-a-b
    if(abs(c)-abs(b) > EPS) return -2; //a-b-c
    return 0; //a-c-b
}

P unit(const P &p){
    return p/abs(p);
}
P rotate(const P &p, double rad){
    return p *P(cos(rad), sin(rad));
}

bool intersectSP(const L& s, const P &p){
    return abs(cross(s[0]-p, s[1]-p))<EPS  && dot(s[0]-p, s[1]-p)<EPS;
}

P projection(const L& l, const P& p) {
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
}
double distanceLP(const L &l, const P &p) {
    return abs(cross(l[1]-l[0], p-l[0])) /abs(l[1]-l[0]);
}
double distanceSP(const L &s, const P &p) {
    if(dot(s[1]-s[0], p-s[0]) < EPS) return abs(p-s[0]);
    if(dot(s[0]-s[1], p-s[1]) < EPS) return abs(p-s[1]);
    return distanceLP(s, p);
}

VP crosspointCL(const C &c, const L &l){
    VP ret;
    P mid = projection(l, c.p);
    double d = distanceLP(l, c.p);
    if(EQ(d, c.r)){
        ret.push_back(mid);
    }else if(d < c.r){
        double len = sqrt(c.r*c.r -d*d);
        ret.push_back(mid +len*unit(l[1]-l[0]));
        ret.push_back(mid -len*unit(l[1]-l[0]));
    }
    return ret;
}
VP crosspointCS(const C &c, const L &s){
    VP ret;
    VP cp = crosspointCL(c,s);
    for(int i=0; i<(int)cp.size(); i++){
        if(intersectSP(s, cp[i])){
            ret.push_back(cp[i]);
        }
    }
    return ret;
}

int in_poly(const P &p, const VP &poly){
    int n = poly.size();
    int ret = -1;
    for(int i=0; i<n; i++){
        P a = poly[i]-p;
        P b = poly[(i+1)%n]-p;
        if(a.Y > b.Y) swap(a,b);
        if(intersectSP(L(a,b), P(0,0))) return 0;
        if(a.Y<=0 && b.Y>0 && cross(a,b)<0) ret = -ret;
    }
    return ret;
}
double getarea(const VP &poly){
    int n = poly.size();
    double ret = 0;
    for (int i=0; i<n; i++){ 
        ret += cross(poly[i], poly[(i+1)%n]);
    }
    return ret*0.5;
}

VP convex(VP v){
    VP ret;
    int n = v.size();
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        while((int)ret.size()>1 && cross(ret.back()-ret[ret.size()-2], v[i]-ret.back()) < EPS){
            ret.pop_back();
        }
        ret.push_back(v[i]);
    }
    int t = ret.size();
    for(int i=n-2; i>=0; i--){
        while((int)ret.size()>t && cross(ret.back()-ret[ret.size()-2], v[i]-ret.back()) < EPS){
            ret.pop_back();
        }
        ret.push_back(v[i]);
    }
    if((int)ret.size() > 1) ret.pop_back();
    return ret;
}

double commonarea_circle_convex(C c, VP poly){
    int n = poly.size();
    for(int i=0; i<n; i++) poly[i] -= c.p;
    c.p = P(0, 0);

    double mindist = INF;
    VP cp;
    for(int i=0; i<n; i++){
        L edge(poly[i], poly[(i+1)%n]);
        VP ret = crosspointCS(c, edge);
        cp.insert(cp.begin(), ret.begin(), ret.end());
        if(abs(poly[i]) < c.r) cp.push_back(poly[i]);
        mindist = min(mindist, distanceSP(edge, c.p));
    }
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    if(mindist +EPS > c.r && in_poly(c.p, poly) > 0){
        return PI *c.r *c.r;
    }

    double res = 0;
    VP v = convex(cp);
    int m = v.size();
    for(int i=0; i<m; i++){
        P curr = v[i];
        P next = v[(i+1)%m];
        if(EQ(abs(curr), c.r) && EQ(abs(next), c.r)
            && in_poly(c.r *unit(next -curr)*P(0,-1), poly) > 0){
            double theta = arg(next /curr);
            if(theta < 0) theta += 2*PI;
            res += c.r*c.r *theta /2;
        }else{
            res += cross(curr, next) /2;
        }
    }
    return res;
}


vector<VP> triangulate(VP poly){
    vector<VP> ret;
    int i=0;
    while((int)poly.size() >= 3){
        int n = poly.size();
        i = (i+1)%n;
        VP tri{poly[(i-1+n)%n], poly[i], poly[(i+1)%n]};
        if(ccw(tri[0], tri[1], tri[2]) != 1) continue;
        bool isear = true;
        for(int j=0; j<n; j++){
            if(j==(i-1+n)%n || j==i || j==(i+1)%n) continue;
            if(in_poly(poly[j], tri) >= 0){
                isear = false;
                break;
            }
        }
        if(isear){
            ret.push_back(tri);
            poly.erase(poly.begin() +i);
        }
    }
    return ret;
}

double commonarea_circle_poly(const C &c, const VP &poly){
    vector<VP> tri = triangulate(poly);
    double ret = 0;
    for(int i=0; i<(int)tri.size(); i++){
        ret += commonarea_circle_convex(c, tri[i]);
    }
    return ret;
}

int main(){
    int n,r;
    cin >> n >> r;
    VP p(n);
    for(int i=0; i<n; i++){
        double x,y;
        cin >> x >> y;
        p[i] = P(x, y);
    }

    vector<double> areacp(r+1, 0);
    for(int i=1; i<=r; i++){
        areacp[i] = commonarea_circle_poly(C(P(0, 0), i), p);
    }
    double ans = 0;
    for(int i=0; i<r; i++){
        if(i%2 == 0){
            ans += areacp[i+1] -areacp[i];
        }else{
            ans += PI*((i+1)*(i+1) -i*i) -(areacp[i+1] -areacp[i]);
        }
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}
