#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
using namespace std;
const double EPS = 1e-5;
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

bool intersectSS(const L& a, const L& b){
    return ( ccw(a[0],a[1],b[0]) *ccw(a[0],a[1],b[1]) <= 0 ) &&
        ( ccw(b[0],b[1],a[0]) *ccw(b[0],b[1],a[1]) <= 0 );
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

bool isParallel(const P &a, const P &b){
    return abs(cross(a,b)) < EPS;
}
bool isParallel(const L &a, const L &b){
    return isParallel(a[1]-a[0], b[1]-b[0]);
}

P crosspointLL(const L &l, const L &m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  return m[0] + B/A *(m[1]-m[0]);
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
vector<L> getTangentLine(const C &c, const P &p){
    vector<L> ret;
    P dir = p -c.p;
    if(c.r +EPS < abs(dir)){
        /*
        P a = c.p + c.r*unit(dir);
        VP cp = crosspointCL(C(c.p, abs(dir)), L(a, a+dir*P(0,1)));
        for(P cpp: cp){
            ret.push_back(L(p, c.p +c.r*unit(cpp-c.p)));
        }
        */
        double a = abs(dir);
        double b = sqrt(a*a -c.r*c.r);
        double psi = arg(p - c.p);
        double phi = PI - acos(b/a);
        ret.emplace_back(p, p + b *P(cos(psi+phi), sin(psi+phi)));
        ret.emplace_back(p, p + b *P(cos(psi-phi), sin(psi-phi)));
    }else if(abs(c.r -abs(dir)) < EPS){
        ret.push_back(L(p, p +dir*P(0, 1)));
    }
    return ret;
}

struct edge{
    int to, rev;
    int cap;
    double cost;
    edge(int to, int rev, int cap, double cost)
        :to(to),rev(rev),cap(cap),cost(cost){}
    edge(){}
};
 
double min_cost_flow(int s, int g, int f, vector<vector<edge> > &adj){
    int n = adj.size();
    double res = 0;
    while(f > 0){
        vector<int> prevv(n), preve(n);
        vector<double> mincost(n, INF);
        mincost[s] = 0;
        while(1){
            bool update = false;
            for(int i=0; i<n; i++){
                if(mincost[i] == INF) continue;
                for(int j=0; j<(int)adj[i].size(); j++){
                    edge &e = adj[i][j];
                    if(e.cap>0 && mincost[i] +e.cost +EPS < mincost[e.to]){
                        mincost[e.to] = mincost[i] +e.cost;
                        prevv[e.to] = i;
                        preve[e.to] = j;
                        update = true;
                    }
                }
            }
            if(!update) break;
        }
        if(mincost[g] == INF){
            return -1;
        }
         
        int d = f;
        for(int v=g; v!=s; v=prevv[v]){
            d = min(d, adj[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d*mincost[g];
        for(int v=g; v!=s; v=prevv[v]){
            edge &e = adj[prevv[v]][preve[v]];
            e.cap -= d;
            adj[v][e.rev].cap += d;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<C> c(2);
    for(int i=0; i<2; i++){
        double x,y,r;
        cin >> x >> y >> r;
        c[i] = C(P(x, y), r);
    }

    vector<VP> pos(2, VP(n));
    vector<vector<vector<L> > > tangent(2, vector<vector<L> >(n));
    for(int d=0; d<2; d++){
        for(int i=0; i<n; i++){
            double x,y;
            cin >> x >> y;
            pos[d][i] = P(x, y);
            vector<L> ret;
            for(int dd=0; dd<2; dd++){
                ret = getTangentLine(c[dd], pos[d][i]);
                tangent[d][i].insert(tangent[d][i].end(), ret.begin(), ret.end());
            }
        }
    }

    //1点経由でのred[i] ~blue[j]の最小距離
    vector<vector<double> > dist(n, vector<double>(n, INF));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            VP cand;
            cand.push_back((pos[0][i] +pos[1][j])/2.0);
            for(L t1: tangent[0][i]){
                for(L t2: tangent[1][j]){
                    if(!isParallel(t1, t2)){
                        cand.push_back(crosspointLL(t1, t2));
                    }
                }
            }
            for(P cp: cand){
                if(distanceSP(L(pos[0][i], cp), c[0].p) +EPS > c[0].r &&
                    distanceSP(L(pos[0][i], cp), c[1].p) +EPS > c[1].r &&
                    distanceSP(L(pos[1][j], cp), c[0].p) +EPS > c[0].r &&
                    distanceSP(L(pos[1][j], cp), c[1].p) +EPS > c[1].r){
                    dist[i][j] = min(dist[i][j], abs(pos[0][i] -cp) +abs(pos[1][j] -cp));
                }
            }
        }
    }

    vector<vector<edge> > adj(2*n +2);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j] == INF) continue;
            adj[i+2].emplace_back(j+2+n, adj[j+2+n].size(), 1, dist[i][j]);
            adj[j+2+n].emplace_back(i+2, adj[i+2].size()-1, 0, -dist[i][j]);
        }
        adj[0].emplace_back(i+2, adj[i+2].size(), 1, 0);
        adj[i+2].emplace_back(0, adj[0].size()-1, 0, 0);
        adj[i+2+n].emplace_back(1, adj[1].size(), 1, 0);
        adj[1].emplace_back(i+2+n, adj[i+2+n].size()-1, 0, 0);
    }

    double ans = min_cost_flow(0, 1, n, adj);
    if(ans == -1){
        cout << "Impossible" << endl;
    }else{
        cout << fixed << setprecision(10);
        cout << ans << endl;
    }
    return 0;
}
