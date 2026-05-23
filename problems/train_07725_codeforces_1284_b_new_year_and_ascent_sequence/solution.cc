#include <bits/stdc++.h>
using namespace std;
long long A[500009], mx[500009], mn[500009], ys[500009], cnt[1000009];
string x[109], y[1209];
int main() {
  long long N, M, i, j, k, Q, a = 0, t, b = 0;
  cin >> N;
  for (i = 1; i <= N; i++) {
    cin >> k;
    mx[i] = -1;
    mn[i] = 10000000000;
    t = 0;
    for (j = 1; j <= k; j++) {
      cin >> A[j];
      mx[i] = max(mx[i], A[j]);
      mn[i] = min(mn[i], A[j]);
      if (t < 1 && j > 1 && A[j] > A[j - 1]) {
        t = 1;
        a++;
        ys[i] = 1;
      }
    }
    if (t == 0) {
      cnt[mx[i]]++;
    }
  }
  for (i = 1000000; i >= 0; i--) {
    cnt[i] += cnt[i + 1];
  }
  for (i = 1; i <= N; i++) {
    if (ys[i] == 0) {
      b += cnt[mn[i] + 1];
    }
  }
  cout << 2 * N * a - a * a + b << endl;
}
