#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 * 4 + 100;
vector<int> vec[maxn];
queue<int> q;
int n, c[maxn], fa[maxn], maxe;
bool check[maxn];
void bfs() {
  check[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    int cnt = 0;
    for (auto nei : vec[cur])
      if (!check[nei]) {
        fa[nei] = cur;
        q.push(nei);
        check[nei] = 1;
        while (cnt == c[cur] || cnt == c[fa[cur]]) {
          cnt++;
          cnt %= maxe;
        }
        c[nei] = cnt++;
        cnt %= maxe;
      }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int f, g;
    cin >> f >> g;
    vec[f].push_back(g);
    vec[g].push_back(f);
  }
  maxe = 0;
  for (int i = 1; i <= n; i++) maxe = max(maxe, (int)vec[i].size() + 1);
  cout << maxe << endl;
  bfs();
  for (int i = 1; i <= n; i++) cout << c[i] + 1 << " ";
}
