#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using ll=long long;
using R=long double;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

// Problem Specific Parameter:
const int inf=1<<19;
const int LOG=19;
int alpha[26][500010];
int nxt[19][500010];

bool query(int l,int r){
	rrep(i,LOG) if(nxt[i][l]<=r) l=nxt[i][l];
	return l==r;
}

int main(void){
	string s;
	cin >> s;
	const int n=s.size();

	rep(i,26)rep(j,n+1) alpha[i][j]=inf;
	rep(i,LOG)rep(j,n+1) nxt[i][j]=inf;

	rrep(i,n){
		const int c=s[i]-'a';
		alpha[c][i]=i+1;
		
		rep(k,c+1,26){
			if(alpha[k-1][i]<=n)
				alpha[k][i]=alpha[k-1][alpha[k-1][i]];
		}
		
		if(alpha[25][i]<=n) nxt[0][i]=alpha[25][alpha[25][i]];
		rep(j,LOG-1) if(nxt[j][i]<=n) nxt[j+1][i]=nxt[j][nxt[j][i]];
		
		rep(k,c){
			if(nxt[0][i]<=n)
				alpha[k][i]=alpha[k][nxt[0][i]];
		}

	}

	int q;
	cin >> q;

	rep(loop,q){
		int l,r;
		cin >> l >> r,l--;
		cout << (query(l,r)?"Yes":"No") << endl;
	}

	return 0;
}