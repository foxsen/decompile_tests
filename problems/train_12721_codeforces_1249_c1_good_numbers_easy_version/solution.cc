#include <bits/stdc++.h>
using namespace std;
long long pwr(long long base, long long p, long long mod) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
bool cmp(int a, int b) { return a > b; }
const int dx[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
const int dsx[4] = {0, 1, 0, -1};
const int dsy[4] = {1, 0, -1, 0};
const int mod = 1e9 + 7;
template <class T, class second>
void outvp(vector<pair<T, second>> &v) {
  for (pair<T, second> x : v) cout << x.first << " " << x.second << endl;
}
template <typename T>
void outv(vector<T> &v) {
  for (T x : v) cout << x << " ";
  cout << endl;
}
template <typename T>
void outs(set<T> &v) {
  for (T x : v) cout << x << " ";
  cout << endl;
}
template <typename T>
void outm(map<T, int> &v, int n = 1) {
  for (T &x : v) cout << (n == 1 ? x.first : x.second) << " ";
  cout << endl;
}
template <typename T>
void readv(vector<T> &v, long long n) {
  for (long long i = 0; i < n; i++) {
    T x;
    cin >> x;
    v.push_back(x);
  }
}
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1) {
  std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
int multiply(int x, int res[], int res_size) {
  int carry = 0;
  for (int i = 0; i < res_size; i++) {
    int prod = res[i] * x + carry;
    res[i] = prod % 10;
    carry = prod / 10;
  }
  while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
  }
  return res_size;
}
void power(int x, int n) {
  if (n == 0) {
    cout << "1";
    return;
  }
  int res[10000];
  int res_size = 0;
  int temp = x;
  while (temp != 0) {
    res[res_size++] = temp % 10;
    temp = temp / 10;
  }
  for (int i = 2; i <= n; i++) res_size = multiply(x, res, res_size);
  for (int i = res_size - 1; i >= 0; i--) cout << res[i];
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    vector<int> a;
    long long n;
    cin >> n;
    long long temp = n;
    while (n > 0) {
      a.push_back(n % 3);
      n /= 3;
    }
    int z = -1;
    bool f = false;
    for (int i = a.size() - 1; i >= 0; i--) {
      if ((!f) && (a[i] == 0)) z = i;
      if (a[i] == 2) {
        f = true;
        break;
      }
      if (f && z == -1) break;
    }
    if (f && z > 0) {
      for (int i = z - 1; i >= 0; i--) a[i] = 0;
    }
    if (f && z == -1) {
      power(3, a.size());
    } else {
      if (f) a[z] = 1;
      long long ans = a[0];
      long long num = 3;
      for (int i = 1; i < a.size(); i++) {
        if (a[i]) ans += num;
        num *= 3;
      }
      cout << ans;
    }
    cout << endl;
  }
  return 0;
}
