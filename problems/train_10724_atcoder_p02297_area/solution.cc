#include <iostream>
#include <cmath>
#include <complex>
#include <tuple>
#include <vector>
using namespace std;

using vec = complex<double>;
using line = pair<vec,vec>;
using polygon = vector<vec>;
const double eps = 0.0000001;

double inner_product(vec u,vec v){
    return real(u*conj(v));
}
double cross_product(vec u,vec v){
    return imag(conj(u)*v);
}

vec projection(line l,vec p){//p???l???????°???±
    vec s=l.first, t=l.second;
    double k = inner_product(t-s,p-s)/inner_product(t-s,t-s);
    return (1.0-k)*s+k*t;
}

vec reflection(line l,vec p){
    return 2.0*projection(l,p)-p;
}

int ccw(vec& a, vec& b, vec& c){
    vec ab = b-a, ac = c-a;
    double o = cross_product(ab,ac);
    if(o>0) return 1; //CCW
    if(o<0) return -1; //CW
    if(inner_product(ab,ac)<0){
        return 2; //C-A-B
    }else{
        if(inner_product(ab,ab)<inner_product(ac,ac)){
            return -2; //A-B-C
        }else{
            return 0; //A-C-B
        }
    }
}

bool isIntersect(line l0, line l1){
    int s = ccw(l0.first,l0.second,l1.first)*ccw(l0.first,l0.second,l1.second);
    if(s!=0&&s!=-1&&s!=-4) return false;
    s=ccw(l1.first,l1.second,l0.first)*ccw(l1.first,l1.second,l0.second);
    if(s!=0&&s!=-1&&s!=-4) return false;
    else return true;
}

vec interSection(line l0, line l1){
    vec s0, t0, s1, t1;
    tie(s0,t0)=l0; tie(s1,t1)=l1;
    double k = cross_product(t1-s1,s1-s0)/cross_product(t1-s1,t0-s0);
    return s0+(t0-s0)*k;
}

double segLength(line l){
    return abs(l.first-l.second);
}

double distLine2point(line l, vec p){
    return abs(cross_product(l.second-l.first,p-l.first))/abs(l.second-l.first);
}

double distSeg2Point(line l, vec p){
    vec x = projection(l,p);
    double L = segLength(l);
    if(abs(x-l.first)<L&&abs(x-l.second)<L){
        return abs(x-p);
    }else{
        return min(abs(l.first-p),abs(l.second-p));
    }
}

double distSeg2Seg(line l1, line l2){
    if(isIntersect(l1,l2)) return 0;
    double ret = 1e20;
    ret = min(ret,distSeg2Point(l1,l2.first));
    ret = min(ret,distSeg2Point(l1,l2.second));
    swap(l1,l2);
    ret = min(ret,distSeg2Point(l1,l2.first));
    ret = min(ret,distSeg2Point(l1,l2.second));
    return ret;
}

double area(polygon& g){
    double S=0;
    int n=g.size();
    for(int i=0;i<n;i++){
        S+=cross_product(g[i],g[(i+1)%n]);
    }
    S/=2;
    return S;
}

//???????????§???????????????


int main(){
    int n;
    cin >> n;
    polygon g;
    while(n--){
        int x,y;
        cin>>x>>y;
        g.emplace_back(x,y);
    }
    g.push_back(g.front());
    cout.precision(1);
    cout << fixed;
    cout << area(g) << endl;
    return 0;
}