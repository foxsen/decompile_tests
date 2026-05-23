#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const long long INF = 2e18;
void print(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
void printll(long long a[], long long n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
vector<int> primes;
void sieve() {
  bool isPrime[100000 + 5];
  memset(isPrime, true, sizeof(isPrime));
  for (int i = 3; i * i <= 100000 + 5; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j <= 100000 + 5; j += 2 * i) {
        isPrime[j] = false;
      }
    }
  }
  primes.push_back(2);
  for (int i = 3; i < 100000 + 5; i += 2) {
    if (isPrime[i]) primes.push_back(i);
  }
}
vector<long long> findPrimeFactors(long long n) {
  vector<long long> primeFactors;
  while (n % 2 == 0) primeFactors.push_back(2), n = n / 2;
  for (long long i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      primeFactors.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) primeFactors.push_back(n);
  return primeFactors;
}
vector<long long> allDivisiors(long long n) {
  vector<long long> divisors;
  long long limit = sqrt(n + 1);
  for (long long i = 1; i <= limit; i++) {
    if (n % i == 0) {
      if (n / i == i)
        divisors.push_back(i);
      else
        divisors.push_back(i), divisors.push_back(n / i);
    }
  }
  return divisors;
}
bool isPrime(long long n) {
  if (n == 2 or n == 3) return true;
  if (n % 2 == 0) return false;
  for (long long i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
long long nsum(long long n) { return (n * (n + 1)) / 2; }
long long power(long long n, long long p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * n;
    n = n * n;
    p = p / 2;
  }
  return ans;
}
long long mpower(long long n, long long p, long long mod) {
  if (p == -1) p = mod - 2;
  if (p == 0) return 1;
  if (p == 1) return n;
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * n) % mod;
    n = (n * n) % mod;
    p = p / 2;
  }
  return ans;
}
bool isPalindrome(string s) {
  int N = s.size();
  for (int i = 0; i < (N / 2); i++) {
    if (s[i] != s[N - 1 - i]) return 0;
  }
  return 1;
}
long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  cout << s << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  int testCase = 0;
  while (tc--) {
    solve();
  }
}
