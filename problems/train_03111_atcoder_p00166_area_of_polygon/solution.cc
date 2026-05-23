#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>
#include<stack>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<string> vstring;
typedef vector<pint> vpint;
typedef stringstream SS;

template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

#define rep(i,n) for(int i=0;i<(n);++i)
#define repn(i,m,n) for(int i=(m);i<(n);++i)
#define repd(i,n) for(int i=(n)-1;i>=0;--i)
#define repnd(i,m,n) for(int i=(n)-1;i>=(m);--i)
#define rep0(i,n) for(i=0;i<(n);++i)
#define repn0(i,m,n) for(i=(m);i<(n);++i)
#define repd0(i,n) for(i=(n)-1;i>=0;--i)
#define repnd0(i,m,n) for(i=(n)-1;i>=(m);--i)
#define repc(i,n) for(int i=0;i<=(n);++i)
#define repcn(i,m,n) for(int i=(m);i<=(n);++i)
#define repcd(i,n) for(int i=(n);i>=0;--i)
#define repcnd(i,m,n) for(int i=(n);i>=(m);--i)
#define repc0(i,n) for(i=0;i<=(n);++i)
#define repcn0(i,m,n) for(i=(m);i<=(n);++i)
#define repcd0(i,n) for(i=(n);i>=0;--i)
#define repcnd0(i,m,n) for(i=(n);i>=(m);--i)
#define all(n) n.begin(),n.end()
#define sz(n) ((int)(n).size())
#define IL for(;;)
#define MP make_pair
#define PB push_back
#define X second
#define Y first
#define p_queue(n) priority_queue<n,vector<n>,greater<n> >
#define PUTLINE cout<<"LINE:"<<__LINE__<<endl;

const int INF = 2147483647/3;
const double EPS = 1e-10;
const double PI = acos(-1.0);

const int dx[]={1,-1,0,0,1,1,-1,-1,0};
const int dy[]={0,0,1,-1,1,-1,1,-1,0};

int sig(double r) { return r < -EPS ? -1 : r > EPS ? 1 : 0; }

int main() {
	int m, n;
	int v1[400], v2[400];
	double m1, m2;
	IL {
		cin >> m;
		if (m == 0) break;
		rep (i, m - 1) cin >> v1[i];
		cin >> n;
		rep (i, n - 1) cin >> v2[i];
		m1 = m2 = 0;
		rep (i, m - 1) m1 += sin(v1[i] * PI / 180);
		rep (i, n - 1) m2 += sin(v2[i] * PI / 180);
		int th1, th2;
		th1 = th2 = 360;
		rep (i, m - 1) th1 -= v1[i];
		m1 += sin(th1 * PI / 180);
		rep (i, n - 1) th2 -= v2[i];
		m2 += sin(th2 * PI / 180);
		//cout << m1 << " " << m2 << endl;
		if (sig(m1 - m2) > 0) cout << 1 << endl;
		if (sig(m1 - m2) < 0) cout << 2 << endl;
		if (sig(m1 - m2) == 0) cout << 0 << endl;
	}
	return 0;
}