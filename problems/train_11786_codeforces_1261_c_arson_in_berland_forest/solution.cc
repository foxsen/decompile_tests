#include <bits/stdc++.h>
using namespace std;
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, multiset<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.F << ":" << m.S << ") ";
  return os << "}";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e7 + 7;
const int N = 2e5;
inline int fast_expo(int base, int power, int modulo = mod) {
  base %= modulo;
  if (base < 0) base += modulo;
  long long x = base, cnt = power, ans = 1;
  while (cnt) {
    if (cnt & 1) ans = (ans * x) % modulo;
    x = (x * x) % modulo;
    cnt >>= 1;
  }
  return ans;
}
inline int inv(int base, int modulo = mod) {
  return fast_expo(base, modulo - 2, modulo);
}
vector<pair<int, int> > dr = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                              {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
int n, m;
vector<string> M;
vector<vector<int> > inLevel, level;
queue<pair<int, int> > inQ;
bool comp(int t) {
  queue<pair<int, int> > Q = inQ;
  level = inLevel;
  while (!Q.empty()) {
    pair<int, int> cp = Q.front();
    Q.pop();
    for (pair<int, int> p : dr) {
      int i = cp.first + p.first;
      int j = cp.second + p.second;
      if (M[i][j] == 'X' and level[i][j] == -1) {
        level[i][j] = level[cp.first][cp.second] + 1;
        Q.push({i, j});
      }
    }
  }
  vector<vector<int> > tLevel(n + 2, vector<int>(m + 2, -1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (level[i][j] >= t) {
        Q.push({i, j});
        tLevel[i][j] = 0;
      }
    }
  }
  while (!Q.empty() and t) {
    pair<int, int> cp = Q.front();
    Q.pop();
    for (pair<int, int> p : dr) {
      int i = cp.first + p.first;
      int j = cp.second + p.second;
      if (tLevel[i][j] == -1) {
        tLevel[i][j] = tLevel[cp.first][cp.second] + 1;
        if (tLevel[i][j] < t) Q.push({i, j});
        if (M[i][j] == '.') return false;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (tLevel[i][j] == -1 and M[i][j] == 'X') return false;
      if (tLevel[i][j] != -1 and M[i][j] == '.') return false;
    }
  }
  return true;
}
void solve() {
  cin >> n >> m;
  M = vector<string>(n + 2, string(m + 2, '.'));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> M[i][j];
    }
  }
  inLevel = vector<vector<int> >(n + 2, vector<int>(m + 1, -1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (M[i][j] == '.') continue;
      for (pair<int, int> p : dr) {
        if (M[i + p.first][j + p.second] == '.') {
          inQ.push({i, j});
          inLevel[i][j] = 0;
          break;
        }
      }
    }
  }
  int l = 0, r = min(n, m), ans;
  while (l <= r) {
    int md = (l + r) / 2;
    if (comp(md))
      ans = md, l = md + 1;
    else
      r = md - 1;
  }
  comp(ans);
  cout << ans << '\n';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (level[i][j] >= ans)
        cout << 'X';
      else
        cout << '.';
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1, tc = 1;
  while (T--) {
    solve();
  }
  return 0;
}
