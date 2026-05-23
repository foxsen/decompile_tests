#include<bits/stdc++.h>

using namespace std;

const int N=4004;

struct node{int to,next;}num[N];

int cnt=1,n,m,u,v,ans,Cnt[N],st[N],ed[N],head[N],vis[N],sure[N];
vector<int> vec[N],pass[N]; 

void add(int x,int y){num[++cnt].to=y;num[cnt].next=head[x];head[x]=cnt;}

int dfs(int x,int fa,int aim,int id)
{
	if(x==aim) return 1;
	for(int i=head[x];i;i=num[i].next)
	    if(num[i].to!=fa)
	    {
	  	    Cnt[i/2]++;pass[i/2].push_back(id);
	  	    vec[id].push_back(i);
	  	    if (dfs(num[i].to,x,aim,id)==1) return 1;	
		    Cnt[i/2]--;pass[i/2].pop_back();vec[id].pop_back();
	    }
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&st[i],&ed[i]);
		dfs(st[i],-1,ed[i],i);
	}
	for(int i=1;i<n;i++) ans+=min(Cnt[i],2);
	printf("%d\n",ans);
	while (1==1)
	{
		int p=0,q;
		for(int i=1;i<n;i++)
		    if(Cnt[i]==1&&vis[i*2]!=vis[i*2+1]) {p=i;break;} 
		if(!p) for(int i=1;i<n;i++) if(Cnt[i]>=2) {p=i;break;}
	    if(!p) break;
		for(int i=0;i<pass[p].size();i++)
		    if(!sure[pass[p][i]]) {q=pass[p][i];break;}
		int x=st[q],y=ed[q];sure[q]=1;
		for(int i=0;i<vec[q].size();i++)
		{
			int t=vec[q][i];
			if(t/2==p)
			{
				if(vis[t])
				{
				   for(int j=0;j<vec[q].size();j++) vec[q][j]^=1;
				   swap(st[q],ed[q]);
				}
				for(int j=0;j<vec[q].size();j++)
				    Cnt[vec[q][j]/2]--,vis[vec[q][j]]=1;
				break;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d %d\n",st[i],ed[i]);
	return 0;
}