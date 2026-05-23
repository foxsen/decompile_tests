#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 1000000;
int n;
long long skill;
long long a[MAXN];
int cost[MAXN];
vector<long long> p;
long long b[MAXN];
long long c[MAXN];
int nc;
vector<int> copt[MAXN];
pair<int, int> ord[MAXN];
vector<int> freq;
vector<pair<int, vector<int>>> opt;
vector<vector<long long>> dp;
void addopt(vector<int> &myopt, vector<long long> &myneed, long long prod,
            int mask, int at) {
  if (at >= ((int)(myneed).size())) {
    bool ok = true;
    for (int i = (0); i < (((int)(myneed).size())); ++i)
      if ((mask & (1 << i)) == 0 && prod * myneed[i] <= skill) ok = false;
    if (ok && mask != 0) myopt.push_back(mask);
    return;
  }
  addopt(myopt, myneed, prod, mask, at + 1);
  if (prod * myneed[at] <= skill)
    addopt(myopt, myneed, prod * myneed[at], mask | (1 << at), at + 1);
}
long long solve() {
  long long g = 0;
  for (int i = (0); i < (n); ++i) g = gcd(g, a[i]);
  {
    p.clear();
    long long x = g;
    for (int i = 2; (long long)i * i <= x; ++i)
      if (x % i == 0) {
        p.push_back(i);
        while (x % i == 0) x /= i;
      }
    if (x != 1) p.push_back(x);
  }
  for (int i = (0); i < (n); ++i) {
    long long x = a[i];
    for (int j = (0); j < (((int)(p).size())); ++j)
      while (x % p[j] == 0) x /= p[j];
    b[i] = a[i] / x;
  }
  nc = 0;
  for (int i = (0); i < (n); ++i) c[nc++] = b[i];
  sort(c, c + nc);
  nc = unique(c, c + nc) - c;
  for (int i = (0); i < (nc); ++i) {
    vector<long long> need(((int)(p).size()));
    for (int j = (0); j < (((int)(p).size())); ++j) {
      long long x = c[i];
      while (x % p[j] == 0) x /= p[j];
      need[j] = c[i] / x;
    }
    copt[i].clear();
    addopt(copt[i], need, 1, 0, 0);
  }
  freq = vector<int>(1 << ((int)(p).size()), 0);
  opt.clear();
  for (int i = (0); i < (n); ++i) ord[i] = make_pair(cost[i], i);
  sort(ord, ord + n);
  for (int i = (0); i < (n); ++i) {
    int at = ord[i].second;
    int idx = lower_bound(c, c + nc, b[at]) - c;
    bool any = false;
    for (int j = (0); j < (((int)(copt[idx]).size())); ++j)
      if (freq[copt[idx][j]] < ((int)(p).size())) any = true;
    if (!any) continue;
    vector<int> masks;
    for (int j = (0); j < (((int)(copt[idx]).size())); ++j)
      if (freq[copt[idx][j]] < ((int)(p).size())) {
        masks.push_back(copt[idx][j]);
        ++freq[copt[idx][j]];
      }
    opt.push_back(make_pair(cost[at], masks));
  }
  dp = vector<vector<long long>>(
      ((int)(p).size()) + 1,
      vector<long long>(1 << ((int)(p).size()), LLONG_MAX));
  dp[0][0] = 0;
  for (int i = (0); i < (((int)(opt).size())); ++i) {
    for (int cnt = ((int)(p).size()) - 1; cnt >= 0; --cnt)
      for (int mask = (0); mask < (1 << ((int)(p).size())); ++mask)
        if (dp[cnt][mask] != LLONG_MAX) {
          for (int j = (0); j < (((int)(opt[i].second).size())); ++j) {
            int ncnt = cnt + 1, nmask = mask | opt[i].second[j];
            long long ncost = dp[cnt][mask] + opt[i].first;
            dp[ncnt][nmask] = min(dp[ncnt][nmask], ncost);
          }
        }
  }
  long long ret = LLONG_MAX;
  for (int cnt = (0); cnt <= (((int)(p).size())); ++cnt)
    if (dp[cnt][(1 << ((int)(p).size())) - 1] != LLONG_MAX)
      ret = min(ret, cnt * dp[cnt][(1 << ((int)(p).size())) - 1]);
  return ret == LLONG_MAX ? -1 : ret;
}
void run() {
  scanf("%d%lld", &n, &skill);
  for (int i = (0); i < (n); ++i) scanf("%lld", &a[i]);
  for (int i = (0); i < (n); ++i) scanf("%d", &cost[i]);
  printf("%lld\n", solve());
}
int main() {
  run();
  return 0;
}
