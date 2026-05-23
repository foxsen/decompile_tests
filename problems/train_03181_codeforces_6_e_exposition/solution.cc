#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, h[100005], st = 1, ed, mid, cnt, a, b;
  multiset<int> s;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", h + i);
  }
  ed = n;
  while (st <= ed) {
    mid = (st + ed) / 2;
    cnt = 0;
    s.clear();
    for (i = 0; i < mid - 1; i++) {
      s.insert(h[i]);
    }
    for (; i < n; i++) {
      s.insert(h[i]);
      if (*s.rbegin() - *s.begin() <= k) {
        cnt++;
      }
      s.erase(s.find(h[i - mid + 1]));
    }
    if (cnt) {
      a = mid;
      b = cnt;
      st = mid + 1;
    } else {
      ed = mid - 1;
    }
  }
  printf("%d %d\n", a, b);
  s.clear();
  for (i = 0; i < a - 1; i++) {
    s.insert(h[i]);
  }
  for (; i < n; i++) {
    s.insert(h[i]);
    if (*s.rbegin() - *s.begin() <= k) {
      printf("%d %d\n", i - a + 2, i + 1);
    }
    s.erase(s.find(h[i - a + 1]));
  }
}
