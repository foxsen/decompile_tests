#include <bits/stdc++.h>
using namespace std;
long long sum, x, n, k;
long long arr[123456];
long long t[123456];
long long cum[123456];
long long ans[123456];
long long res[123456];
long long bs() {
  int s = 0, e = n, mid;
  while (s < e) {
    mid = (s + e + 1) / 2;
    if (x >= cum[mid] - sum)
      s = mid;
    else
      e = mid - 1;
  }
  return s;
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &t[i]);
    sum += t[i];
    cum[i] = sum;
  }
  sum = 0;
  for (int i = 1; i <= n; i++) {
    x = arr[i];
    k = bs();
    ans[i]++;
    ans[k + 1]--;
    res[k + 1] += arr[i] - (cum[k] - sum);
    sum += t[i];
  }
  for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];
  for (int i = 1; i <= n; i++) cout << ans[i] * t[i] + res[i] << " ";
  cout << endl;
  return 0;
}
