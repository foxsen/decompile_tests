// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

typedef db T;
const db eps = 1e-8;
int sgn(T x){return (x>eps)-(x<-eps);}
struct P{
    T x,y;
    P(){} P(T x,T y):x(x),y(y){}
    void read(){scanf("%lf%lf",&x,&y);}
    P operator - (const P&b) const {return P(x-b.x,y-b.y);}
    P operator + (const P&b) const {return P(x+b.x,y+b.y);}
    T operator * (const P&b) const {return x*b.x+y*b.y;}
    P operator * (const T&k) const {return P(x*k,y*k);}
    P operator / (const T&k) const {return P(x/k,y/k);}
    T operator ^ (const P&b) const {return x*b.y-y*b.x;}
    bool operator < (const P&b) const {return sgn(x-b.x)?x<b.x:y<b.y;}
    bool operator == (const P&b) const{return !sgn(x-b.x)&&!sgn(y-b.y);}
    P rot90() {return P(-y,x);}
};
T norm(P x){return x*x;}
T abs(P x){return sqrt(x*x);}
struct C{
    P o;T r;
    void read(){o.read();scanf("%lf",&r);}
};

vector<P> tanCP(C c,P p){
    db x = norm(p - c.o) , d = x - c.r * c.r;
    vector<P> res;
    if(sgn(d) < 0) return res;
    d = max(d,0.);
    P mid = c.o + (p - c.o) * (c.r * c.r / x) ,
      del = ((p-c.o)*(c.r*sqrt(d)/x)).rot90();
    return {mid - del ,mid + del}; // counter-clockwise
}

vector<pair<P,P> > tanCC(C c1,C c2){
    vector<pair<P,P> > res;
    // extan
    if(!sgn(c1.r-c2.r)){
        P dir = c2.o-c1.o;
        dir = (dir*(c1.r/abs(dir))).rot90();
        res.pb({c1.o+dir,c2.o+dir});
        res.pb({c1.o-dir,c2.o-dir});
    } else {
        P p = (c2.o * c1.r - c1.o * c2.r) / (c1.r - c2.r);
        vector<P> ps = tanCP(c1 , p) , qs = tanCP(c2 , p);
        rep(i,0,min(sz(ps),sz(qs))) res.pb({ps[i],qs[i]});
    }
    // intan
    P p = (c1.o * c2.r + c2.o * c1.r) / (c1.r + c2.r);
    vector<P> ps = tanCP(c1 , p) , qs = tanCP(c2 , p);
    rep(i,0,min(sz(ps),sz(qs))) res.pb({ps[i],qs[i]});
    return res;
}

int main(){
    C o1,o2;
    o1.read();
    o2.read();
    vector<pair<P,P> > res = tanCC(o1 , o2);
    sort(all(res));
    res.erase(unique(all(res)),res.end());
    for(auto e : res) printf("%.10f %.10f\n",e.fi.x,e.fi.y);
    return 0;
}