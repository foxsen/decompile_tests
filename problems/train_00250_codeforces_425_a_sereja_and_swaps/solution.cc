#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
long long mod = 1e9 + 7;
long long powm(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = 0; i < (n); i++) {
    cin >> a[i];
  };
  long long ans = -1e9;
  for (long long i = 0; i < (n); i++) {
    for (long long j = (i); j < (n); j++) {
      vector<long long> temp, temp1;
      temp1.clear();
      temp.clear();
      long long sum = 0;
      for (long long ka = 0; ka < (i); ka++) temp1.push_back(a[ka]);
      for (long long ka = (j + 1); ka < (n); ka++) temp1.push_back(a[ka]);
      for (long long ka = (i); ka < (j + 1); ka++)
        temp.push_back(a[ka]), sum += a[ka];
      ans = max(ans, sum);
      sort(temp.begin(), temp.end());
      sort(temp1.begin(), temp1.end());
      reverse(temp1.begin(), temp1.end());
      for (long long ka = 0;
           ka < (min({k, (long long)temp1.size(), (long long)temp.size()}));
           ka++) {
        sum -= temp[ka];
        sum += temp1[ka];
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
