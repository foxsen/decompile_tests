#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=205;
int n,mrk[N],dep[N],ans;vector<int>E[N];queue<int>Q;
void dfs(int u,int c){
	mrk[u]=c;
	for(int v:E[u])
		if(!~mrk[v])dfs(v,c^1);
		else if(mrk[v]!=(c^1))puts("-1"),exit(0);
}
void bfs(int u){
	memset(dep,63,sizeof(dep));
	dep[u]=1;Q.push(u);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int v:E[u])
			if(dep[v]>dep[u]+1)
				dep[v]=dep[u]+1,Q.push(v);
	}
	for(int i=1;i<=n;++i)ans=max(ans,dep[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			int x;scanf("%1d",&x);
			if(x)E[i].push_back(j);
		}
	memset(mrk,-1,sizeof(mrk));
	dfs(1,0);
	for(int i=1;i<=n;++i)bfs(i);
	printf("%d\n",ans);
	return 0;
}
