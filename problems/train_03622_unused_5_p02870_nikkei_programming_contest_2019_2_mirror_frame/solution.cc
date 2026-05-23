#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int N=1505;
const int mo=998244353;
int a[N][N],n,ans;
int deg[N],vis[N];
int S1,S2,S3,GG;
vector<int> e[N];
char s[N];
void dfs(int x){
	++S3;
	S1^=deg[x];
	S2+=e[x].size();
	vis[x]=1;
	For(i,0,e[x].size()-1)
		if (!vis[e[x][i]])
			dfs(e[x][i]);
}
int main(){
	scanf("%d",&n);
	For(i,0,n) For(j,0,n) a[i][j]=-1;
	For(i,1,n-1){
		scanf("%s",s+1);
		For(j,1,n-1){
			int c=-1;
			int v1=abs(i-j),v2=n-abs(n-i-j);
			if (v1>v2) swap(v1,v2);
			if (s[j]=='x') c=0;
			if (s[j]=='o') c=1;
			if (c!=-1&&a[v1][v2]!=-1&&c!=a[v1][v2]) GG=1;
			if (c!=-1) a[v1][v2]=c;
		}
	}
	if (GG)
		return puts("0"),0;
	For(i,1,n-1) For(j,1,n-1){
		int v1=i-j,v2=i+j;
		if (v1>=0&&v2<=n){
			//printf("%d %d\n",i,j);
			if (a[v1][v2]==-1){
				e[v1].PB(v2);
				e[v2].PB(v1);
				//printf("edge %d %d\n",v1,v2); 
			}
			else if (a[v1][v2]==1)
				deg[v1]^=1,deg[v2]^=1;
		}
	}
	int ans=1;
	For(i,0,n) if (!vis[i]){
		S1=S2=S3=0; dfs(i); S2/=2;
		int cnt=(i&1?(n+1)/2:n/2+1);
		if (cnt&1){
			if (S1) return puts("0"),0;
			S2-=S3-1;
		}
		For(j,1,S2)
			ans=2ll*ans%mo;
	}
	printf("%d",ans);
}