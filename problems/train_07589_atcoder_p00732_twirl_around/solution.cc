#include <cassert>// c
#include <ctime>
#include <iostream>// io
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>// container
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>// other
#include <complex>
#include <numeric>
#include <functional>
#include <random>
#include <regex>

using namespace std;
typedef long long ll;

#define ALL(c) (c).begin(),(c).end()
#define FOR(i,l,r) for(int i=(int)l;i<(int)r;++i)
#define REP(i,n) FOR(i,0,n)
#define FORr(i,l,r) for(int i=(int)r-1;i>=(int)l;--i)
#define REPr(i,n) FORr(i,0,n)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end())
//debug
#define DUMP(x)  cerr << #x << " = " << (x)
#define LINE()    cerr<< " (L" << __LINE__ << ")"

template<typename T,typename U> T pmod(T x,U M){return (x%M+M)%M;}


//output
template<typename T> ostream& operator << (ostream& os, const vector<T>& as){REP(i,as.size()){if(i!=0)os<<" "; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const vector<vector<T>>& as){REP(i,as.size()){if(i!=0)os<<endl; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const set<T>& ss){for(auto a:ss){if(a!=ss.begin())os<<" "; os<<a;}return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p){os<<p.first<<" "<<p.second;return os;}
template<typename K,typename V> ostream& operator << (ostream& os, const map<K,V>& m){bool isF=true;for(auto& p:m){if(!isF)os<<endl;os<<p;isF=false;}return os;}
template<typename T1> ostream& operator << (ostream& os, const tuple<T1>& t){os << get<0>(t);return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const tuple<T1,T2>& t){os << get<0>(t)<<" "<<get<1>(t);return os;}
template<typename T1,typename T2,typename T3> ostream& operator << (ostream& os, const tuple<T1,T2,T3>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6,T7>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t)<<" "<<get<6>(t);return os;}

// must template
typedef long double D;
const D INF = 1e12,EPS = 1e-10;

typedef complex<D> P;
#define X real()
#define Y imag()
istream& operator >> (istream& is,complex<D>& p){D x,y;is >> x >> y; p=P(x,y); return is;}

int sig(D a,D b=0){return a<b-EPS?-1:a>b+EPS?1:0;}
template<typename T> bool eq(const T& a,const T& b){return sig(abs(a-b))==0;}
bool compX (const P& a,const P& b){return !eq(a.X,b.X)?sig(a.X,b.X)<0:sig(a.Y,b.Y)<0;}
namespace std{
	bool operator <  (const P& a,const P& b){return compX(a,b);}
  	bool operator == (const P& a,const P& b){return eq(a,b);}
};
// a×b
D cross(const P& a,const P& b){return imag(conj(a)*b);}
// a・b
D dot(const P& a,const P& b) {return real(conj(a)*b);}
int ccw(const P& a,P b,P c){
    b -= a; c -= a;
    if (sig(cross(b,c)) > 0)   return +1;       // counter clockwise
    if (sig(cross(b,c)) < 0)   return -1;       // clockwise
    if (sig(dot(b,c)) < 0)     return +2;       // c--a--b on line
    if (sig(norm(b),norm(c))<0) return -2;       // a--b--c on line
    return 0; //a--c--b on line (c==b,c==a)
}
// //must template

//直線・線分
struct L : public vector<P> {
	P vec() const {return this->at(1)-this->at(0);}
	L(const P &a, const P &b){push_back(a); push_back(b);}
	L(){push_back(P());push_back(P());}
};
istream& operator >> (istream& is,L& l){P s,t;is >> s >> t;l=L(s,t);return is;}

bool isIntersectLS(const L &l, const L &s) {
	return sig(cross(l.vec(), s[0]-l[0])*       // s[0] is left of l
		cross(l.vec(), s[1]-l[0]))<=0; // s[1] is right of l
}
// verified by ACAC003 B
// http://judge.u-aizu.ac.jp/onlinejudge/creview.jsp?rid=899178&cid=ACAC003
bool isIntersectSS(const L &s, const L &t) {
	return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&
		ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;
}
bool isStrictIntersectSS(const L &s, const L &t) {
	return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) < 0 &&
		ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) < 0;
}
bool isIntersectSP(const L &s, const P &p) {
	return sig(abs(s[0]-p)+abs(s[1]-p),abs(s[1]-s[0])) <=0; // triangle inequality
}

// 直線へ射影した時の点
// verified by AOJLIB
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092212
P projection(const L &l, const P &p) {
	D t = dot(p-l[0],l.vec()) / norm(l.vec());
	return l[0] + t * l.vec();
}

D distanceLP(const L &l, const P &p) {return abs(p - projection(l, p));}

struct C {
	P o; D r;
	C(const P &o,D r) : o(o), r(r) { }
};

