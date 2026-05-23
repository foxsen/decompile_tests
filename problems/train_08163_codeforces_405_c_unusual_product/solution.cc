#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}
long long exp(long long a, long long b) {
  long long ans = 1;
  while (b != 0) {
    if (b % 2) ans = ans * a;
    a = a * a;
    b /= 2;
  }
  return ans;
}
int arr[1005][1005];
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (long long i = (long long)0; i < (long long)n; i++) {
    for (long long j = (long long)0; j < (long long)n; j++)
      scanf("%d", &arr[i][j]);
  }
  for (long long i = (long long)0; i < (long long)n; i++) {
    ans = ans + arr[i][i];
  }
  ans %= 2;
  int q;
  scanf("%d", &q);
  for (long long i = (long long)0; i < (long long)q; i++) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1 || ty == 2) {
      int row;
      scanf("%d", &row);
      ans = ans ^ 1;
    } else
      printf("%lld", ans);
  }
  return 0;
}
