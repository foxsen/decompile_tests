#include <bits/stdc++.h>
using namespace std;
const int N = (int)(2e6 + 5);
const int LOG = (int)(20);
long long int n, m, ar[N], pre[N], to[N], st, ans = INT_MAX;
void recalc(long long int x) {
  int ind = 0, mini = INT_MAX;
  for (int i = 1; i <= n; i++) {
    while (ind < i + n && pre[ind] - pre[i - 1] <= x) ind++;
    to[i] = ind;
    to[i + n] = min(2 * n + 1, ind + n);
    if (to[i] - i < mini) {
      mini = to[i] - i;
      st = i;
    }
  }
}
long long int calcans(int x) {
  int re = 0, t = x;
  while (t < x + n) t = to[t], re++;
  return re;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    ar[i + n] = ar[i];
  }
  for (int i = 1; i <= 2 * n; i++) pre[i] = pre[i - 1] + ar[i];
  while (m--) {
    long long int a;
    cin >> a;
    ans = INT_MAX;
    recalc(a);
    for (int i = st; i <= to[st]; i++) ans = min(ans, calcans(i));
    cout << ans << "\n";
  }
}
