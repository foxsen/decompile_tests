#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100;
const int P = 998244353;
const int md = 1e9 + 7;
double getTime() { return clock() / (double)CLOCKS_PER_SEC; };
int state[maxN][maxN][maxN];
int di[4] = {0, 0, 1};
int dj[4] = {0, 1, 0};
int de[4] = {1, 0, 0};
int n, m, k;
bool check(int &i, int &j, int &e) {
  return !(i < 0 || i >= n || j < 0 || j >= m || e < 0 || e >= k);
}
bool check_path(int &i, int &j, int &e, int &fi, int &fj, int &fe) {
  if (!check(i, j, e) || !check(fi, fj, fe)) return false;
  if (i > fi || j > fj || e > fe) return false;
  if (state[i][j][e] == 0) return false;
  if (i == fi && j == fj && e == fe) return true;
  for (int t = 0; (t) < 3; ++(t)) {
    int new_i = i + di[t];
    int new_j = j + dj[t];
    int new_e = e + de[t];
    if (check_path(new_i, new_j, new_e, fi, fj, fe)) return true;
  }
  return false;
}
int ans = 0;
int checked(int &i, int &j, int &e) {
  if (state[i][j][e] == 0) return 0;
  for (int t1 = 0; (t1) < 3; ++(t1)) {
    for (int t2 = 0; (t2) < 3; ++(t2)) {
      int i_start = i - di[t1];
      int j_start = j - dj[t1];
      int e_start = e - de[t1];
      int i_finish = i + di[t2];
      int j_finish = j + dj[t2];
      int e_finish = e + de[t2];
      if (check_path(i_start, j_start, e_start, i_finish, j_finish, e_finish)) {
        state[i][j][e] = 0;
        if (!check_path(i_start, j_start, e_start, i_finish, j_finish,
                        e_finish)) {
          state[i][j][e] = 1;
          return 1;
        }
        state[i][j][e] = 1;
      }
    }
  }
  return 0;
}
void solve() {
  cin >> n >> m >> k;
  for (int i = 0; (i) < n; ++(i)) {
    for (int j = 0; (j) < m; ++(j)) {
      for (int e = 0; (e) < k; ++(e)) {
        char a;
        cin >> a;
        state[i][j][e] = a - '0';
      }
    }
  }
  for (int i = 0; (i) < n; ++(i)) {
    for (int j = 0; (j) < m; ++(j)) {
      for (int e = 0; (e) < k; ++(e)) {
        ans += checked(i, j, e);
      }
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tests = 1;
  for (int _ = 0; (_) < tests; ++(_)) {
    solve();
  }
  return 0;
}
