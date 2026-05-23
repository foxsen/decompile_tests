#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 13;
int n, ans, val[maxN][50 + 13];
vector<int> adj[maxN];
void dfs (int x, int par) {
    for (auto a : adj[x]) {
	if (a != par) {
	    dfs(a, x);
	    for (int i = 0; i <= 50; i++)
		val[x][i] += val[a][i];
	}
    }
    int cur = 0;
    for (int i = 0; i <= 50; i++) {
	//cout << x << " " << i << " " << val[x][i] << endl;
	if (val[x][i] >= 2)
	    cur = i + 1;
    }
    while (val[x][cur])
	cur++;
    ans = max(ans, cur);
    for (int i = 0; i < cur; i++)
	val[x][i] = 0;
    //cout << x << " " << cur << endl;
    val[x][cur] = 1;
}

int main () {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
	int a, b;
	cin >> a >> b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }

    dfs(1, 1);
    cout << ans << endl;
}
