#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const long long int MODA = 1000000007;
vector<long long int> primefactors;
vector<long long int> factors;
long long int fact[1025] = {};
bool isPowerTwo(long long int x) { return (x && !(x & (x - 1))); }
long long int modmul(long long int a, long long int b) {
  return ((a % MODA) * (b % MODA)) % MODA;
}
long long int modadd(long long int a, long long int b) {
  return ((a % MODA) + (b % MODA) + MODA) % MODA;
}
long long int modsub(long long int a, long long int b) {
  return ((a % MODA) - (b % MODA) + MODA) % MODA;
}
bool isSubstring(string s1, string s2) {
  if (s1.find(s2) != string::npos)
    return true;
  else
    return false;
}
void generateFactorial(long long int n) {
  fact[0] = 1;
  for (long long int i = 1; i <= n; i++) fact[i] = (i * 1ll * fact[i - 1]);
}
void generateFactorialMOD(long long int n) {
  fact[0] = 1;
  for (long long int i = 1; i <= n; i++)
    fact[i] = (i * 1ll * fact[i - 1]) % MODA;
}
bool isPrime(long long int n) {
  if (n < 2) return false;
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long int powermod(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MODA;
    a = (a * a) % MODA;
    b >>= 1;
  }
  return res;
}
long long int modi(long long int a) {
  long long int m = MODA, second = 1, p = 0;
  while (a > 1) {
    long long int q = a / m, t = m;
    m = a % m;
    a = t;
    t = p;
    p = second - q * p;
    second = t;
  }
  return second >= 0 ? second : second + MODA;
}
void generatePrimeFactors(long long int n) {
  primefactors.clear();
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      primefactors.push_back(i);
      while (n % i == 0) n = n / i;
    }
  }
  if (n != 1) primefactors.push_back(n);
}
long long int ncr(long long int n, long long int r) {
  if (r == 0) return 1;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MODA;
  return (fact[n] * modi(fact[r]) % MODA * modi(fact[n - r]) % MODA) % MODA;
}
void generateFactors(long long int n) {
  factors.clear();
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      factors.push_back(i);
      if (n / i != i) factors.push_back(n / i);
    }
  }
  factors.push_back(1);
  factors.push_back(n);
  sort(factors.begin(), factors.end());
}
long double Logn(long double n, long double r) { return log(n) / log(r); }
const int Nmax = 1000005;
vector<int> func(vector<int> v1, vector<int> v2) {
  vector<pair<int, int>> dif;
  vector<int> index;
  int sum1 = 0;
  int sum2 = 0;
  for (int i = 0; i < (int)v1.size(); i++) {
    sum1 += v1[i];
    sum2 += v2[i];
  }
  if (sum1 >= sum2) {
    return index;
  } else {
    int diff = sum2 - sum1;
    for (int i = 0; i < (int)v1.size(); i++) {
      dif.push_back(make_pair(v2[i] - v1[i], i));
    }
    sort(dif.begin(), dif.end());
    int lI = (int)dif.size();
    lI--;
    while (lI >= 0 && diff > 0) {
      diff -= dif[lI].first;
      index.push_back(dif[lI].second);
      lI--;
    }
    return index;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      ;
      v[j].push_back(x);
    }
  }
  vector<int> ans(m + 1);
  for (int i = 0; i < n - 1; i++) {
    vector<int> curans = func(v[i], v[n - 1]);
    if ((int)curans.size() < (int)ans.size()) {
      ans = curans;
    }
  }
  cout << (int)ans.size() << "\n";
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  ;
}
