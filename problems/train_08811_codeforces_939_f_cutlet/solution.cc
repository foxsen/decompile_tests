#include <bits/stdc++.h>
using namespace std;
class MyQueue {
  vector<pair<int, int> > a1, a2;
  void clear_a1_stack() {
    while (a1.size()) {
      a2.push_back(a1.back());
      if (a2.size() > 1)
        a2.back().second = min(a2.back().first, a2[a2.size() - 2].second);
      else
        a2.back().second = a2.back().first;
      a1.pop_back();
    }
  }

 public:
  void push(int xx) {
    a1.push_back({xx, xx});
    if (a1.size() > 1)
      a1.back().second = min(a1.back().first, a1[a1.size() - 2].second);
  }
  bool is_queue_empty() {
    if (a1.size() == 0 && a2.size() == 0) return 1;
    return 0;
  }
  void pop() {
    if (!a2.size()) clear_a1_stack();
    a2.pop_back();
  }
  int get_front() {
    if (!a2.size()) clear_a1_stack();
    return a2.back().first;
  }
  long long get_min() {
    if (!a2.size()) {
      clear_a1_stack();
    }
    int mn;
    if (a1.size())
      mn = min(a1.back().second, a2.back().second);
    else
      mn = a2.back().second;
    return mn;
  }
};
MyQueue q[2];
long long dp[2][300000][2];
pair<long long, long long> a[300000];
int main() {
  long long n, k, l, r;
  long long time;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> l >> r;
    a[i] = {l, r};
    for (int j = 0; j <= 2 * n; j++)
      dp[0][j][0] = dp[0][j][1] = dp[1][j][0] = dp[1][j][1] = 1e9;
  }
  a[0] = {0, 0};
  dp[1][0][0] = 0;
  dp[1][0][1] = 0;
  int last = 0;
  int del, dist;
  int _old, _new;
  for (int i = 1; i <= k; i++) {
    del = a[i].first - a[i - 1].second;
    dist = a[i].second - a[i].first + 1;
    for (int j = 0; j <= 2 * n; j++) {
      dp[0][j][0] = dp[1][j][0];
      dp[0][j][1] = dp[1][j][1];
    }
    for (int j = 2 * n; j >= 0; j--) {
      if (j >= del)
        dp[0][j][0] = dp[0][j - del][0];
      else
        dp[0][j][0] = 1e9;
      dp[1][j][0] = dp[1][j][1] = 1e9;
    }
    while (!q[0].is_queue_empty()) q[0].pop();
    while (!q[1].is_queue_empty()) q[1].pop();
    for (int j = 0; j <= a[i].second; j++) {
      dp[1][j][1] = min(dp[1][j][1], dp[0][j][1]);
      q[0].push(dp[0][j][0]);
      q[1].push(dp[0][j][1]);
      if (j <= n) dp[1][j][0] = min(dp[1][j][0], q[1].get_min() + 1);
      if (j <= n) dp[1][j][0] = min(dp[1][j][0], q[0].get_min() + 2);
      if (j <= n) dp[1][j][1] = min(dp[1][j][1], q[0].get_min() + 1);
      if (j <= n) dp[1][j][1] = min(dp[1][j][1], q[1].get_min() + 2);
      if (j - dist + 1 >= 0) {
        dp[1][j][0] = min(dp[1][j][0], dp[0][j - dist + 1][0]);
        q[0].pop();
        q[1].pop();
      }
    }
  }
  del = 2 * n - a[k].second;
  for (int j = 2 * n; j >= 0; j--) {
    if (j >= del)
      dp[1][j][0] = dp[1][j - del][0];
    else
      dp[1][j][0] = 1e9;
  }
  long long ans = min(dp[1][n][0], dp[1][n][1]);
  if (ans == 1e9)
    cout << "Hungry" << endl;
  else {
    cout << "Full" << endl;
    cout << ans << endl;
  }
}
