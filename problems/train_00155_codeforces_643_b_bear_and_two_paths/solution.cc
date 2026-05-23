#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<T> &v) {
  for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
    out << v[i] << " ";
  out << "\n";
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, set<T> &s) {
  for (auto e : s) out << e << " ";
  out << "\n";
  return out;
}
template <typename T, typename N>
std::ostream &operator<<(std::ostream &out, pair<T, N> &p) {
  out << "(" << p.first << ", " << p.second << ") ";
  return out;
}
template <typename T, typename N>
std::ostream &operator<<(std::ostream &out, vector<pair<T, N> > &v) {
  for (size_t i = 0; i < v.size(); ++i) cout << v[i];
  out << "\n";
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<vector<T> > &v) {
  for (size_t i = 0; i < v.size(); ++i) {
    for (size_t j = 0; j < v[i].size(); ++j) {
      out << v[i][j] << " ";
    }
    out << "\n";
  }
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<set<T> > &v) {
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
  }
  out << "\n";
  return out;
}
void solve() {
  int n, k;
  cin >> n >> k;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (n == 4 || k < n + 1) {
    cout << "-1\n";
    return;
  }
  cout << a << " " << c << " ";
  vector<int> middle_vertices;
  for (int i = 1; i <= n; ++i) {
    if (i != a && i != b && i != c && i != d) {
      cout << i << " ";
    }
  }
  cout << d << " " << b << "\n";
  cout << c << " " << a << " ";
  for (int i = 1; i <= n; ++i) {
    if (i != a && i != b && i != c && i != d) {
      cout << i << " ";
    }
  }
  cout << b << " " << d << "\n";
  return;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
