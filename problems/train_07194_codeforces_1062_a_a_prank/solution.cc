#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long MOD = (long long)1e9 + 7;
const long long MOD2 = 1007681537;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-12;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, long long p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline long long chkmin(T &a, const T &val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline long long chkmax(T &a, const T &val) {
  return a < val ? a = val, 1 : 0;
}
inline void addmod(long long &a, long long val, long long p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(long long &a, long long val, long long p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline long long mult(long long a, long long b, long long p = MOD) {
  return (long long)a * b % p;
}
inline long long inv(long long a, long long p = MOD) {
  return fpow(a, p - 2, p);
}
inline void get_arr(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) cin >> arr[i];
}
inline void print_arr(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "\n";
  ;
}
long long dp[65];
long long cp[65];
long long clc(long long l) {
  if (l == 0) {
    return 0;
  }
  long long x = 0;
  for (long long i = 0; i < 64; i++) {
    if (cp[i] > l) {
      x = i - 1;
      break;
    }
  }
  long long o = 0, e = 0;
  for (long long i = 0; i <= x; i = i + 2) {
    o += dp[i];
    o = o % MOD;
  }
  for (long long i = 1; i <= x; i = i + 2) {
    e += dp[i];
    e = e % MOD;
  }
  if (x % 2 == 1) {
    o += l - cp[x];
    o = o % MOD;
  } else {
    e += l - cp[x];
    e = e % MOD;
  }
  long long ans = 0;
  ans = ((o % MOD) * (o % MOD)) % MOD;
  ans += (((e % MOD) * (e % MOD)) % MOD + (e % MOD)) % MOD;
  return ans % MOD;
}
int32_t main() {
  long long n;
  cin >> n;
  long long arr[n];
  get_arr(arr, n);
  long long c = 0;
  if (n == 1) {
    cout << "0";
    return 0;
  }
  if (n == 2) {
    if (arr[1] - arr[0] == 1 && (arr[0] == 1 || arr[1] == 1000)) {
      cout << "1";
      return 0;
    } else {
      cout << "0";
      return 0;
    }
  }
  if (n == 3) {
    if (arr[0] == 1) {
      if (arr[1] == 2) {
        if (arr[2] == 3) {
          cout << "2";
        } else {
          cout << "1";
        }
        return 0;
      }
    }
  }
  if (arr[0] == 1) {
    for (long long i = 1; i < n; i++) {
      if (arr[i] - arr[i - 1] == 1) {
        c++;
      } else {
        break;
      }
    }
  }
  long long d = 0;
  if (arr[n - 1] == 1000) {
    for (long long i = n - 2; i >= 0; i--) {
      if (arr[i + 1] - arr[i] == 1) {
        d++;
      } else {
        break;
      }
    }
  }
  c = max(c, d);
  for (long long i = 0; i < n; i++) {
    long long j = i + 1;
    long long x = 0;
    while (arr[j] - arr[j - 1] == 1) {
      x++;
      j++;
    }
    c = max(c, x - 1);
  }
  cout << c;
}
