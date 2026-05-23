#include <bits/stdc++.h>
using namespace std;
int n, m, can[101][101], comp[101], tot;
void init(int k) {
  for (int i = 0; i <= n; i++) comp[i] = i;
  tot = n - k;
}
bool f(int i, int j) {
  for (int k = 0; k < m; k++)
    if (can[i][k] && can[j][k]) return true;
  return false;
}
int find(int i) { return i == comp[i] ? i : comp[i] = find(comp[i]); }
void join(int i, int j) {
  if (find(i) == find(j)) return;
  comp[find(i)] = find(j);
  tot--;
}
int main() {
  cin >> n >> m;
  int a, b, c = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    c += (a == 0);
    for (int j = 0; j < a; j++) {
      cin >> b;
      b--;
      can[i][b]++;
    }
  }
  init(c);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (f(i, j)) join(i, j);
    }
  }
  printf("%d\n", c < n ? tot - 1 + (c) : c);
}
