#include <bits/stdc++.h>
using namespace std;
int f[0x1000], c[0x1000];
map<pair<int, int>, int> gao;
map<pair<int, int>, int> ans;
int main() {
  int n, p, a, b, d;
  scanf("%d%d", &n, &p);
  for (int i = 0; i < p; ++i) {
    scanf("%d%d%d", &a, &b, &d);
    f[b] = a;
    c[a] = b;
    gao[pair<int, int>(a, b)] = d;
  }
  for (int i = 1; i <= n; ++i) {
    if (c[i] == 0 && f[i] != 0) {
      int j = i;
      int temp = 0x7fffffff;
      while (f[j] != 0) {
        temp = min(temp, gao[pair<int, int>(f[j], j)]);
        j = f[j];
      }
      ans[pair<int, int>(j, i)] = temp;
    }
  }
  printf("%d\n", ans.size());
  for (map<pair<int, int>, int>::iterator it = ans.begin(); it != ans.end();
       ++it)
    printf("%d %d %d\n", it->first.first, it->first.second, it->second);
}
