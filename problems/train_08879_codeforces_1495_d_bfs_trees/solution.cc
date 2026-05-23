#include<bits/stdc++.h>
#define cs const
#define pb push_back
using namespace std;

cs int Mod = 998244353;

int mul(int a, int b){ return 1ll * a * b % Mod; }
void Mul(int &a, int b) { a = mul(a, b); }

cs int N = 405;

int n, m, ans[N][N], fa[N];
vector<int> G[N];

int work(int S){
	static int d[N];
	queue<int> q; 
	memset(d, -1, sizeof d);
	q.push(S);
	int ans = 1; d[S] = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int v : G[x])
		if(d[v] == -1) {
			d[v] = d[x] + 1; 
			fa[v] = x; 
			int c = 0; 
			for(int z : G[v])
			if(d[z] == d[x]) 
			++ c; 
			Mul(ans, c);
			q.push(v);
		}
	} return ans;
}
int work(int S, int T){
	static int d1[N], d2[N], fa1[N], fa2[N];
	memset(d1, -1, sizeof(d1));
	memset(d2, -1, sizeof(d2));
	queue<int> q; 
	q.push(S);
	d1[S] = 0; 
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int v : G[x])
		if(d1[v] == -1) {
			d1[v] = d1[x] + 1; 
			fa1[v] = x; 
			q.push(v);
		}
	}
	d2[T] = 0; 
	q.push(T);	
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int v : G[x])
		if(d2[v] == -1) {
			d2[v] = d2[x] + 1; 
			fa2[v] = x; 
			q.push(v);
		}
	}
	static bool ex[N], o[N];
	memset(ex, 0, sizeof(ex));
	memset(o, 0, sizeof(o));
	for(int i = 1; i <= n; i++)
		if(d1[i] + d2[i] == d1[T]){
			if(ex[d1[i]]) 
				return 0; 
			ex[d1[i]] = true;
			o[i] = 1; 
		}
	for(int i = 0; i <= d1[T]; i++)
		if(!ex[i]) return 0;
	
	int ans = 1; 
	for(int i = 1; i <= n; i++)
	if(!o[i]){
		int c = 0; 
//		if(S == 5 && T == 6){
//		
//		cout << S << " " << T << " " << i << ' ' << d1[i] << " " << d2[i] <<endl;	
//		}
		for(int v : G[i])
		if(d1[v] == d1[i] - 1 && d2[v] == d2[i] - 1)
		++ c; 
//		if(S == 5 && T == 6){
//			cout << i << ' ' << c << endl;
//		}
		Mul(ans, c);
	} return ans;
	
}
int main(){
	#ifdef FSYo
	freopen("1.in", "r", stdin);
	#endif
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; i++){
		scanf("%d%d", &u, &v);
		G[u].pb(v), G[v].pb(u);
	}
	for(int i = 1; i <= n; i++)
		ans[i][i] = work(i); 
	for(int i = 1; i <= n; i++)
	for(int j = i + 1; j <= n; j++)
	ans[i][j] = ans[j][i] = work(i, j);
	for(int i = 1; i <= n; i++, puts(""))
	for(int j = 1; j <= n; j++)
	cout << ans[i][j] << " ";
	return 0;
}