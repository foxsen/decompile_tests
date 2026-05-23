#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int n, k, b;
int main() {
  scanf("%d%d%d", &k, &b, &n);
  int k1 = k - 1;
  mp[0] = 1;
  int temp, sum = 0;
  long long ans = 0, zero = 0, tz = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &temp);
    sum = (sum + temp) % k1;
    int t = (sum - b + k1) % k1;
    ans += mp[t];
    mp[sum]++;
    if (temp == 0) {
      zero += ++tz;
    } else
      tz = 0;
  }
  long long ret = 0;
  if (b == 0)
    ret = zero;
  else if (b == k1)
    ret = ans - zero;
  else
    ret = ans;
  printf("%I64d\n", ret);
  return 0;
}
