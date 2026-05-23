#include <bits/stdc++.h>
using namespace std;
long double pi = 3.14159265358979323846;
vector<long long> al[500005];
long long vis[500005], color[500005], I[101][101];
long long gcd(long long a, long long b) {
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
long long bpow(long long n, long long po) {
  long long res = 1;
  while (po > 0) {
    if (po % 2) {
      res *= n;
      po--;
    } else {
      n *= n;
      po /= 2;
    }
  }
  return res;
}
long long binpow(long long n, long long po, long long mod) {
  long long res = 1;
  while (po > 0) {
    if (po % 2) {
      res = (res * n) % mod;
      po--;
    } else {
      n = (n * n) % mod;
      po /= 2;
    }
  }
  return res;
}
long long swap(long long *a, long long *b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}
long long fact(long long n) {
  if ((n == 0) || (n == 1))
    return 1;
  else
    return n * fact(n - 1);
}
long long C(long long n, long long r) {
  if (r > n - r) r = n - r;
  long long ans = 1;
  long long i;
  for (i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
    ans = ans % 1000000007;
  }
  return ans;
}
void mmul(long long A[][101], long long B[][101], long long dim) {
  long long res[dim][dim];
  for (long long i = 0; i < dim; i++)
    for (long long j = 0; j < dim; j++) {
      res[i][j] = 0;
      for (long long k = 0; k < dim; k++)
        res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % 1000000007;
    }
  for (long long i = 0; i < dim; i++)
    for (long long j = 0; j < dim; j++) A[i][j] = res[i][j];
}
void mpow(long long A[][101], long long dim, long long po) {
  for (long long i = 0; i < dim; i++)
    for (long long j = 0; j < dim; j++) {
      if (i == j)
        I[i][j] = 1;
      else
        I[i][j] = 0;
    }
  while (po > 0) {
    if (po % 2 == 1) {
      mmul(I, A, dim);
      po--;
    } else {
      mmul(A, A, dim);
      po /= 2;
    }
  }
  for (long long i = 0; i < dim; i++)
    for (long long j = 0; j < dim; j++) A[i][j] = I[i][j];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  while (testcases--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> a, b;
    long long x, y, z;
    for (long long i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x);
    }
    for (long long i = 0; i < m; i++) {
      cin >> x >> y >> z;
      if (x == 1) b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans[a.size()];
    for (long long i = 0; i < (long long)a.size(); i++) {
      x = a[i];
      long long lo = 0, hi = b.size();
      while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (b[mid] >= x)
          hi = mid;
        else
          lo = mid + 1;
      }
      ans[i] = i + b.size() - lo;
    }
    long long an;
    long long lo = 0, hi = b.size();
    while (lo < hi) {
      long long mid = (lo + hi) / 2;
      if (b[mid] >= 1000000000)
        hi = mid;
      else
        lo = mid + 1;
    }
    an = a.size() + b.size() - lo;
    for (long long i = 0; i < a.size(); i++) an = min(an, ans[i]);
    cout << an;
  }
}
