#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int bit[4][12][12][N], n, m, id[307];
string a;
void add(int flag, int start, int gap, int pos, int val) {
  while (pos <= n) bit[flag][start][gap][pos] += val, pos += pos & -pos;
}
int sum(int flag, int start, int gap, int pos) {
  int res = 0;
  while (pos) res += bit[flag][start][gap][pos], pos -= pos & -pos;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  id['A'] = 0;
  id['T'] = 1;
  id['G'] = 2;
  id['C'] = 3;
  cin >> a;
  n = a.size();
  a = string("*") + a;
  for (int i = 1; i <= 10; ++i)
    for (int j = 1; j <= i; ++j)
      for (int k = j; k <= n; k += i) {
        int c = id[a[k]];
        add(c, j, i, k, 1);
      }
  cin >> m;
  while (m--) {
    int op, l, r, x;
    string e;
    cin >> op;
    if (op == 1) {
      cin >> x >> e;
      int c = id[a[x]];
      a[x] = e[0];
      int cc = id[a[x]];
      for (int i = 1; i <= 10; ++i)
        for (int j = 1; j <= i; ++j)
          if ((x - j) % i == 0) {
            add(c, j, i, x, -1);
            add(cc, j, i, x, 1);
          }
    } else {
      cin >> l >> r >> e;
      int res = 0, gap = e.size();
      for (int k = 0; k < e.size(); ++k) {
        int pos = k + l;
        int c = id[e[k]];
        for (int j = 1; j <= gap; ++j)
          if ((pos - j) % gap == 0) {
            res += sum(c, j, gap, r) - sum(c, j, gap, l - 1);
          }
      }
      cout << res << endl;
    }
  }
  return 0;
}
