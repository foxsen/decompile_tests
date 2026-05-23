#include <bits/stdc++.h>
const int N = 109;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
using namespace std;
int n, k, t;
bool g[N];
priority_queue<int> que;
vector<pair<int, int> > b[N];
void dfs(int nb, int w) {
  if (nb != n)
    ;
  else if (que.size() < t)
    que.push(w);
  else if (que.top() > w)
    que.pop(), que.push(w);
  if (nb == n) return;
  dfs(nb + 1, w);
  int sz = b[nb].size();
  for (int i = 0; i < sz; i++) {
    int ng = b[nb][i].first;
    if (!g[ng]) {
      g[ng] = 1;
      dfs(nb + 1, w + b[nb][i].second);
      g[ng] = 0;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &k, &t);
  for (int i = 0; i < k; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    b[x - 1].push_back(make_pair(y - 1, z));
  }
  dfs(0, 0);
  printf("%d\n", que.top());
  return 0;
}
