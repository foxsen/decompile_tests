#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double EPS = 1e-8, INF = 1e12, PI = acos(-1.0);
typedef complex<double> P;
namespace std{
	bool operator<(const P& a, const P& b){
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}
inline double cross(const P& a, const P& b){ return imag(conj(a)*b); }
inline double dot(const P& a, const P& b){ return real(conj(a)*b); }
struct L : public vector<P>{
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};
typedef vector<P> G;
inline int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if(cross(b, c) > EPS)   return +1;		// counter clockwise
	if(cross(b, c) <-EPS)   return -1;		// clockwise
	if(dot(b, c)   <-EPS)     return +2;		// c--a--b on line
	if(norm(b)+EPS < norm(c)) return -2;		// a--b--c on line
	return 0;
}
G isCL(const P &c, double r, const P &p1, const P &p2){
	double x = dot(p1 - c, p2 - p1);
	double y = norm(p2 - p1);
	double d = x * x - y * (norm(p1 - c) - r * r);
	if(d < -EPS) return G(0);
	if(d < 0) d = 0;
	P q1 = p1 - (p2 - p1) * (x / y);
	P q2 = (p2 - p1) * (sqrt(d) / y);
	G res; res.pb(q1 - q2); res.pb(q1 + q2);
	return res;
}
vector<P> tanCP(P c, double r, P p){
	double x = norm(p - c);
	double d = x - r * r;
	if(d < -EPS) return vector<P>(0);
	if(d < 0) d = 0;
	P q1 = (p - c) * r * r / x;
	P q2 = (p - c) * (-r * sqrt(d) / x) * P(0, 1);
	
	vector<P> res;
	res.pb(c + q1 - q2);
	res.pb(c + q1 + q2);
	return res;
}
vector<L> tanCC(P c1, double r1, P c2, double r2){
	vector<L> res;
	if(abs(r1 - r2) < EPS){
		P dir = c2 - c1;
		dir = dir * (r1 / abs(dir)) * P(0, 1);
		res.pb(L(c1 + dir, c2 + dir));
		res.pb(L(c1 - dir, c2 - dir));
	}
	else{
		P p = (c1 * (-r2) + c2 * r1) / (r1 - r2);
		G ps = tanCP(c1, r1, p), qs = tanCP(c2, r2, p);
		rep(i, min(ps.size(), qs.size())) res.pb(L(ps[i], qs[i]));
	}
	P p = (c1 * r2 + c2 * r1) / (r1 + r2);
	vector<P> ps = tanCP(c1, r1, p), qs = tanCP(c2, r2, p);
	rep(i, min(ps.size(), qs.size())) res.pb(L(ps[i], qs[i]));
	return res;
}

//??¨?????????????????????????????????????????£???????????°??????????????????
int n, x[16], y[16], r[16], dp[1 << 16];

int main(){
	cin >> n;
	rep(i, n) cin >> x[i] >> y[i] >> r[i];
	rep(i, 1 << n) dp[i] = inf;
	dp[0] = 0;
	rep(i, n) dp[1 | 1 << i] = 1;
	
	G g;
	rep(i, n) g.pb(P(x[i], y[i]));
	
	rep(i, n) rep(j, i){
		//???????????????????????£?????????????????? ????????????
		assert(abs(g[i] - g[j]) > r[i] + r[j] + EPS);
	}
	
	rep(i, n) rep(j, i){
		vector<L> ls = tanCC(g[i], r[i], g[j], r[j]);
		for(L l : ls){
			G c = isCL(g[0], r[0], l[0], l[1]);
			for(P cc : c){
				P p(INF, INF);
				int bit1 = 1, bit2 = 1;
				for(int k = 1; k < n; k++){
					G d = isCL(g[k], r[k], l[0], l[1]);
					if(d.empty()) continue;
					for(P pp : d) if(abs(cc - pp) < abs(cc - p)) p = pp;
				}
				for(int k = 1; k < n; k++){
					G d = isCL(g[k], r[k], l[0], l[1]);
					if(d.empty()) continue;
					if(ccw(cc, p, d[0]) == 2)   bit2 |= 1 << k;
					else                        bit1 |= 1 << k;
					
					#if 0
					bool flag = ccw(cc, p, d[0]) == 2; //???????????????????????????????????£????????????
					for(P dd : d){
						assert(flag == (ccw(cc, p, dd) == 2));
						assert(flag || !flag && (ccw(cc, p, dd) == 0 || (ccw(cc, p, dd) == -2)));
					}
					#endif
				}
				dp[bit1] = min(dp[bit1], 1);
				dp[bit2] = min(dp[bit2], 1);
			}
		}
	}
	rep(i, 1 << n){
		for(int j = i - 1; j; j = j - 1 & i) dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
		for(int j = i; j; j = j - 1 & i) dp[i ^ j] = min(dp[i ^ j], dp[i]);
	}
	cout << dp[(1 << n) - 1] << endl;
	
	return 0;
}