#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max((decltype(b))a, b)
#define chmin(a, b) (a) = min(a, b)

class UFTree {
  vector<int> m_parent;
  vector<int> m_height;
  vector<int> m_size;

 public:
  UFTree(int size) {
    for (int i = 0; i < size; i++) {
      m_parent.push_back(i);
      m_height.push_back(0);
      m_size.push_back(1);
    }
  }

  int root(int node) {
    if (m_parent[node] == node) {
      return node;
    }
    return m_parent[node] = root(m_parent[node]);
  }
  void merge(int n0, int n1) {
    int r0 = root(n0), r1 = root(n1);
    if (r0 == r1) {
      return;
    }
    if (m_height[r0] < m_height[r1]) swap(r0, r1);
    if (m_height[r0] == m_height[r1]) m_height[r0]++;
    m_parent[r1] = r0;
    m_size[r0] += m_size[r1];
  }
  int size(int node) { return m_size[root(node)]; }
};

int main() {
  int V;
  cin >> V;

  UFTree connectivity(V);
  int cnt = 0;
  rep(i, V) {
    string s;
    cin >> s;
    rep(j, V) {
      if (s[j] == 'Y') {
        connectivity.merge(i, j);
        cnt--;
      }
    }
  }
  cnt /= 2;

  int group = 0;
  int odd = 0;
  vector<bool> is_visited(V, false);
  rep(i, V) {
    if (!is_visited[connectivity.root(i)]) {
      is_visited[connectivity.root(i)] = true;
      const int s = connectivity.size(i);
      cnt += s * (s - 1) / 2;
      group++;
      if (s % 2 == 1) {
        odd++;
      }
    }
  }

  vector<vector<vector<bool>>> dp(
      group + 1, vector<vector<bool>>(group + 1, vector<bool>(2, false)));

  irep(j, 2) { dp[2][j][1] = true; }

  for (int i = 2; i < group; i++) {
    irep(j, i + 1) {
      rep(k, 2) {
        if (j - 2 >= 0) {
          dp[i + 1][j][k] = dp[i + 1][j][k] || !dp[i][j - 2][k];
        }
        if ((i + 1 - j >= 1 && j >= 1) || i + 1 - j >= 2) {
          dp[i + 1][j][k] = dp[i + 1][j][k] || !dp[i][j][(k + 1) % 2];
        }
      }
      dp[i + 1][j][1] = dp[i + 1][j][1] || !dp[i + 1][j][0];
    }
  }

  /*cerr << group << " " << odd << " " << cnt << "\n";
  irep(i, group) {
    irep(j, i) { cerr << "(" << dp[i][j][0] << ", " << dp[i][j][1] << ") "; }
    cerr << "\n";
  }*/

  // cerr << cnt << "\n";
  cout << (dp[group][odd][cnt % 2] ? "Taro" : "Hanako") << endl;
  return 0;
}
