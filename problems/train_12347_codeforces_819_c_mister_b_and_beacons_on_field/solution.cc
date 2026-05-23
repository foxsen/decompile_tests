#include <bits/stdc++.h>
using namespace std;
int t, s[3], m[3], n[3];
long long N, M;
map<int, int> factn, facts;
vector<pair<int, int> > vp;
vector<long long> gm;
long long ans;
void dfs(int ind, long long val) {
  if (ind == vp.size()) {
    ans++;
    return;
  }
  for (int i = 0; i <= vp[ind].second && val <= N; i++, val *= vp[ind].first) {
    dfs(ind + 1, val);
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    ans = 0;
    scanf("%d%d%d%d%d%d%d%d%d", n, n + 1, n + 2, m, m + 1, m + 2, s, s + 1,
          s + 2);
    M = (long long)m[0] * (long long)m[1] * (long long)m[2];
    N = (long long)n[0] * (long long)n[1] * (long long)n[2];
    factn.clear();
    facts.clear();
    facts[2] = 1;
    for (int i = 2; i <= 1000; i++) {
      for (int j = 0; j < 3; j++) {
        while (s[j] % i == 0) {
          facts[i]++;
          s[j] /= i;
        }
        while (n[j] % i == 0) {
          factn[i]++;
          n[j] /= i;
        }
      }
    }
    for (int j = 0; j < 3; j++) {
      if (s[j] > 1) {
        facts[s[j]]++;
      }
      if (n[j] > 1) {
        factn[n[j]]++;
      }
    }
    vp.clear();
    for (const auto& it : facts) {
      vp.push_back(make_pair(it.first, it.second));
    }
    dfs(0, 1);
    gm.clear();
    for (const auto& it : factn) {
      if (it.second > facts[it.first]) {
        long long temp = 1;
        for (int i = 0; i < facts[it.first] + 1; i++) {
          temp *= ((long long)it.first);
        }
        gm.push_back(temp);
      }
    }
    for (int i = 0; i < (1 << gm.size()); i++) {
      long long temp = M;
      bool flag = true;
      for (int j = 0; j < ((int)gm.size()); j++) {
        if ((i >> j) & 1) {
          temp /= gm[j];
          flag ^= 1;
        }
      }
      if (flag)
        ans += temp;
      else
        ans -= temp;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
