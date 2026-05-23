#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define rep(i,x) for(int i=0;i<x;i++)
typedef complex<double> pt;
typedef pair<pt,pt> L;
typedef vector<P> poly;
const double EPS = 1e-9;
#define x real()
#define y imag()
bool eq(double a,double b){ return -EPS<a-b&&a-b<EPS; }
double dot(pt a,pt b){
	return (conj(a)*b).x;
}
double cross(pt a,pt b){
	return (conj(a)*b).y;
}
bool on_segment(pair<pt,pt> a,pt p){
  return eq(abs(a.first-a.second)-abs(a.first-p)-abs(a.second-p),0);
}
bool contain_point(vector<pt>ps,pt p){
	double sum = 0;
	//arg no sum wo keisan
	for(int i=0;i<ps.size();i++){
		if(on_segment(mp(ps[i],ps[ (i+1)%ps.size() ]),p)) return 1;
		sum += arg( (ps[ (i+1)%ps.size() ]-p) / (ps[i]-p) );
	}
	return (abs(sum) > 1);
}

bool LCMP(const pt& a,const pt& b){
	if(eq(a.x,b.x)) return a.y < b.y;
	else return a.x < b.x;
}
int ccw(pt a,pt b,pt c){
	b -= a; c -= a;
	if(cross(b,c) > EPS) return 1; // counter clockwise
	if(cross(b,c) < -EPS) return -1; // clockwise
	if(dot(b,c) < -EPS) return 2; //c-a-b
	if(norm(b) < norm(c)) return -2; //a-b-c
	return 0; //a-c-b
}
pt crossPoint(pt a,pt b,pt c,pt d){
	double A = cross(b-a,d-c);
	double B = cross(b-a,b-c);
	if( fabs(A) < EPS && fabs(B) < EPS ) return c;
	else if(fabs(A) >= EPS ) return c+B/A*(d-c);
	else pt(1e9,1e9);
}
bool contain_segment(vector<pt>ps,pt p,pt q){
        vector<pt> qs;
      //  if(p == pt(1,2) && q == pt(0,0)) cout << "J" << endl;
        qs.pb(p); qs.pb(q);
    	for(int i=0;i<ps.size();i++){
    		//on-segment
    		if(ccw(p,q,ps[i]) == 0) qs.pb(ps[i]);
    	}
        for(int i=0;i<ps.size();i++){
        	pt r = crossPoint(p,q,ps[i],ps[(i+1)%ps.size()]);
        	if(r.x > 1e8) continue;
        	if(ccw(p,q,r) == 0) qs.pb(r);
        }
        sort(qs.begin(),qs.end(),LCMP);
        for(int i=1;i<qs.size();i++){
            pt r = (qs[i] + qs[i-1]) / 2.0;
            if(!contain_point(ps, r)) return 0;
        }
        return 1;
}
int n;
vector<pt>f;
ll ok[45];
int ans = 40;
void dfs(int v,int num,ll state){
	if(state == (1LL<<n)-1){
		ans = min(ans,num); return;
	}
	if(v == n) return;
	if(ans <= num || num >= 10) return;
	dfs(v+1,num,state);
	dfs(v+1,num+1,state|ok[v]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	    double X,Y;
		scanf("%lf%lf",&X,&Y);
		f.pb(pt(X,Y));
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) ok[i] ^= (1LL<<j);
			else{
				if(contain_segment(f,f[i],f[j])){
					ok[i] ^=  (1LL<<j);
				}
			}
		}
		//cout << ok[i] << endl;
	}//return 0;
	dfs(0,0,0);
	cout << ans << endl;
}