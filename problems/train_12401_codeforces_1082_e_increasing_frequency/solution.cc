#include <bits/stdc++.h>
using namespace std;
template <typename T>
void pr(vector<T> &v) {
  for (int i = 0; i < (int)(v).size(); i++) cout << v[i] << " ";
  cout << endl;
}
template <typename T>
void pr(vector<vector<T>> &v) {
  for (int i = 0; i < (int)(v).size(); i++) {
    pr(v[i]);
  }
}
template <typename T>
void re(T &first) {
  cin >> first;
}
template <typename T>
void re(vector<T> &a) {
  for (int i = 0; i < (int)(a).size(); i++) re(a[i]);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <typename T>
void pr(T first) {
  cout << first << endl;
}
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  cout << first << " ";
  pr(rest...);
  cout << endl;
}
void ps() { cout << endl; }
template <class T, class... Ts>
void ps(const T &t, const Ts &...ts) {
  cout << t;
  if (sizeof...(ts)) cout << " ";
  ps(ts...);
}
vector<int> pre;
int cnt(int l, int r) { return pre[r + 1] - pre[l]; }
void solve() {
  int n, c;
  re(n, c);
  vector<int> a(n);
  re(a);
  pre.resize(n + 1);
  pre[0] = 0;
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + ((a[i] == c) ? 1 : 0);
  }
  vector<vector<int>> ind(5e5 + 1);
  for (int i = 0; i < n; i++) {
    ind[a[i]].push_back(i);
  }
  int mx = 0;
  for (int i = 1; i < (int)(ind).size(); i++) {
    int m = (int)(ind[i]).size();
    if (!m || i == c) continue;
    int cur = 1;
    mx = max(mx, cur);
    for (int j = 1; j < (int)(ind[i]).size(); j++) {
      cur -= cnt(ind[i][j - 1], ind[i][j]) - 1;
      if (cur <= 0) {
        cur = 1;
      }
      mx = max(mx, cur);
    }
  }
  pr(cnt(0, n - 1) + mx);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
}
