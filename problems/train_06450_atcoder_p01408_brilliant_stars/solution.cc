#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int,long long> P;

const long long mod=1000000009;

vector<int> G[100100];
bool used[100100];
int N,M;

int dis[100100];
int base[100100];
int bfs(int v){
	queue<int> que;
	dis[v]=0;
	base[v]=v;
	que.push(v);
	int res=v;
	int cnt=0;
	while(!que.empty()){
		int cur=que.front();
		que.pop();
		cnt++;
		for(int i=0;i<G[cur].size();i++){
			int u=G[cur][i];
			if(used[u]) continue;
			if(base[u]==v&&dis[u]<=dis[cur]+1) continue;
			dis[u]=dis[cur]+1;
			base[u]=v;
			que.push(u);
			if(dis[u]==2){
				res=cur;
			}
		}
	}
	if(cnt==1) return -1;
	return res;
}

P solve(int v){
	int root=bfs(v);
//	printf("solve %d root=%d\n",v,root);
	if(root==-1){
		used[v]=true;
//		printf("end solve %d :1 1\n",v);
		return P(1,1);
	}
	used[root]=true;
	for(int i=0;i<G[root].size();i++){
		if(used[G[root][i]]) continue;
		base[G[root][i]]=-1;
	}
	int num=0;
	long long ways=1;
	for(int i=0;i<G[root].size();i++){
		if(used[G[root][i]]) continue;
		P p=solve(G[root][i]);
		num+=p.first;
		ways*=p.second;
		ways%=mod;
	}
	if(num==1){
		ways++;
		ways%=mod;
	}
//	printf("end solve %d: %d %d\n",v,num,ways);
	return P(num,ways);
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++){
		base[i]=-1;
	}
	int num=0;
	long long ways=1;
	for(int i=0;i<N;i++){
		if(used[i]==false){
			P p=solve(i);
			num+=p.first;
			ways=(ways*p.second)%mod;
		}
	}
	printf("%d\n%lld\n",num,ways);
	return 0;
}