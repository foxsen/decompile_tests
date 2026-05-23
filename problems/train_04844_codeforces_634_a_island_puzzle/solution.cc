#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  deque<int> a(n), b(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  a.erase(find(a.begin(), a.end(), 0));
  b.erase(find(b.begin(), b.end(), 0));
  while (a[0] != 1) a.push_back(a[0]), a.pop_front();
  while (b[0] != 1) b.push_back(b[0]), b.pop_front();
  puts(a == b ? "YES" : "NO");
  return 0;
}
