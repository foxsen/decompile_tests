#include <bits/stdc++.h>
using namespace std;
int n, m, k, s, ipt1, ipt2, clst[100002][102], sum;
vector<int> a[102], adj[100002], ans;
struct data {
  int l, d;
} t1;
queue<data> q;
void bfs(int g) {
  for (int i = 0; i < a[g].size(); i++) {
    q.push({a[g][i], 0});
    clst[a[g][i]][g] = 0;
  }
  while (!q.empty()) {
    t1 = q.front();
    q.pop();
    for (int i = 0; i < adj[t1.l].size(); i++) {
      if (clst[adj[t1.l][i]][g] == -1) {
        q.push({adj[t1.l][i], t1.d + 1});
        clst[adj[t1.l][i]][g] = t1.d + 1;
      }
    }
  }
  return;
}
int main() {
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= n; i++) {
    cin >> ipt1;
    a[ipt1].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> ipt1 >> ipt2;
    adj[ipt1].push_back(ipt2);
    adj[ipt2].push_back(ipt1);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++) clst[i][j] = -1;
  for (int i = 1; i <= k; i++) {
    bfs(i);
  }
  for (int i = 1; i <= n; i++) {
    sort(clst[i] + 1, clst[i] + 1 + k);
    sum = 0;
    for (int j = 1; j <= s; j++) sum += clst[i][j];
    cout << sum << " ";
  }
  cout << endl;
}
