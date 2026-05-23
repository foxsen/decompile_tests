#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <unordered_map>
#include <iterator>
#include <assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

namespace geom{
#define X real()
#define Y imag()
#define at(i) ((*this)[i])
#define SELF (*this)
	enum {TRUE = 1, FALSE = 0, BORDER = -1};
	typedef int BOOL;
	typedef double R;
	const R INF = 1e12;
	R EPS = 1e-5;
	const R PI = 3.1415926535897932384626;
	inline int sig(const R &x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
	inline BOOL less(const R &x, const R &y) {return sig(x-y) ? x < y : BORDER;}
	typedef complex<R> P;
	inline R norm(const P &p){return p.X*p.X+p.Y*p.Y;}
	inline R inp(const P& a, const P& b){return (conj(a)*b).X;}
	inline R outp(const P& a, const P& b){return (conj(a)*b).Y;}
	inline P unit(const P& p){return p/abs(p);}
	inline P proj(const P &s, const P &t){return t*inp(s, t)/norm(t);}
	inline int ccw(const P &s, const P &t, const P &p, int adv=0){
		int res = sig(outp(t-s, p-s));
		if(res || !adv) return res;
		if(sig(inp(t-s, p-s)) < 0) return -2;	// p-s-t
		if(sig(inp(s-t, p-t)) < 0) return 2;	// s-t-p
		return 0;								// s-p-t
	}
	
	
	struct L : public vector<P>{	// line
		L(const P &p1, const P &p2){this->push_back(p1);this->push_back(p2);}
		L(){}
		inline P dir()const {return at(1) - at(0);}
		BOOL online(const P &p)const {return !sig(outp(p-at(0), dir()));}
	};
	struct S : public L{	// segment
		S(const P &p1, const P &p2):L(p1, p2){}
		inline S(){}
		inline BOOL online(const P &p)const {
			return !sig(outp(p-at(0), dir())) && inp(p-at(0), dir()) > -EPS && inp(p-at(1), -dir()) > -EPS;
			//if(!sig(norm(p - at(0))) || !sig(norm(p - at(1)))) return BORDER;
			//return !sig(abs(at(0)-p) + abs(at(1) - p) - abs(at(0) - at(1)));
		}
	};
	struct G : public vector<P>{
		G(size_type size=0):vector(size){}
		S edge(int i)const {return S(at(i), at(i+1 == size() ? 0 : i+1));}
		inline BOOL contains(const P &p)const {
			R sum = .0;
			REP(i, size()){
				if(S(at(i), at((i+1)%size())).online(p)) return BORDER;	// online
				sum += arg((at(i) - p) / (at((i+1)%size()) - p));
			}
			return !!sig(sum);
		}
	};

	inline P proj(const P &s, const L &t){return t[0] + proj(s-t[0], t[1]-t[0]);}
	inline P reflect(const P &s, const L &t){return (R)2.*proj(s, t) - s;}
	inline S reflect(const S &s, const L &t){return S(reflect(s[0], t), reflect(s[1], t));}
	BOOL intersect(const S &s, const S &t){
		const int p = ccw(t[0], t[1], s[0], 1) * ccw(t[0], t[1], s[1], 1);
		const int q = ccw(s[0], s[1], t[0], 1) * ccw(s[0], s[1], t[1], 1);
		return !(p>0||q>0);
	}
	BOOL intersect(const S &s, const L &l){
		return (sig(outp(l.dir(), s[0]-l[0])) * sig(outp(l.dir(), s[1]-l[0])) < 0);
	}
	
	inline P crosspoint(const L &l, const L &m){
		R A = outp(l.dir(), m.dir()), B = outp(l.dir(), l[1] - m[0]);
		if(!sig(abs(A)) && !sig(abs(B))) return m[0]; // same line
		if(abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!
		return m[0] + B / A * (m[1] - m[0]);
	}
	
	template<class T> void merge(vector<T> &s) {
		REP(i, s.size()) if (s[i][1] < s[i][0]) swap(s[i][0], s[i][1]);
		sort(ALL(s));
		REP(i, s.size())REP(j, i)if(!sig(outp(s[i].dir(), s[j].dir())) && intersect(s[i], s[j])) {
			s[j][1] = max(s[i][1], s[j][1]);
			s.erase(s.begin() + i--);
			break;
		}
	}
	struct Arrangement{
		struct AEdge{
			int u, v, t;
			R cost;
			AEdge(int u=0, int v=0, int t=0, R cost=0)
				:u(u), v(v), t(t), cost(cost){}
		};
		typedef vector<vector<AEdge>> AGraph;
		vector<P> p;
		AGraph g;
		Arrangement(){}
		Arrangement(vector<S> &seg){
			merge(seg);
			int m = seg.size();
			REP(i, m){
				p.push_back(seg[i][0]);
				p.push_back(seg[i][1]);
				REP(j, i) if(sig(outp(seg[i].dir(), seg[j].dir())) && intersect(seg[i], seg[j]) == TRUE)
					p.push_back(crosspoint(seg[i], seg[j]));
			}
			sort(ALL(p)); UNIQUE(p);
			int n=p.size();
			g.resize(n);
			REP(i, m){
				S &s = seg[i];
				vector<pair<R, int>> ps;
				REP(j, n) if(s.online(p[j])) ps.emplace_back(norm(p[j] - s[0]), j);
				sort(ALL(ps));
				REP(j, (int)ps.size()-1){
					const int u=ps[j].second;
					const int v=ps[j+1].second;
					g[u].emplace_back(u, v, 0, abs(p[u] - p[v]));
					g[v].emplace_back(v, u, 0, abs(p[u] - p[v]));
				}
			}
		}
	};
#undef SELF
#undef at
}

using namespace geom;

int f = 0;
namespace std{
	bool operator<(const P &a, const P &b){return sig(a.X-b.X) ? a.X < b.X : a.Y+EPS < b.Y;}
	bool operator==(const P &a, const P &b){return abs(a-b) < EPS;}
	istream& operator>>(istream &is, P &p){R x,y;is>>x>>y;p=P(x, y);return is;}
}


int n;
R r;

R manhattan(const P &p, const P &q){
	return abs(p.X-q.X) + abs(p.Y-q.Y);
}

R manhattan(const S &s, const P &p){
	R r = min(manhattan(s[0], p), manhattan(s[1], p));
	L x(p, p+P(1, 0));
	L y(p, p+P(0, 1));
	if(sig(outp(s.dir(), x.dir())) && intersect(s, x) == TRUE) r = min(r, abs(crosspoint(x, s).X - p.X));
	if(sig(outp(s.dir(), y.dir())) && intersect(s, y) == TRUE) r = min(r, abs(crosspoint(y, s).Y - p.Y));
	return r;
}

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	int T = 0;
	while(cin >> n >> r, n){
		G g(n);
		vector<vector<P>> p(n, vector<P>(4));
		REP(i, n){
			cin >> g[i];
			p[i][0] = g[i] + P(r, 0);
			p[i][1] = g[i] + P(0, r);
			p[i][2] = g[i] + P(-r, 0);
			p[i][3] = g[i] + P(0, -r);
		}
		vector<S> s;
		REP(i, n)REP(j, 4){
			s.emplace_back(p[i][j], p[(i+1)%n][j]);
			s.emplace_back(p[i][j], p[i][(j+1)%4]);
		}
		Arrangement a(s);
		R ans = 0;
		vector<S> anss;
		REP(i, a.g.size())FOR(e, a.g[i])if(e->u < e->v){
			S s(a.p[e->u], a.p[e->v]);
			if(g.contains(s[0]) && [&](){
				REP(j, n) if(manhattan(g.edge(j), (s[0]+s[1])*(R).5) < r - EPS) return 0;
				return 1;
			}()) ans += abs(s.dir());
		}
		printf("%.10f\n", (double)ans);
	}
	return 0;
}