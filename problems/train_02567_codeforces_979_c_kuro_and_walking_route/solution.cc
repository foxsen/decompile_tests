#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, a, b, c, d, op, mini, mij, ls, ld, ul, timp, k, maxl, rasp;
long long dp[1000005], flower[1000005], viz[1000005];
vector<int> v[1000005];
long long rez;
void go(int nod, int p) {
  if (viz[nod]) return;
  viz[nod] = 1;
  for (int i = 0; i < v[nod].size(); i++) {
    int nxt = v[nod][i];
    if (nxt == p) continue;
    go(nxt, nod);
    dp[nod] += dp[nxt];
    flower[nod] += flower[nxt];
  }
  long long total = dp[nod] + flower[nod];
  if (nod == b)
    rez += total + dp[nod];
  else
    rez += total * 2;
  for (int i = 0; i < v[nod].size(); i++) {
    int nxt = v[nod][i];
    if (nxt == p) continue;
    if (nod == b)
      rez += (total - dp[nxt] - flower[nxt]) * dp[nxt];
    else
      rez += (total - dp[nxt] - flower[nxt]) * (dp[nxt] + flower[nxt]);
  }
  dp[nod]++;
  if (nod == a) flower[nod] += dp[nod], dp[nod] = 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n >> a >> b;
  for (int i = 1; i < n; i++)
    cin >> c >> d, v[c].push_back(d), v[d].push_back(c);
  go(b, -1);
  cout << rez;
  return 0;
}
