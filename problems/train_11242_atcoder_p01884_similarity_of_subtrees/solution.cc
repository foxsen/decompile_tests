#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <stack>
#include <vector>
using namespace std;
 
 
const int mod=1e9+7;
const int maxn=1e6+10;
#define _int64 unsigned long long
 
map<_int64,_int64> mp;
vector<int> g[maxn];
 
_int64 d[maxn];


_int64 ans;

int n; 

 
void dfs(int u,int fa){
    d[u]=1;
    for(int i=0;i<g[u].size();++i)
	{
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u);
        d[u]+=d[v]*mod;
    }
    mp[d[u]]++;
}
 
 

int main()
{
	while(~scanf("%d",&n))
    {
    	
    	for(int i=0; i<=n; i++)
            g[i].clear();
        mp.clear();
        ans=0;
        for(int i=1;i<n;i++)
		{
            int u,v;
			scanf("%d%d",&u,&v);
            g[u].push_back(v);
			g[v].push_back(u);
        }
      
        dfs(1,0);
        for(map<_int64,_int64>::iterator it=mp.begin(); it!=mp.end(); it++)
            ans+=(_int64)it->second*(it->second-1)/2;
        cout<<ans<<endl;
    }
    return 0; 
}
