#include <bits/stdc++.h>
using namespace std;
int max1 = INT_MIN;
long long cnt = 0;
long long cnt1 = 0;
bool DFSgraph(vector<int> l[], int v, vector<bool> &discovered,
              vector<int> &col) {
  discovered[v] = true;
  for (int u : l[v]) {
    if (discovered[u] == false) {
      col[u] = !col[v];
      if (DFSgraph(l, u, discovered, col) == false) return false;
    } else if (col[v] == col[u])
      return false;
  }
  return true;
}
bool bipat(vector<int> list[], int N) {
  vector<bool> discovered(N, false);
  vector<int> color(N, 0);
  color[0] = 0;
  for (int i = 0; i < N; i++) {
    if (discovered[i] == false)
      if (DFSgraph(list, i, discovered, color) == false) return false;
  }
  for (int i = 0; i < N; i++) {
    if (color[i] == 0)
      cnt++;
    else
      cnt1++;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> list[n + 1];
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    list[x - 1].push_back(y - 1);
    list[y - 1].push_back(x - 1);
  }
  bool m = bipat(list, n);
  cout << (cnt * cnt1 - n + 1);
  return 0;
}
