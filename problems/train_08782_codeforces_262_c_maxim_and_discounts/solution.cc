#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int fexpo(long long int a, long long int b) {
  if (b == 0) return 1LL;
  if (b == 1) return a;
  if (b == 2) return ((a) * (a));
  if (b % 2 == 0)
    return fexpo(fexpo(a, b / 2), 2);
  else
    return ((a) * (fexpo(fexpo(a, (b - 1) / 2), 2)));
}
long long int q[101010];
long long int ar[101010];
bool comp(long long int a, long long int b) {
  if (a > b) return true;
  return false;
}
int main() {
  int m, n;
  cin >> m;
  long long int q_min = INT_MAX;
  for (int i = 1; i <= m; i++) {
    cin >> q[i];
    q_min = min(q[i], q_min);
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  sort(ar + 1, ar + n + 1, comp);
  int l = 1;
  int r = n;
  long long int ans = 0;
  int ct = 1;
  for (int i = 1; i <= n; i++) {
    if (ct <= q_min) {
      ans += ar[i];
    }
    if (ct == q_min + 2) {
      ct = 0;
    }
    ct++;
  }
  cout << ans << endl;
}
