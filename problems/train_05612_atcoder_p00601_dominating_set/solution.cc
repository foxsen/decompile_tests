#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <complex>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define iter(c) __typeof__((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

int solve(vi& g,int flg,int cur)
{
	int n=g.size();
	if(flg==(1<<n)-1)
		return 0;
	
	int res=n;
	repi(i,cur,n)
		res=min(res,1+solve(g,flg|g[i],i+1));
	return res;
}

int main()
{
	for(int n,m;scanf("%d%d",&n,&m),n|m;){
		vi g(n);
		rep(i,n)
			g[i]=1<<i;
		rep(i,m){
			int s,d; scanf("%d%d",&s,&d);
			g[s]|=1<<d;
			g[d]|=1<<s;
		}
		printf("%d\n",solve(g,0,0));
	}
	
	return 0;
}