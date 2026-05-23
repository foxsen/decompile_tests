#include <bits/stdc++.h>
using namespace std;
const int maxn = 1009;
int a[maxn], b[maxn];
int pos[2][maxn];
vector<pair<int, int> > V;
int fin(int id, int a) {
  return pos[id][a] == a ? a : pos[id][pos[id][a]] = fin(id, pos[id][a]);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) pos[0][i] = pos[1][i] = i;
  for (int i = 1, j; i <= n; i++) scanf("%d", &j), a[j] = i;
  for (int i = 1, j; i <= n; i++) scanf("%d", &j), b[j] = i;
  for (int i = 1; i <= n; i++) {
    int h = fin(0, a[i]), c = fin(1, b[i]);
    if (h == i && c == i) {
      continue;
    }
    V.push_back({h, i}), V.push_back({i, c});
    pos[0][i] = h;
    pos[1][i] = c;
  }
  printf("%d\n", (int)V.size() / 2);
  for (int i = 0; i < V.size(); i += 2) {
    printf("%d %d %d %d\n", V[i].first, V[i].second, V[i + 1].first,
           V[i + 1].second);
  }
}
