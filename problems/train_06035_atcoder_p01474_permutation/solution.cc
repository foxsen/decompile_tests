#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long int64;

const int MAX_N = 2000 + 1;
const int64 MOD = (int64)(1e9 + 7);

int N, C, target, ord;

int parent[MAX_N+1];
vector<int> graph[MAX_N+1];

int V[MAX_N+1];
int S[MAX_N+1];
int64 T[MAX_N+1];

int64 dp[MAX_N+1][MAX_N+1];
bool visited[MAX_N + 1];
int64 comb[MAX_N+1][MAX_N+1];

void init(){
	scanf("%d%d%d%d", &N, &C, &target, &ord);
	ord = N - ord + 1;
	++N;
	parent[0] = -1;
	for(int i=0; i<C; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		parent[a] = b;
		graph[b].push_back(a);
	}

	for(int i=0; i<N; i++)if(parent[i] == 0){
		graph[0].push_back(i);
	}

	for(int i=0; i<=N; i++){
		comb[i][i] = comb[i][0] = 1;
		for(int j=1; j<i; j++){
			comb[i][j] = ( comb[i-1][j-1] + comb[i-1][j] ) % MOD;
		}
	}
}

void calc(int v){
	T[v] = S[v] = 1;
	for(int i=0; i<(int)graph[v].size(); ++i){
		const int u = graph[v][i];
		calc(u);
		S[v] += S[u];
	}

	int total = S[v] - 1;
	for(int i=0; i<(int)graph[v].size(); i++){
		const int u = graph[v][i];
		T[v] = T[v] * comb[total][S[u]] % MOD * T[u] % MOD;
		total -= S[u];
	}
}

int solve(){
	calc(0);
	if(S[0] != N){
		return 0;
	}

	const int dummy = N;
	S[dummy] = 0;
	parent[dummy] = target;

	int depth = 0;
	for(int v = target; v!=-1 ;V[depth++]=v, v=parent[v]);
	reverse(V, V+depth);
	V[depth] = dummy;

	for(int i=0; i<depth; i++){
		int cur = V[i], nxt = V[i+1], all = N - S[nxt];
		int64 sum = 0, prod = 1;
		int total = S[cur] - S[nxt] - 1;
		for(int j=0; j<(int)graph[cur].size(); j++){
			const int u = graph[cur][j];
			if(nxt != u){
				prod = prod * T[u] % MOD * comb[total][S[u]] % MOD;
				total -= S[u];
			}
		}
		if(i == 0){
			dp[0][0] = prod;
			continue;
		}
		for(int j=1; j<N; j++){
			sum = (sum + dp[i-1][j-1]) % MOD;
			int rem = all - j - 1, child = S[cur] - S[nxt] - 1;
			if(rem >= child && rem >= 0 && child >= 0){
				dp[i][j] = sum * comb[rem][child] % MOD * prod % MOD;
			}
		}
	}

	return (int)dp[depth-1][ord];
}

int main(){
	init();
	printf("%d\n", solve());

	return 0;
}