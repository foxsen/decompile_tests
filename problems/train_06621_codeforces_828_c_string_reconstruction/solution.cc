#include <bits/stdc++.h>
using namespace std;
char c[2000100];
int p[2000100];
int get(int a) {
  if (p[a] == a) return a;
  return p[a] = get(p[a]);
}
void unite(int a, int b) { p[a] = b; }
void add(string &s, int a) {
  int k = get(a);
  while (true) {
    if (k - a + 1 > s.size()) break;
    c[k] = s[k - a];
    unite(k, k + 1);
    k = get(a);
  }
}
int main() {
  int n, i, k, a, j, m = 0;
  string s;
  cin >> n;
  for (i = 1; i <= 2000000; ++i) {
    c[i] = '#';
    p[i] = i;
  }
  for (i = 0; i < n; ++i) {
    cin >> s >> k;
    for (j = 0; j < k; ++j) {
      cin >> a;
      m = max(m, (int)s.size() + a - 1);
      add(s, a);
    }
  }
  for (i = 1; i <= m; ++i) {
    if (c[i] == '#') c[i] = 'a';
    cout << c[i];
  }
  return 0;
}
