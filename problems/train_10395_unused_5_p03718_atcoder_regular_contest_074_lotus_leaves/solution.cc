#include<bits/stdc++.h>
#define ll long long
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
using namespace std;

const int maxn=107,maxm=5000007;
const int inf=0x1fffffff;

int n,m,fi[maxm],la[maxm],ne[maxm],va[maxm],tot=1;
char a[maxn][maxn];

#define Leaf(x,y) (1+x*m+y-m)
#define LEAF(x,y) (1+n*m+x*m+y-m)
#define Row(x) (1+n*m+n*m+x)
#define Col(x) (1+n*m+n*m+n+x)
int N;
void add(int a,int b,int c){
	tot++;
	ne[tot]=fi[a];
	la[tot]=b;
	va[tot]=c;
	fi[a]=tot;
}
void Add(int a,int b,int c){
	add(a,b,c);
	add(b,a,0);
}
void Init(){
	scanf("%d%d",&n,&m);
	N=2+2*n*m+n+m;
	fo(i,1,n) scanf("%s",a[i]+1);
	fo(i,1,n)
		fo(j,1,m){
			if (a[i][j]=='.') continue;
			if (a[i][j]=='S') Add(1,Leaf(i,j),inf);
			if (a[i][j]=='T') Add(LEAF(i,j),N,inf);
			/*fo(k,1,n)
				if (i!=k && a[k][j]!='.')
					add(LEAF(i,j),Leaf(k,j),inf);
			fo(k,1,m)
				if (j!=k && a[i][k]!='.')
					add(LEAF(i,j),Leaf(i,k),inf);*/
			Add(LEAF(i,j),Row(i),inf);
			Add(LEAF(i,j),Col(j),inf);
			Add(Leaf(i,j),LEAF(i,j),(a[i][j]=='o'?1:inf));
		}
	fo(i,1,n) fo(j,1,m)
		if (a[i][j]!='.'){
			Add(Row(i),Leaf(i,j),inf);
			Add(Col(j),Leaf(i,j),inf);
		}
}

int Ans,Cnt[maxm],bz[maxm];
int gap(int v,int Flow){
	int Used=0;
	if (v==N) 
		return Flow;
	for(int k=fi[v];k;k=ne[k])
		if (va[k] && bz[la[k]]+1==bz[v]){
			int i=gap(la[k],min(Flow-Used,va[k]));
			va[k]-=i;
			va[k^1]+=i;
			Used+=i;
			if (Used==Flow || bz[1]==N) return Used;
		}
	if (!--Cnt[bz[v]]) bz[1]=N;
	Cnt[++bz[v]]++;
	return Used;
}
void Solve(){
	Cnt[0]=N;
	while (bz[1]<N && Ans<inf){
		Ans+=gap(1,inf);
	}
}

bool Vis[maxm];
void dfs(int v){
	if (Vis[v]) return;
	Vis[v]=true;
	for(int k=fi[v];k;k=ne[k])
		if (va[k])
			dfs(la[k]);
}
void Print(){
	dfs(1);
	if (Ans>=inf) printf("-1\n");
	else printf("%d\n",Ans);
}

int main(){
	Init();
	Solve();
	Print();
	return 0;
}