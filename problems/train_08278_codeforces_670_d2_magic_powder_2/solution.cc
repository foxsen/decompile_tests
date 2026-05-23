#include <bits/stdc++.h>
using namespace std;
const int N6 = 1e6 + 6, N3 = 1e3 + 6, oo = 1e9 + 9, base = 1e9 + 7;
const long long ool = 1e18 + 9;
int n;
long long k, a[N6], ans, b[N6];
pair<long long, int> d[N6];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    d[i].first = (b[i] + a[i] - 1) / a[i];
    d[i].second = i;
  }
  sort(d + 1, d + n + 1);
  long long need = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i].first != d[i - 1].first) {
      if (k < cur) {
        cout << d[i - 1].first - 1 << "\n";
        return 0;
      }
      k -= cur;
      if (k < need * (d[i].first - d[i - 1].first)) {
        cout << d[i - 1].first + k / need << "\n";
        return 0;
      } else {
        k -= need * (d[i].first - d[i - 1].first);
      }
      cur = 0;
    }
    cur += a[d[i].second] *
               ((b[d[i].second] + a[d[i].second] - 1) / a[d[i].second]) -
           b[d[i].second];
    need += a[d[i].second];
  }
  if (k < cur) {
    cout << d[n].first - 1 << "\n";
    return 0;
  }
  k -= cur;
  cout << d[n].first + k / need << "\n";
  return 0;
}
