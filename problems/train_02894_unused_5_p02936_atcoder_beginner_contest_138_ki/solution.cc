#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void dfs(vector<int> *to,int v, int p = -1){
	for(int u : to[v]){
		if(u == p) continue;
		ans[u] += ans[v];
		dfs(to,u,v);
	}
}
int main(int argc, char** argv){
	int n,q;
	cin >> n >> q;
	vector<int> to[n];
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		--a; --b;
		to[a].push_back(b); 
		to[b].push_back(a);
	}
	ans.resize(n);
	for(int i = 0; i < q; i++){
		int p, x;
		cin >> p >> x;
		--p;
		ans[p] += x;
	}
	dfs(to,0);
	for(int i = 0; i < n; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
