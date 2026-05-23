#include <bits/stdc++.h>
using namespace std;
long long int dep(long long int t, long long int k) {
  t %= (2 * k);
  if (t <= k)
    return t;
  else
    return (2 * k - t);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, l;
    cin >> n >> k >> l;
    vector<long long int> d(n + 1, 0);
    for (long long int i = 1; i < n + 1; i++) cin >> d[i];
    long long int fl = 0;
    vector<long long int> safe(n + 1);
    safe[0] = 1;
    for (long long int i = 1; i < n + 1; i++) {
      if (d[i] > l) {
        fl = 1;
        break;
      }
      if (d[i] + k <= l)
        safe[i] = 1;
      else
        safe[i] = 0;
    }
    if (fl) {
      cout << "No" << endl;
      continue;
    }
    fl = 0;
    long long int t = 0;
    for (long long int i = 0; i < n; i++) {
      if (safe[i]) {
        if (safe[i + 1])
          continue;
        else {
          long long int h = (d[i + 1] + k) - l;
          t = (k + h) % (2 * k);
        }
      } else {
        if (safe[i + 1])
          continue;
        else {
          if (d[i + 1] + dep(t + 1, k) <= l) {
            t++;
            t %= (2 * k);
          } else {
            if (t < k) {
              fl = 1;
              break;
            } else {
              long long int h = d[i + 1] + dep(t + 1, k) - l;
              t = (t + h) % (2 * k);
              t++;
              t %= (2 * k);
            }
          }
        }
      }
    }
    if (fl)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
}
