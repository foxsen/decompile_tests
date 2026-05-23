#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
long long int expo(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
long long int mmiprime(long long int a, long long int b) {
  return expo(a, b - 2, b);
}
void extendgcd(long long int a, long long int b, long long int* v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long int x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long int mod_div(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mmiprime(b, m), m) + m) % m;
}
vector<long long int> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
const long long INF = 1e18;
void sk_kr() {
  int n;
  cin >> n;
  int maxi = 0;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }
  int ans = 0;
  int mini = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == maxi) {
      cout << ans << endl;
      return;
    } else {
      if (a[i] > mini) {
        ans++;
        mini = a[i];
      }
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  auto begin = chrono::high_resolution_clock::now();
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    sk_kr();
  }
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - begin);
  return 0;
}
