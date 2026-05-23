#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int MX = 100500;

int sz[MX];
vector<pair<int,int>> e[MX];

void dfs(int u, int pr){
	sz[u] = 1;
	for(int i = 0; i < e[u].size(); i++){
		int v = e[u][i].first;
		if(v == pr) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

long long ans = 0;

void dfs2(int u, int pr){
	for(int i = 0; i < e[u].size(); i++){
		int v = e[u][i].first;
		if(v == pr) continue;
		long long t = e[u][i].second;
		t *= 2 * sz[v];
		ans += t;
		//cout << u << ' ' << t << endl;
		dfs2(v, u);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	int mid = (n + 1) / 2;
	dfs(0, 0);
	int u = 0;
	while(true){
		bool ok = false;
		for(int i = 0; i < e[u].size(); i++){
			int v = e[u][i].first;
			if(sz[u] < sz[v]) continue;
			if(sz[v] >= mid) {u = v; ok = true; break;}
		}
		if(!ok) break;
	}
	//cout << u << endl;
	dfs(u, u);
	dfs2(u, u);
	int r2 = 1e9;
	for(int i = 0; i < e[u].size(); i++)
		r2 = min(r2, e[u][i].second);
	for(int i = 0; i < e[u].size(); i++)
		if(sz[e[u][i].first] >= mid) r2 = e[u][i].second;
//	cout << ans << endl;
	cout << ans - r2 << endl;
	return 0;
}