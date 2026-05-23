#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main() {
  int n, m, i, l, r, x;
  set<int> s;
  cin >> n >> m;
  for (i = 1; i <= n; i++) s.insert(i);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &l, &r, &x);
    for (set<int>::iterator it = s.lower_bound(l);
         it != s.end() && (*it) <= r;) {
      if (*it != x) {
        a[*it] = x;
        s.erase(it++);
      } else
        it++;
    }
  }
  for (i = 1; i <= n; i++) printf("%d ", a[i]);
  cout << endl;
  return 0;
}
