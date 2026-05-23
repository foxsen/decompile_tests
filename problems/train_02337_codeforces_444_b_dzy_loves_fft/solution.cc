#include <bits/stdc++.h>
using namespace std;
long long n, d, x;
long long a[100002], b[100002], c[100002], q[100002], pos[100002];
long long sb = 0;
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (long long i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (long long i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (long long i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (long long i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> d >> x;
  initAB();
  for (long long i = 0; i < n; i++) {
    if (b[i]) {
      sb++;
      q[sb] = i;
    }
    pos[a[i]] = i;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = n; j > n - 30LL; j--) {
      if (j < 1) break;
      if (i >= pos[j] && b[i - pos[j]]) {
        c[i] = j;
        break;
      }
    }
    if (c[i] != 0) continue;
    long long v = 0;
    for (long long j = 1; j <= sb; j++) {
      if (q[j] > i) break;
      v = max(v, a[i - q[j]]);
    }
    c[i] = v;
  }
  for (long long i = 0; i < n; i++) {
    cout << c[i] << "\n";
  }
  return 0;
}
