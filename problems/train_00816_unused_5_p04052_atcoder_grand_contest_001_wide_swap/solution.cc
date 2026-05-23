#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,a[1000005];
vector<int>v[1000005];
map<int,int>mp;
void dfs(int x)
{
	for(int i=0;i<v[x].size();i++)
    	dfs(v[x][i]);
    cnt++;
	a[x]=cnt;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(i>k)
			mp.erase(a[i-k]);
		v[(mp.upper_bound(a[i]))->second].push_back(i);
		mp[a[i]]=i;
	}
	dfs(0);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<endl;

	return 0;
}