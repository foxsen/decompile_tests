#include <bits/stdc++.h>
using namespace std;
template <class T>
void mini(T& a, T b) {
  a = min(a, b);
}
template <class T>
void maxi(T& a, T b) {
  a = max(a, b);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  return out << a.first << " " << a.second;
}
template <class T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, set<T> a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2> a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T>
void out(T a) {
  cout << a << endl;
}
void out() { cout << "OK" << endl; }
const int N = 1 << 20;
const int inf = 1e9;
const int K = 105;
int dp[N];
int a[K];
pair<char, int> b[K];
int n, m;
int solve(int id = 0, int mask = 0) {
  if (dp[mask] != inf) return dp[mask];
  if (id == m) return dp[mask] = 0;
  char tp = b[id].first;
  int team = b[id].second;
  if (tp == 'p') {
    int mx = -1;
    for (int i = 0; i < m; i++) {
      if (!(mask & (1 << i))) {
        mx = i;
        break;
      }
    }
    if (team == 1)
      dp[mask] = a[mx];
    else
      dp[mask] = -a[mx];
    dp[mask] += solve(id + 1, mask | (1 << mx));
  } else {
    int res;
    if (team == 1) {
      res = -inf;
      for (int i = 0; i < m; i++) {
        if (!(mask & (1 << i))) {
          maxi(res, solve(id + 1, mask | (1 << i)));
        }
      }
      dp[mask] = res;
    } else {
      res = inf;
      for (int i = 0; i < m; i++) {
        if (!(mask & (1 << i))) {
          mini(res, solve(id + 1, mask | (1 << i)));
        }
      }
      dp[mask] = res;
    }
  }
  return dp[mask];
}
void Solve() {
  for (int i = 0; i < N; i++) dp[i] = inf;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  cout << solve() << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Solve();
  return 0;
}
