#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)

typedef vector<int> vi;
typedef vector<vi> vvi;

void chmax(int& a,int b)
{
	a=max(a,b);
}

int main()
{
	for(int n,c;cin>>n>>c,n|c;){
		vi a(n),b(c);
		{
			int x;
			rep(i,n) rep(j,16) cin>>x,a[i]|=x<<j;
			rep(i,c) rep(j,16) cin>>x,b[i]|=x<<j;
		}
		
		vvi dp(n+1,vi(1<<16,-1));
		dp[0][0]=0;
		rep(i,n) rep(j,1<<16) if(dp[i][j]!=-1) rep(k,c)
			chmax(dp[i+1][(j|a[i])&~b[k]],dp[i][j]+__builtin_popcount((j|a[i])&b[k]));
		cout<<*max_element(begin(dp[n]),end(dp[n]))<<endl;
	}
	
	return 0;
}