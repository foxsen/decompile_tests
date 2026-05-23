#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007LL;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int c[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>c[i];
	}
	long long ans[n+5],memo[200005]={};
	ans[0]=1LL;
	memo[c[0]]=1LL;
	for (int i = 1; i < n; ++i)
	{
		ans[i]=ans[i-1];
		if (c[i]!=c[i-1])
		{
			ans[i]+=memo[c[i]];
		}
		ans[i]%=mod;
		memo[c[i]]=ans[i];
	}
	cout<<ans[n-1]<<endl;
	return 0;
}