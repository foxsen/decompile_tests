#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
vector<long long> dp;
long long sum(int r) {
  long long res = 0;
  for (; r > 0; r -= r & -r) {
    res += dp[r];
    res %= mod;
  }
  return res;
}
long long sum(int l, int r) { return ((sum(r) - sum(l - 1)) + mod) % mod; }
void add(int k, int x) {
  for (; k <= dp.size(); k += k & -k) {
    dp[k] += x;
    dp[k] %= mod;
  }
}
int main() {
  long long n;
  cin >> n;
  vector<long long> v(2 * n + 1);
  vector<long long> v2(2 * n + 1);
  vector<pair<long long, long long> > ab1(n + 1);
  for (long long i = 1; i <= n; i++) {
    long long a, b;
    cin >> a >> b;
    ab1[i] = {a, b};
    v[b] = a;
    v2[a] = b;
  }
  long long t;
  cin >> t;
  vector<long long> tt(t);
  deque<long long> bs;
  map<long long, bool> mp;
  long long m = 0;
  for (long long &i : tt) {
    cin >> i;
    bs.push_back(ab1[i].second);
    m = max(m, ab1[i].second);
    mp[ab1[i].first] = true;
  }
  sort((bs).begin(), (bs).end());
  map<long long, long long> bb;
  for (long long i = 0; i < bs.size(); i++) {
    bb[v[bs[i]]] = i;
  }
  dp = vector<long long>(m + 1);
  for (long long i = 1; i <= m; i++) {
    if (v[i] != 0) {
      add(v[i], (sum(v[i], i) + 1) % mod);
    }
  }
  long long answer = 0;
  long long bi = bs.size() - 1;
  for (long long i = 1; i <= m; i++) {
    while (bs[bi] == 0 && bi > 0) bi--;
    if (bs[bi] == 0 && bi == -1) break;
    if (sum(i, i) != 0 && bs[bi] >= v2[i]) {
      answer += sum(i, i);
      answer %= mod;
    }
    if (mp[i]) {
      bs[bb[i]] = 0;
    }
  }
  cout << answer << "\n";
  return 0;
}
