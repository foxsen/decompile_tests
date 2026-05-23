#include<bits/stdc++.h>
using namespace std;
struct nobe
{
    int v,a,b;
};
vector<nobe> gg[55];
int c[55],d[55];
long long f[55][3030];
int main()
{
    int n,m,s,i=1,j=0;
    scanf("%d%d%d",&n,&m,&s);
	s=min(s,2500);
    while(i<=m)
	{
		int u,v,a,b;
        scanf("%d%d%d%d",&u,&v,&a,&b);
        gg[u].push_back((nobe){v,a,b});
        gg[v].push_back((nobe){u,a,b});
        ++i;
    }
    i=1;
    while(i<=n)
    {
    	scanf("%d%d",&c[i],&d[i]);
    	++i;
    }
    memset(f,63,sizeof(f));
    f[1][s]=0;
    typedef tuple<long long,int,int> tt;
    priority_queue<tt,vector<tt>,greater<tt> > qu;
    qu.push(tt(0,1,s));
    while(!qu.empty())
	{
        long long t=get<0>(qu.top());
        int u=get<1>(qu.top()),w=get<2>(qu.top());
        qu.pop();
        if(f[u][w]>t) continue;
        i=0;
        while(i<gg[u].size())
		{
            int v=gg[u][i].v,a=gg[u][i].a,b=gg[u][i].b;
            if((w>=a)&&(f[v][w-a]>t+b))
			{
                f[v][w-a]=t+b;
                qu.push(tt(t+b,v,w-a));
            }
            ++i;
        }
        if(f[u][min(w+c[u],2500)]>t+d[u])
		{
            f[u][min(w+c[u],2500)]=t+d[u];
            qu.push(tt(t+d[u],u,min(w+c[u],2500)));
        }
    }
    i=2;
    while(i<=n)
	{
        long long ans=999999999999999999ll;
        j=0;
        while(j<=2500)
		{
            ans=min(ans,f[i][j]);
            ++j;
        }
        printf("%lld\n",ans);
		++i;
    }
    return 0;
}
/*
3 2 1
1 2 1 2
1 3 2 4
1 11
1 2
2 5
*/