#include <bits/stdc++.h>
using namespace std;
void fast_io() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void my_file_in_out() {
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
inline void OK(string t = "") { cerr << "OK " << t << '\n'; }
inline long double time() { return clock() / (long double)CLOCKS_PER_SEC; }
inline void stop(string t = "PROCESS FINISHED") {
  cerr << t << '\n';
  exit(0);
}
const long long MODD = 998244353;
const long long M = 1e9 + 7;
long long bp(long long c, long long st) {
  if (!st) return 1;
  if (st & 1) return (c * bp(c, st - 1)) % M;
  return bp((c * c) % M, st >> 1);
}
namespace VECTOR_MAGIC {
template <typename T>
istream &operator>>(istream &inp, vector<T> &a) {
  for (auto &elem : a) inp >> elem;
  return inp;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &elem : a) out << elem << ' ';
  out << endl;
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &a) {
  for (auto &elem : a) out << elem;
  return out;
}
template <typename T>
void operator++(vector<T> &a) {
  for (auto &el : a) el++;
}
template <typename T>
void operator--(vector<T> &a) {
  for (auto &el : a) el--;
}
}  // namespace VECTOR_MAGIC
using namespace VECTOR_MAGIC;
mt19937 rnd(time(0));
int rndc(int x) {
  int u = rnd();
  if (u < 0) u = -u;
  return u % x;
}
const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const long long LINF = 4e17 + 9;
void solve() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  string sub = "abacaba";
  for (int i = 0; i < n - 6; i++) {
    bool fl = 1;
    string b = a;
    for (int j = 0; j < 7; j++) {
      if (!(sub[j] == a[i + j] || a[i + j] == '?')) fl = 0;
      b[i + j] = sub[j];
    }
    if (!fl) continue;
    for (auto &el : b)
      if (el == '?') el = 'z';
    int kol = 0;
    for (int k = 0; k < n - 6; k++) {
      bool p = 1;
      for (int j = 0; j < 7; j++)
        if (!(sub[j] == b[k + j] || b[k + j] == '?')) p = 0;
      kol += p;
    }
    if (kol == 1) {
      cout << "Yes\n";
      cout << b << '\n';
      return;
    }
  }
  cout << "No\n";
}
signed main() {
  fast_io();
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
