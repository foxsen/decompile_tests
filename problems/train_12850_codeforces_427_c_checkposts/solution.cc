#include <bits/stdc++.h>
long long power(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
using namespace std;
vector<int> adj1[100001];
vector<int> adj2[100001];
bool visit[100001];
stack<int> st;
void dfs1(int node) {
  visit[node] = true;
  for (vector<int>::iterator it = adj1[node].begin(); it < adj1[node].end();
       it++) {
    if (!visit[*it]) {
      dfs1(*it);
    }
  }
  st.push(node);
}
vector<int> c1;
void dfs2(int node) {
  visit[node] = true;
  c1.push_back(node);
  for (vector<int>::iterator it = adj2[node].begin(); it < adj2[node].end();
       it++) {
    if (!visit[*it]) {
      dfs2(*it);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, j, t, x, y, k, z, m, sum, p, q, r, arr[100001], a, c, flag,
      dp[100001];
  long long ans, cnt;
  char ch;
  cnt = 0;
  string s;
  cin >> n;
  vector<int>::iterator it;
  for (i = 0; i < n; i++) cin >> arr[i];
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    adj1[x].push_back(y);
    adj2[y].push_back(x);
  }
  for (i = 0; i < n; i++) visit[i] = false;
  while (!st.empty()) st.pop();
  for (i = 0; i < n; i++) {
    if (!visit[i]) dfs1(i);
  }
  for (i = 0; i < n; i++) visit[i] = false;
  ans = 0;
  cnt = 1;
  while (!st.empty()) {
    if (!visit[st.top()]) {
      c1.clear();
      dfs2(st.top());
      t = c1.size();
      for (i = 0; i < t; i++) {
        c1[i] = arr[c1[i]];
      }
      sort(c1.begin(), c1.end());
      ans += c1[0];
      for (i = 1; i < t; i++) {
        if (c1[i] != c1[i - 1]) break;
      }
      cnt *= i;
      cnt = cnt % 1000000007;
    }
    st.pop();
  }
  cout << ans << " " << cnt;
  return 0;
}
