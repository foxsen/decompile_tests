#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
pair<int, int> a[N];
int n, k;
vector<int> w;
long long calc(int v) {
  int l = lower_bound(a + 1, a + n + 1, pair<int, int>(v - 1, 0)) - a;
  int r = lower_bound(a + 1, a + n + 1, pair<int, int>(v + 1, 0)) - a - 1;
  int must = k - l + 1;
  if (must > r - l + 1 || v > n || v < must) return (1ll << 60);
  long long ans = 0;
  w.clear();
  for (int i = (int)(l); i <= (int)(r); i++) w.push_back(a[i].second);
  sort(w.begin(), w.end(), greater<int>());
  for (int i = (int)(1); i <= (int)(must); i++) {
    ans += w.back();
    w.pop_back();
    --v;
  }
  for (int i = (int)(1); i <= (int)(l - 1); i++) w.push_back(a[i].second);
  for (int i = (int)(r + 1); i <= (int)(n); i++) w.push_back(a[i].second);
  sort(w.begin(), w.end(), greater<int>());
  for (int i = (int)(1); i <= (int)(v); i++) {
    ans += w.back();
    w.pop_back();
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  k = n - k + 1;
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + n + 1);
  if (!k) return puts("0"), 0;
  int s = a[k].first;
  long long ans = (1ll << 60);
  for (int i = (int)(s - 1); i <= (int)(s + 3); i++) ans = min(ans, calc(i));
  printf("%lld\n", ans == (1ll << 60) ? -1 : ans);
}
