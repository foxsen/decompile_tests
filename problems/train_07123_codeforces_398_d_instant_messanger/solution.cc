#include <bits/stdc++.h>
using namespace std;
const int MAX = 50000 + 10;
int n, m, q;
int in[MAX], du[MAX], f[MAX];
set<int> ne[MAX];
int cmp(int a, int b) { return (du[a] != du[b]) ? (du[a] < du[b]) : (a < b); }
void add(int a, int b) {
  ++du[a];
  ++du[b];
  if (cmp(b, a)) swap(a, b);
  ne[a].insert(b);
  f[b] += in[a];
}
void del(int a, int b) {
  --du[a];
  --du[b];
  if (ne[a].find(b) == ne[a].end()) swap(a, b);
  ne[a].erase(b);
  f[b] -= in[a];
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  int o, i;
  scanf("%d", &o);
  for ((i) = (1); (i) <= (o); ++(i)) {
    int a;
    scanf("%d", &a);
    in[a] = 1;
  }
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
  }
  for ((i) = (1); (i) <= (q); ++(i)) {
    char Q[10];
    int a, b;
    scanf("%s", Q);
    if (Q[0] == 'A') {
      scanf("%d%d", &a, &b);
      add(a, b);
    } else if (Q[0] == 'D') {
      scanf("%d%d", &a, &b);
      del(a, b);
    } else if (Q[0] == 'O') {
      scanf("%d", &a);
      in[a] = 1;
      for (set<int>::iterator it = ne[a].begin(); it != ne[a].end(); ++it)
        f[*it]++;
    } else if (Q[0] == 'F') {
      scanf("%d", &a);
      in[a] = 0;
      for (set<int>::iterator it = ne[a].begin(); it != ne[a].end(); ++it)
        f[*it]--;
    } else {
      scanf("%d", &a);
      int ans = 0;
      for (set<int>::iterator it = ne[a].begin(); it != ne[a].end(); ++it)
        ans += in[*it];
      printf("%d\n", ans + f[a]);
    }
  }
  return 0;
}
