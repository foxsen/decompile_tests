#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
struct node {
  node *c[2];
  int t;
  node() {
    c[0] = c[1] = NULL;
    t = 0;
  }
} * root;
int n, k;
bool vis[N][N], dp[N][N];
string s, x;
bool can(int l, int r) {
  if (r <= l) return 1;
  if (vis[l][r]) return dp[l][r];
  vis[l][r] = 1;
  if (s[l] == s[r]) dp[l][r] = can(l + 2, r - 2);
  return dp[l][r];
}
bool solve(node *cur) {
  if (!cur) return 0;
  k -= cur->t;
  if (k <= 0) return 1;
  if (solve(cur->c[0])) {
    x += 'a';
    return 1;
  } else if (solve(cur->c[1])) {
    x += 'b';
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> k;
  n = s.size();
  root = new node();
  for (int i = 0; i < n; i++) {
    node *cur = root;
    for (int j = i; j < n; j++) {
      if (!cur->c[s[j] - 'a']) cur->c[s[j] - 'a'] = new node();
      cur = cur->c[s[j] - 'a'];
      if (can(i, j)) cur->t++;
    }
  }
  solve(root);
  reverse(x.begin(), x.end());
  cout << x;
}
