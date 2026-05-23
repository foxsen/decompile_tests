#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n;
int a[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  long long lo = *max_element(a, a + n), hi = 1e13;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    long long tot = 0;
    for (int i = 0; i < n; i++) tot += max(0LL, mid - a[i]);
    if (tot < mid)
      lo = mid + 1;
    else
      hi = mid;
  }
  cout << lo << endl;
  return 0;
}