// verified by http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1088814
vector<P> intersectionLC(L l,C c){
	D d = distanceLP(l,c.o);
	vector <P> res;
 	if(sig(d-c.r)==0){
		res.push_back(projection(l,c.o));
	}else if(sig(d,c.r)<0){
		P m = projection(l,c.o),u = (l[1]-l[0])/abs(l[1]-l[0]);
	 	D t = sqrt(c.r*c.r - d*d);
		res.push_back( m + t * u);res.push_back( m - t * u);
	}
	return res;
}

// verified by http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1088814
// 注:ccwの折れ線判定にEPSをつけること
vector<P> intersectionSC(L l,C c){
	vector<P> ps=intersectionLC(l,c),res;
	REP(i,ps.size()){
		if(ccw(ps[i],l[0],l[1])==+2 || ccw(ps[i],l[1],l[0])==+2){
			res.push_back(ps[i]);
		}
	}
	return res;
}

//浮動小数点 pmod
D pfmod(D v,D M=2*M_PI){return fmod(fmod(v,M)+M,M);}

class Main{
	public:

	void run(){

		while(true){
			D l,r;cin >> l >> r;int N;cin >> N;if(N==0)break;
			r*=2*M_PI;
			
			vector<P> ps(N);REP(i,N) cin >> ps[i];
			vector<L> ls(N);REP(i,N) ls[i]=L(ps[i],ps[pmod(i+1,N)]);

			P a(0,0),b(0,l),c(0,0);
			bool aeqa=true;

			auto r_arg=[&](const P& x,const P&y)->D{
				D res=-(arg(x-c)-arg(y-c));
				return sig(res)>=0?res:res+2*M_PI;
			};
			while(sig(r)>0){
				vector<tuple<D,D,P>> cps;
				//rot a
				{
					C cir_a(c,abs(a-c));
					L ca(c,a),car(c,c+(a-c)*polar(1.0L,-1e-5L));
					REP(i,N)if(sig(abs(ps[i]-cir_a.o),cir_a.r)<=0)if(!eq(c,ps[i])){
						if(isIntersectSS(car,ls[pmod(i-1,N)]) || !isIntersectSP(ca,ps[i])){// つっかかれる
							cps.emplace_back(r_arg(ps[i],a),-abs(ps[i]-c),ps[i]);
						}
					}
					REP(i,N){
						vector<P> _cps=intersectionSC(ls[i],cir_a);
						REP(j,_cps.size()){
							// rot eps rs
							if(a ==_cps[j]){
								if(isStrictIntersectSS(car,ls[i]))cps.emplace_back(r_arg(_cps[j],a),-abs(_cps[j]-c),_cps[j]);
							}else{
								cps.emplace_back(r_arg(_cps[j],a),-abs(_cps[j]-c),_cps[j]);
							}
						}
					}
				}
				//rot b
				{
					C cir_b(c,abs(b-c));
					L cb(c,b),cbr(c,c+(b-c)*polar(1.0L,-1e-5L));
					REP(i,N)if(sig(abs(ps[i]-cir_b.o),cir_b.r)<=0)if(!eq(c,ps[i])){
						if(isIntersectSS(cbr,ls[pmod(i-1,N)]) || !isIntersectSP(cb,ps[i])){// つっかかれる
							cps.emplace_back(r_arg(ps[i],b),-abs(ps[i]-c),ps[i]);
						}
					}
					REP(i,N){
						vector<P> _cps=intersectionSC(ls[i],cir_b);
						REP(j,_cps.size()){
							// rot eps rs
							if(b ==_cps[j]){
								if(isStrictIntersectSS(cbr,ls[i]))cps.emplace_back(r_arg(_cps[j],b),-abs(_cps[j]-c),_cps[j]);
							}else{
								cps.emplace_back(r_arg(_cps[j],b),-abs(_cps[j]-c),_cps[j]);
							}
						}
					}
				}
				sort(ALL(cps));
				assert(cps.size()>0);
				D ar=get<0>(cps[0]);P cp=get<2>(cps[0]);
				
				// can't move
				if(sig(ar)<=0)break;

				//end
				if(sig(r,ar)<0)ar=r;

				//rotate
				P na=c + (a-c)*polar(1.0L,-ar),nb=c+(b-c)*polar(1.0L,-ar),nc=cp;
				a=na;b=nb;c=nc;
				r-=ar;
				bool rev=false;REP(i,ls.size())if((aeqa && isIntersectSP(ls[i],b)) || (!aeqa && isIntersectSP(ls[i],a)) )rev=true;
				if(rev){
					swap(a,b);aeqa=!aeqa;
				}
			}
			if(aeqa) cout << a.X <<" " << a.Y <<endl;
			else cout << b.X <<" " << b.Y << endl;
		}
	}
};
int main(){
	cerr <<fixed<<setprecision(20);	
	cout <<fixed<<setprecision(20);	
	ios::sync_with_stdio(false);
	Main().run();
	return 0;
}