#include <bits/stdc++.h>
using namespace std;
const long long N = 205;
long long n, k, a[N], st[N], fin[N];
bool used[N];
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n, k;
    cin >> n >> k;
    for (long long j = 0; j < k; j++) {
      long long x, y;
      cin >> x >> y;
      a[x] = j + 1;
      a[y] = j + 1;
    }
    long long curr = k + 1;
    for (long long j = 1; j <= 2 * n; j++) {
      if (a[j] == 0) {
        a[j] = curr;
        curr++;
        if (curr == n + 1) curr = k + 1;
      }
    }
    for (long long j = 1; j <= 2 * n; j++) {
      if (used[a[j]])
        fin[a[j]] = j;
      else {
        st[a[j]] = j;
        used[a[j]] = 1;
      }
    }
    long long ans = 0;
    for (long long j0 = 1; j0 <= n; j0++) {
      for (long long j1 = j0 + 1; j1 <= n; j1++) {
        pair<long long, long long> a, b;
        a = make_pair(st[j0], fin[j0]);
        b = make_pair(st[j1], fin[j1]);
        if (a > b) swap(a, b);
        if (a.second > b.first && a.second < b.second) ans++;
      }
    }
    cout << ans << "\n";
    for (long long i = 1; i <= 2 * n; i++) used[i] = st[i] = fin[i] = a[i] = 0;
  }
  return 0;
}
