#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int MOD = 1000 * 1000 * 1000 + 7;
constexpr int ALPHABET_SIZE = 26;
constexpr ll INF = 1e18;
bool check(const string& s, ll k, vector<vector<ll>>& dp, vector<int>& cont,
           const string& cand, int m) {
  int n = s.length(), l = cand.length();
  if (n < l) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    int pos = i;
    while (pos < n && pos - i < l && s[pos] == cand[pos - i]) {
      ++pos;
    }
    if ((pos < n && pos - i < l && s[pos] < cand[pos - i]) ||
        (pos == n && pos - i < l)) {
      cont[i] = -1;
    } else if (pos == n || pos - i == l) {
      cont[i] = pos;
    } else {
      cont[i] = pos + 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    dp[i].assign(m, 0);
  }
  if (cont[0] != -1) {
    dp[cont[0] - 1][0] = 1;
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i + 1][j] = min(k, dp[i][j] + dp[i + 1][j]);
    }
    if (cont[i + 1] == -1) {
      continue;
    }
    for (int j = 0; j + 1 < m; ++j) {
      dp[cont[i + 1] - 1][j + 1] =
          min(k, dp[cont[i + 1] - 1][j + 1] + dp[i][j]);
    }
  }
  return dp[n - 1][m - 1] > 0 && dp[n - 1][m - 1] >= k;
}
struct TreeNode {
  int have = 0;
  int interm = 0;
  array<int, ALPHABET_SIZE> nxt{};
};
string find_in_trie(const vector<TreeNode>& trie, int ind) {
  string ans;
  int have = 0;
  int cur = 0;
  while (cur != -1) {
    if (have + trie[cur].interm > ind) {
      return ans;
    }
    have += trie[cur].interm;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
      int nxt = trie[cur].nxt[i];
      if (nxt == -1) {
        continue;
      }
      if (have + trie[nxt].have > ind) {
        ans.push_back('a' + i);
        cur = nxt;
        break;
      } else {
        have += trie[nxt].have;
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  ll k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  vector<vector<ll>> dp(n, vector<ll>(m));
  vector<int> cont(n);
  vector<TreeNode> nodes;
  nodes.emplace_back();
  nodes.back().nxt.fill(-1);
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    nodes[0].have += n - i;
    for (int j = i; j < n; ++j) {
      if (nodes[cur].nxt[s[j] - 'a'] == -1) {
        nodes[cur].nxt[s[j] - 'a'] = nodes.size();
        nodes.emplace_back();
        nodes.back().nxt.fill(-1);
      }
      cur = nodes[cur].nxt[s[j] - 'a'];
      nodes[cur].have += n - j;
      ++nodes[cur].interm;
    }
  }
  int st = 0, e = (n * n + n) / 2;
  while (e - st > 1) {
    int mid = (st + e) / 2;
    string cand = find_in_trie(nodes, mid);
    if (check(s, k, dp, cont, cand, m)) {
      st = mid;
    } else {
      e = mid;
    }
  }
  cout << find_in_trie(nodes, st) << "\n";
  return 0;
}
