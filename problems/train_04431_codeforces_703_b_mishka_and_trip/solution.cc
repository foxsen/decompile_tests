#include <bits/stdc++.h>
using namespace std;
enum { North, East, South, West };
int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MN = 1e+5 + 35;
long long val[MN];
long long sum = 0;
long long ans = 0;
void init() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cout << "[FREOPEN]" << endl;
  return;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &val[i]);
    sum += val[i];
  }
  ans += val[0] * val[n - 1];
  for (int i = 0; i < n - 1; i++) {
    ans += val[i] * val[i + 1];
  }
  long long v1 = 0;
  set<int> qq;
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    x--;
    long long a = 0, b = 0;
    if (x == 0) {
      if (!qq.count(n - 1)) a = val[n - 1];
      if (!qq.count(x + 1)) b = val[x + 1];
    } else if (x == n - 1) {
      if (!qq.count(x - 1)) a = val[x - 1];
      if (!qq.count(0)) b = val[0];
    } else {
      if (!qq.count(x - 1)) a = val[x - 1];
      if (!qq.count(x + 1)) b = val[x + 1];
    }
    long long aux = val[x] * (sum - val[x] - a - b - v1);
    ans += aux;
    qq.insert(x);
    v1 += val[x];
  }
  printf("%lld\n", ans);
  return 0;
}
