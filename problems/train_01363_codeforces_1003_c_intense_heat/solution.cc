#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const ll INF = 1e18;
template <typename A, typename B>
inline void prt(pair<A, B> p) {
  cout << "(" << p.first << ", " << p.second << ")\n";
}
template <typename A, typename B, typename C>
inline void prt(tuple<A, B, C> p) {
  cout << "(" << get<0>(p) << ", " << get<1>(p) << ", " << get<2>(p) << ")\n";
}
inline void prt(bool p) {
  if (p)
    cout << "True" << '\n';
  else
    cout << "False" << '\n';
}
template <typename T>
inline void prt(vector<T> v) {
  cout << '{';
  for (ll i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i < v.size() - 1) cout << ", ";
  }
  cout << '}' << '\n';
}
template <typename T>
inline void prt(deque<T> v) {
  cout << '{';
  for (ll i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i < v.size() - 1) cout << ", ";
  }
  cout << '}' << '\n';
}
template <typename A, typename B>
inline void prt(map<A, B> v) {
  cout << '{';
  ll c = 0;
  for (auto& p : v) {
    cout << p.first << ":" << p.second;
    c++;
    if (c != v.size()) cout << ", ";
  }
  cout << '}' << '\n';
}
template <typename A, typename B>
inline void prt(unordered_map<A, B> v) {
  cout << '{';
  ll c = 0;
  for (auto& p : v) {
    cout << p.first << ":" << p.second;
    c++;
    if (c != v.size()) cout << ", ";
  }
  cout << '}' << '\n';
}
template <typename T>
inline void prt(set<T> v) {
  cout << '{';
  for (auto i = v.begin(); i != v.end(); i++) {
    cout << *i;
    if (i != --v.end()) cout << ", ";
  }
  cout << '}' << '\n';
}
template <typename T>
inline void prt(multiset<T> v) {
  cout << '{';
  for (auto i = v.begin(); i != v.end(); i++) {
    cout << *i;
    if (i != --v.end()) cout << ", ";
  }
  cout << '}' << '\n';
}
int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll i = 0; i < (n); ++i) cin >> a[i];
  vector<ll> r(n + 1, 0);
  for (ll i = 0; i < (n); ++i) {
    r[i + 1] = r[i] + a[i];
  }
  double ans = 0;
  for (ll i = 0; i < (n); ++i) {
    for (int j = i + k; j <= n; j++) {
      double now = (r[j] - r[i]) / double(j - i);
      chmax(ans, now);
    }
  }
  printf("%.16lf\n", ans);
  return 0;
}
