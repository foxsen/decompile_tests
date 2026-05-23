#include <bits/stdc++.h>
using namespace std;
const int sigma = 10;
int main() {
  do {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  } while (false);
  string L, R;
  cin >> L >> R;
  int n, m = 0;
  cin >> n;
  reverse(L.begin(), L.end());
  L.resize(R.size(), '0');
  reverse(L.begin(), L.end());
  vector<vector<int> > son, cnt;
  auto new_node = [&]() {
    son.push_back(vector<int>(sigma, 0));
    cnt.push_back(vector<int>(max((int)R.size(), n), 0));
    return m++;
  };
  function<void(int, int, bool, bool, bool)> dfs = [&](int pos, int u, bool fl,
                                                       bool fr, bool fz) {
    if (pos >= R.size() || (fl && fr)) {
      cnt[u][R.size() - pos]++;
    } else {
      for (int i = (fl ? 0 : L[pos] - '0'); i <= (fr ? 9 : R[pos] - '0'); i++) {
        int v = u;
        bool gl = fl || (L[pos] - '0' < i), gr = fr || (R[pos] - '0' > i),
             gz = fz && !i;
        if (!gz) {
          if (!son[u][i]) {
            son[u][i] = new_node();
          }
          v = son[u][i];
        }
        dfs(pos + 1, v, gl, gr, gz);
      }
    }
  };
  dfs(0, new_node(), false, false, true);
  vector<int> fail(m);
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int i = 0; i < sigma; i++) {
      if (son[u][i]) {
        que.push(son[u][i]);
        int v = son[u][i], p = fail[u];
        while (p && !son[p][i]) {
          p = fail[p];
        }
        p = son[p][i];
        if (v != p) {
          fail[v] = p;
          for (int j = 0; j < R.size(); j++) {
            cnt[v][j] += cnt[p][j];
          }
        }
      } else {
        son[u][i] = son[fail[u]][i];
      }
    }
  }
  for (int u = 0; u < m; u++) {
    partial_sum(cnt[u].begin(), cnt[u].end(), cnt[u].begin());
  }
  vector<vector<int> > real(m, vector<int>(sigma));
  for (int u = 0; u < m; u++) {
    for (int i = 0; i < sigma; i++) {
      int v = u;
      while (v && !son[v][i]) {
        v = fail[v];
      }
      real[u][i] = son[v][i];
    }
  }
  vector<vector<int> > dp(n + 1, vector<int>(m, INT_MIN));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j] >= 0) {
        for (int c = 0; c < sigma; c++) {
          int k = real[j][c];
          dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + cnt[k][n - i - 1]);
        }
      }
    }
  }
  vector<vector<bool> > can(n + 1, vector<bool>(m));
  [&]() {
    int max_val = *max_element(dp[n].begin(), dp[n].end());
    cout << max_val << endl;
    for (int i = 0; i < m; i++) {
      if (dp[n][i] == max_val) {
        can[n][i] = true;
      }
    }
  }();
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j] >= 0) {
        for (int c = 0; c < sigma; c++) {
          int k = real[j][c];
          if (can[i + 1][k] && dp[i + 1][k] == dp[i][j] + cnt[k][n - i - 1]) {
            can[i][j] = true;
          }
        }
      }
    }
  }
  for (int i = 0, j = 0; i < n; i++) {
    for (int c = 0; c < sigma; c++) {
      int k = real[j][c];
      if (can[i + 1][k] && dp[i + 1][k] == dp[i][j] + cnt[k][n - i - 1]) {
        cout << (char)(c + '0');
        j = k;
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
