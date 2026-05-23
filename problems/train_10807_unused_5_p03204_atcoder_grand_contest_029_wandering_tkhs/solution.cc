#include<bits/stdc++.h>
using namespace std;
const int maxn=200000;
vector<int>eds[maxn],vv;
int n,x,y;
pair<int,int>go[maxn];
int ad[maxn],ans[maxn];
void dfs1(int v,int p,pair<int,int>ma)
{
    if(ma.second<v) ma.second=v;
    if(ma.second>ma.first) swap(ma.second,ma.first);
    go[v]=ma;
    for(int i=0;i<eds[v].size();i++)
    {
        int u=eds[v][i];
        if(u==p) continue;
        dfs1(u,v,ma);
    }
}
void dfs3(int v,int p,int cnt)
{
    cnt+=ad[v];
    ans[v]=cnt;
    for(int i=0;i<eds[v].size();i++)
    {
        int u=eds[v][i];
        if(u==p) continue;
        dfs3(u,v,cnt);
    }
}
void dfs2(int v,int p)
{
    vv.push_back(v);
    if(v==0) ad[0]++;
    else
    {
        int l=0;
        int r=vv.size()-1;
        while(r-l>1)
        {
            int m=l+r>>1,x=vv[m],f1=0;
            if(go[x].first!=x&&go[x].first==go[v].first
               ||go[x]==go[v]) f1=1;
            if(f1) r=m;
            else l=m;
        }
        ad[vv[r]]++;
    }
    for(int i=0;i<eds[v].size();i++)
    {
        int u=eds[v][i];
        if(u==p) continue;
        dfs2(u,v);
    }
    vv.pop_back();
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        x--;y--;
        eds[x].push_back(y);
        eds[y].push_back(x);
    }
    dfs1(0,-1,make_pair(-1,-1));
    dfs2(0,-1);
    dfs3(0,-1,0);
    for(int i=1;i<n;i++)
        printf(i==n-1?"%d\n":"%d ",ans[i]-1);
}
