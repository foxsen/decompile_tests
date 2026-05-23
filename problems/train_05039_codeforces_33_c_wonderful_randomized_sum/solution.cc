#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  long long pref[100010], suff[100010];
  memset(pref, -127, sizeof(pref));
  memset(suff, -127, sizeof(suff));
  long long sum = accumulate(a.begin(), a.end(), 0);
  long long cur = 0;
  pref[0] = cur;
  for (int i = 1; i <= n; i++) {
    cur -= a[i - 1];
    pref[i] = max(pref[i - 1] + a[i - 1], cur);
  }
  cur = 0;
  suff[n] = cur;
  for (int i = n - 1; i >= 0; i--) {
    cur -= a[i];
    suff[i] = max(suff[i + 1] + a[i], cur);
  }
  long long res = -1000000000000000000LL;
  for (int i = 0; i <= n; i++) {
    res = max(res, pref[i] + suff[i]);
  }
  cout << res << endl;
}
