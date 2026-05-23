#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:500000000")
using namespace std;
int main() {
  int n, k, i;
  scanf("%d %d", &n, &k);
  vector<int> a(n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  int L, R;
  L = 0, R = a.back();
  int RR = R;
  while (L <= R) {
    int c = (L + R) / 2;
    long long sm = 0;
    for (auto p : a)
      if (p >= c) sm += p - c;
    if (sm <= k)
      R = c - 1, RR = c;
    else
      L = c + 1;
  }
  L = 0, R = a.back();
  int LL = 0;
  while (L <= R) {
    int c = (L + R) / 2;
    long long sm = 0;
    for (auto p : a)
      if (c >= p) sm += c - p;
    if (sm <= k)
      L = c + 1, LL = c;
    else
      R = c - 1;
  }
  auto diff = RR - LL;
  if (diff <= 0) {
    long long sum = 0;
    for (auto p : a) sum += p;
    if (sum % n == 0)
      diff = 0;
    else
      diff = 1;
  }
  cout << diff << endl;
}
