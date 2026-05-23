#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int check[100010];
int main() {
  int n, a, b, fl = 0, i, c, d;
  scanf("%d", &n);
  scanf("%d", &a);
  scanf("%d", &b);
  for (i = 1; i <= n; i++) {
    scanf("%d", &c);
    m[c] = i;
  }
  if (a > b) {
    fl = 1;
    swap(a, b);
  }
  map<int, int>::iterator it;
  while (!m.empty()) {
    it = m.end();
    it--;
    c = it->first;
    d = it->second;
    if (m.find(a - c) != m.end()) {
      check[d] = 0;
      check[m[a - c]] = 0;
      m.erase(c);
      m.erase(a - c);
      continue;
    }
    if (m.find(b - c) != m.end()) {
      check[d] = 1;
      check[m[b - c]] = 1;
      m.erase(c);
      m.erase(b - c);
      continue;
    }
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  if (fl)
    for (i = 1; i <= n; i++) printf("%d ", 1 - check[i]);
  else
    for (i = 1; i <= n; i++) printf("%d ", check[i]);
  printf("\n");
  return 0;
}
