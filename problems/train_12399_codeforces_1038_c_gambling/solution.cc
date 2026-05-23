#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
const int M = 4e6 + 7;
const int lim = 1e6;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
multiset<long long> ms;
priority_queue<int> pq;
int a[N], b[N];
int main() {
  int n;
  long long aa = 0, bb = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  int ak = n, bk = n;
  while (n--) {
    if (a[ak] > b[bk])
      aa += a[ak], ak--;
    else
      bk--;
    if (b[bk] > a[ak])
      bb += b[bk], bk--;
    else
      ak--;
  }
  printf("%lld\n", aa - bb);
  return 0;
}
