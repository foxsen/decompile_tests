#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
int n, m, a[maxn], b[maxn];
set<int> q[107];
int main() {
  scanf("%d", &n);
  int x;
  a[1] = 4;
  a[2] = 8;
  a[3] = 15;
  a[4] = 16;
  a[5] = 23;
  a[6] = 42;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    q[x].insert(i);
  }
  int sum = 0;
  while (1) {
    int st = 0;
    int i;
    for (i = 1; i <= 6; i++) {
      if (q[a[i]].empty()) break;
      auto next = q[a[i]].lower_bound(st);
      if (next == q[a[i]].end()) break;
      st = *next;
      q[a[i]].erase(st);
    }
    if (i == 7)
      sum += 6;
    else
      break;
  }
  cout << n - sum << endl;
}
