#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2005;
const long long INF = 1e9 + 5;
char grid[MAX][MAX];
long long dp[MAX][MAX];
auto solve(long long n, long long k) -> string {
  auto inside = [&](long long row, long long col) {
    return (row < n and row >= 0 and col < n and col >= 0);
  };
  for (long long row = 0; row < n; ++row) {
    for (long long col = 0; col < n; ++col) {
      dp[row][col] = INF;
    }
  }
  dp[0][0] = (grid[0][0] != 'a') ? 1 : 0;
  for (long long row = 0; row < n; ++row) {
    for (long long col = 0; col < n; ++col) {
      if (row == 0 and col == 0) continue;
      if ((row != 0) and (col != 0)) {
        dp[row][col] =
            min(dp[row][col - 1], dp[row - 1][col]) + (grid[row][col] != 'a');
      } else {
        dp[row][col] = (row == 0) ? dp[row][col - 1] + (grid[row][col] != 'a')
                                  : dp[row][col];
        dp[row][col] = (col == 0) ? dp[row - 1][col] + (grid[row][col] != 'a')
                                  : dp[row][col];
      }
    }
  }
  long long pref = 0;
  for (long long row = 0; row < n; ++row) {
    for (long long col = 0; col < n; ++col) {
      if (dp[row][col] <= k) {
        pref = max(pref, row + col + 1);
      }
    }
  }
  string answer(pref, 'a');
  vector<pair<long long, long long>> list;
  for (long long row = 0; row < n; ++row) {
    for (long long col = 0; col < n; ++col) {
      if ((dp[row][col] <= k) and (pref == row + col + 1)) {
        list.push_back(make_pair(row, col));
      }
    }
  }
  if (list.empty()) {
    answer = grid[0][0];
    list.emplace_back(0, 0);
  }
  while (!list.empty()) {
    char best_char = 'z' + 1;
    vector<pair<long long, long long>> new_list;
    for (pair<long long, long long> p : list) {
      for (long long d_row : {0, 1}) {
        long long d_col = 1 - d_row;
        long long r2 = p.first + d_row;
        long long c2 = p.second + d_col;
        if (inside(r2, c2)) {
          if (grid[r2][c2] <= best_char) {
            if (grid[r2][c2] < best_char) {
              new_list.clear();
            }
            best_char = grid[r2][c2];
            new_list.push_back(make_pair(r2, c2));
          }
        }
      }
    }
    new_list.resize(std::unique(new_list.begin(), new_list.end()) -
                    new_list.begin());
    list = new_list;
    if (best_char != 'z' + 1) answer = answer + best_char;
  }
  return answer;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  std::cin >> n >> k;
  for (long long i = 0; i < n; ++i) {
    std::cin >> grid[i];
  }
  std::cout << solve(n, k);
  return 0;
}
