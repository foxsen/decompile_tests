#include <bits/stdc++.h>
using namespace std;
long long arr[100005], ans[2];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld", arr + i);
  }
  for (int sum = 1; sum <= m << 1; sum++) {
    vector<int> vec = {0};
    for (int i = 0; i < n; i++) {
      vec.push_back(arr[i] % sum);
    }
    vec.push_back(sum - 1);
    sort(vec.begin(), vec.end());
    for (int i = n + 1, t = 0; i; i--, t ^= 1) {
      int x = max(vec[i - 1], vec[n - t] / 2) + 1, y = min(vec[i], m);
      int a = max(x, sum - y), b = min(y, sum - x);
      if (a <= b) ans[t] += b - a + 1;
    }
  }
  long long x = ((long long)m * m - ans[0] - ans[1]) / 2;
  printf("%lld %lld %lld %lld\n", x, x, ans[1], ans[0]);
  return 0;
}
