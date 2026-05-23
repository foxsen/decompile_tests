#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
ostream &operator<<(ostream &out, const pair<T, V> x) {
  out << "{" << x.first << " : " << x.second << "}";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const set<T> x) {
  for (auto &it : x) {
    out << it << " ";
  }
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const multiset<T> x) {
  for (auto &it : x) {
    out << it << " ";
  }
  return out;
}
template <typename T, typename V>
ostream &operator<<(ostream &out, const map<T, V> x) {
  for (auto &it : x) {
    out << "[" << it.first << "]"
        << " = " << it.second << "\n";
  }
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> x) {
  for (int i = 0; i < x.size() - 1; ++i) {
    out << x[i] << " ";
  }
  out << x.back();
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<vector<T> > x) {
  for (int i = 0; i < x.size() - 1; ++i) {
    out << "[" << i << "]"
        << " = {" << x[i] << "}\n";
  }
  out << "[" << x.size() - 1 << "]"
      << " = {" << x.back() << "}\n";
  return out;
}
const long long N = 1e6 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
map<long long, long long> bal;
void solve() {
  bal.clear();
  long long n, x;
  string s;
  cin >> n >> x >> s;
  long long del = 0;
  for (auto &it : s) {
    if (it == '0')
      del++;
    else
      del--;
    bal[del]++;
  }
  if (del == 0) {
    if (bal.count(x)) {
      cout << -1;
    } else {
      if (x == 0)
        cout << 1;
      else
        cout << 0;
    }
    return;
  }
  long long ans = 0;
  if (x == 0) ans++;
  for (auto &it : bal) {
    if (del > 0) {
      if (it.first <= x && (x - it.first) % del == 0) ans += it.second;
    } else {
      if (it.first >= x && (it.first - x) % -del == 0) ans += it.second;
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    solve();
    cout << "\n";
  }
  return 0;
}
