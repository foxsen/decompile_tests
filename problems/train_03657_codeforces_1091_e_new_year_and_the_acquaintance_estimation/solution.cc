#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long exp(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b == 1) return mod(a, m);
  long long k = mod(exp(a, b / 2, m), m);
  if (b & 1) {
    return mod(a * mod(k * k, m), m);
  } else
    return mod(k * k, m);
}
long long mark[500100];
long long pre[500100];
long long A[500100];
long long sum = 0;
long long n;
long long is_score(long long value) {
  vector<long long> C(n + 1, 0);
  long long N = n;
  for (long long i = 0; i < N; ++i) ++C[A[i]];
  ++C[value];
  long long less = 0;
  long long left = 0, right = 0;
  for (long long k = 0, i = 0; k <= N; k++) {
    long long val = (i == k && (i == N || A[i] < value)) ? value : A[i++];
    left += val;
    --C[val];
    right -= min(val, k);
    less += C[k];
    right += N - k - less;
    if (left > right + (long long)(k + 1) * k) {
      return (i == k) ? 1 : -1;
    }
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  long long s = 0;
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
    sum += A[i];
    s += A[i];
  }
  if (s % 2 == 0)
    s = 0;
  else
    s = 1;
  sort(A, A + n, greater<long long>());
  long long l = 0, r = (n - s) / 2, lans = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (is_score(2 * mid + s) == -1) {
      l = mid + 1;
    } else {
      lans = mid;
      r = mid - 1;
    }
  }
  l = lans, r = (n - s) / 2;
  long long rans = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (is_score(2 * mid + s) == 1) {
      r = mid - 1;
    } else {
      rans = mid;
      l = mid + 1;
    }
  }
  if (lans == -1 || rans == -1) {
    cout << -1 << "\n";
  } else {
    for (long long i = lans; i <= rans; i++) {
      cout << 2 * i + s << " ";
    }
    cout << "\n";
  }
}
