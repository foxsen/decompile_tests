#include <bits/stdc++.h>
using namespace std;
void print(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
long long int power1(long long int x) {
  long long int u = 0;
  while (x > 0) {
    u++;
    x = x / 2;
  }
  return u;
}
long long int powM(long long int x, long long int y, long long int m) {
  if (m == 1) {
    return 0;
  }
  long long int ans = 1, r = 1;
  x %= m;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans *= x;
      ans %= m;
    }
    r <<= 1;
    x *= x;
    x %= m;
  }
  return ans;
}
int powm(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t1 = 1;
  long long int M = 1e9 + 7;
  while (t1--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int s1 = 0;
    long long int b[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      s1 += a[i];
      b[i] = a[i];
    }
    if (s1 == 1) {
      cout << -1;
    } else {
      vector<long long int> v;
      if (s1 % 2 == 0) {
        v.push_back(2);
        while (s1 % 2 == 0) {
          s1 /= 2;
        }
      }
      for (long long int i = 3; i <= sqrt(s1); i++) {
        if (s1 % i == 0) {
          v.push_back(i);
        }
        while (s1 % i == 0) {
          s1 /= i;
        }
      }
      if (s1 > 2) {
        v.push_back(s1);
      }
      long long int u1 = LONG_LONG_MAX;
      long long int s[n];
      s[0] = a[0];
      for (long long int i = 1; i < n; i++) {
        s[i] = s[i - 1] + a[i];
      }
      for (long long int j = 0; j < v.size(); j++) {
        long long int k = v[j];
        long long int u = 0;
        for (long long int i = 0; i < n; i++) {
          u += min(s[i] % k, k - s[i] % k);
        }
        u1 = min(u1, u);
      }
      cout << u1;
    }
  }
  return 0;
}
