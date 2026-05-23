#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long add(long long a, long long b) {
  long long res = a + b;
  return res >= mod ? res - mod : res;
}
long long mul(long long a, long long b) { return a * b % mod; }
vector<vector<long long>> matmul(const vector<vector<long long>>& a,
                                 const vector<vector<long long>>& b) {
  int n = ((int)(a).size()), m = ((int)(b).size()), o = ((int)(b[0]).size());
  vector<vector<long long>> ans(n, vector<long long>(o));
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (o); j++)
      for (int k = (0); k < (m); k++)
        ans[i][j] = add(ans[i][j], mul(a[i][k], b[k][j]));
  return ans;
}
vector<vector<long long>> powmod(vector<vector<long long>> a, long long b) {
  assert(b >= 0);
  int n = ((int)(a).size());
  vector<vector<long long>> ans(n, vector<long long>(n));
  for (int i = (0); i < (n); i++) ans[i][i] = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = matmul(ans, a);
    a = matmul(a, a);
  }
  return ans;
}
vector<pair<long long, pair<int, int>>> event;
int cnt[4];
int n;
long long m;
int main() {
  scanf("%d%lld", &n, &m);
  for (int i = (0); i < (n); i++) {
    long long l, r;
    int a;
    scanf("%d%lld%lld", &a, &l, &r);
    a--;
    l--;
    event.push_back(make_pair(l, make_pair(0, a)));
    event.push_back(make_pair(r, make_pair(1, a)));
  }
  event.push_back(make_pair(1, make_pair(0, 3)));
  event.push_back(make_pair(m, make_pair(1, 3)));
  sort((event).begin(), (event).end());
  vector<vector<long long>> cur = {{0}, {1}, {0}};
  for (int i = 0; i < (((int)(event).size()) - 1); i++) {
    int t = event[i].second.first, of = event[i].second.second;
    if (t == 0)
      cnt[of]++;
    else
      cnt[of]--;
    vector<vector<long long>> now(3, vector<long long>(3));
    if (cnt[0] == 0) now[0] = {1, 1, 0};
    if (cnt[1] == 0) now[1] = {1, 1, 1};
    if (cnt[2] == 0) now[2] = {0, 1, 1};
    long long len = event[i + 1].first - event[i].first;
    cur = matmul(powmod(now, len), cur);
  }
  printf("%lld", cur[1][0]);
}
