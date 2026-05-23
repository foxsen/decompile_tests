#include<bits/stdc++.h>
using namespace std;
int vis[200],m,ans=0;
double k[30000];
struct sc
{
    int x,y;
} s[200];
bool flag=true;
void update(int cnt)
{
    int sum=0;
    for(int i=0; i<cnt; i++)
        for(int j=i+1; j<cnt; j++)
            if(k[j]==k[i])sum++;
    ans=max(sum,ans);
    flag=false;
}
void dfs(int i,int cnt)
{
    while(vis[i]&&i<=m)i++;
    if(i==m+1)
    {
        update(cnt);
        return ;
    }
    vis[i]=1;
    for(int j=i+1; j<=m; j++)
    {
        if(vis[j])continue;
        int a=s[i].x-s[j].x,b=s[i].y-s[j].y;
        k[cnt]=(a==0?100000.0:1.0*b/a);
        vis[j]=1;
        dfs(0,cnt+1);
        vis[j]=0;
    }
    vis[i]=0;
}
int main()
{
    scanf("%d",&m);
    memset(vis,0,sizeof vis);
    for(int i=1; i<=m; i++)scanf("%d %d",&s[i].x,&s[i].y);
    vis[0]=1;
    dfs(0,0);
    cout<<ans<<endl;
}

