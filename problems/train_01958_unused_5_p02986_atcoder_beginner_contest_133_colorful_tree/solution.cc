#include<bits/stdc++.h>
using namespace std;
const int M=100001;
int n,q,a,b,c,dd;
struct node{
	int to,cl,val;
};
vector<node>d[M];
int fa[M][18],deep[M];
struct Node{
	int id,x,y,fl;
};
vector<Node>Ask[M];
void dfs(int x,int la){
	fa[x][0]=la;
	deep[x]=deep[la]+1;
	for(int i=0;i<(int)d[x].size();i++){
		int y=d[x][i].to;
		if(y==la)continue;
		dfs(y,x);
	}
}
void Up(int &b,int step){
	for(int i=17;i>=0;i--)if(step&(1<<i))b=fa[b][i];
}
int LCA(int a,int b){
	if(deep[a]>deep[b])swap(a,b);
	Up(b,deep[b]-deep[a]);
	if(a==b)return a;
	for(int i=17;i>=0;i--)if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int Ans[M],C[M],sum,cnt[M];
void DFS(int x,int la){
	for(int i=0;i<(int)Ask[x].size();i++){
		Node y=Ask[x][i];
		Ans[y.id]+=(sum-C[y.x]+y.y*cnt[y.x])*y.fl;
	}
	for(int i=0;i<d[x].size();i++){
		node y=d[x][i];
		if(y.to==la)continue;
		sum+=y.val;
		C[y.cl]+=y.val;
		cnt[y.cl]++;
		DFS(y.to,x);
		cnt[y.cl]--;
		C[y.cl]-=y.val;
		sum-=y.val;
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		scanf("%d%d%d%d",&a,&b,&c,&dd);
		d[a].push_back((node)<%b,c,dd%>);
		d[b].push_back((node)<%a,c,dd%>);
	}
	dfs(1,0);
	for(int i=1;i<=17;i++)for(int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int i=1;i<=q;i++){
		scanf("%d%d%d%d",&a,&b,&c,&dd);
		int lca=LCA(c,dd);
		Ask[c].push_back((Node)<%i,a,b,1%>);
		Ask[dd].push_back((Node)<%i,a,b,1%>);
		Ask[lca].push_back((Node)<%i,a,b,-2%>);
	}
	DFS(1,0);
	for(int i=1;i<=q;i++)printf("%d\n",Ans[i]);
}