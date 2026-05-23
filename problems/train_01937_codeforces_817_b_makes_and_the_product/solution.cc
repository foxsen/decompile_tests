#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 1e5 + 3;
const int N = 4;
const int mo = 1e9 + 7;
const LL inf = 1e18 + 1;
map<int, LL> mp;
LL a[M];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    mp[x]++;
  }
  int cnt = 0;
  int sum = 0;
  for (auto &e : mp) {
    a[cnt++] = e.second;
    sum += e.second;
    if (sum >= 3) break;
  }
  LL res = 0;
  if (cnt == 1)
    res = a[0] * (a[0] - 1) * (a[0] - 2) / 6;
  else if (cnt == 2) {
    if (a[0] == 1)
      res = a[1] * (a[1] - 1) / 2;
    else
      res = a[1];
  } else
    res = a[2];
  printf("%I64d\n", res);
  return 0;
}
