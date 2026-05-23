#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <string>
#define SIZE 1002
#define INF 10000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll K;

struct edge{int to,cap,rev;};

vector<edge> G[SIZE];
bool used[SIZE];

//グラフ追加: from -> to (cap)
void add_edge(int from, int to, int cap){
	G[from].push_back((edge){to,cap,(int)G[to].size()});
	G[to].push_back((edge){from,0,(int)G[from].size()-1});
}

//パスを一本見つける
int dfs(int v, int t, int f){
	if(v==t)return f;
	used[v] = true;
	for(int i=0;i<G[v].size();i++){
		edge &e = G[v][i];
		if(!used[e.to] && e.cap>0){
			int d = dfs(e.to,t,min(f,e.cap));
			if(d>0){ //v -> G[v][i].toにd流す
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow = 0;
	for(;;){
		memset(used,0,sizeof(used));
		int f = dfs(s,t,INF);
		if(f==0)return flow;
		flow += f;
	}
}

int gcd(int a,int b){ //a>=b
	if(b==0)return a;
	return gcd(b,a%b);
}

bool imain()
{
	int m,n;
	int B[500];
	int R[500];
	scanf("%d %d",&m,&n);
	if(m==0&&n==0)return false;
	for(int i=0;i<m;i++){
		scanf("%d",&B[i]);
		add_edge(1000,i,1);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&R[i]);
		add_edge(i+500,1001,1);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(gcd(B[i],R[j])!=1){
				add_edge(i,500+j,1);
			}
		}
	}
	int ans = max_flow(1000,1001);
	printf("%d\n",ans);
	for(int i=0;i<m;i++)G[i].clear();
	for(int i=0;i<n;i++)G[i+500].clear();
	G[1000].clear();
	G[1001].clear();
	return true;
}

int main(){
	while(imain());
	return 0;
}

