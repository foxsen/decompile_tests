#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long large = 1100000000000000000LL;
long long dp[1000010];
int n;
long long k;
const int max_sz = 2000010;
int sz = 0;
int ch[max_sz][2], range[max_sz][2];
void build(int u, int len) {
  int l = range[u][0];
  int r = range[u][1];
  int m = l - 1;
  for (int i = l; i <= r; i++) {
    if ((dp[i] & (1LL << len))) {
    } else {
      m = i;
    }
  }
  if (l <= m) {
    sz++;
    ch[sz - 1][0] = ch[sz - 1][1] = -1;
    range[sz - 1][0] = l;
    range[sz - 1][1] = m;
    ch[u][0] = sz - 1;
  }
  if (m + 1 <= r) {
    sz++;
    ch[sz - 1][0] = ch[sz - 1][1] = -1;
    range[sz - 1][0] = m + 1;
    range[sz - 1][1] = r;
    ch[u][1] = sz - 1;
  }
}
pair<long long, long long> get(int u, int len) {
  long long u0 = 0, u1 = 0;
  if (ch[u][0] != -1) {
    u0 = range[ch[u][0]][1] - range[ch[u][0]][0] + 1;
  }
  if (ch[u][1] != -1) {
    u1 = range[ch[u][1]][1] - range[ch[u][1]][0] + 1;
  }
  return pair<long long, long long>(u0, u1);
}
int get_ch(int u, int len, long long c) {
  int re = ch[u][c];
  if (re >= n) re -= n;
  return re;
}
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i < n; i++) {
    int x;
    long long y;
    scanf("%d%lld", &x, &y);
    x--;
    dp[i] = dp[x] ^ y;
  }
  sort(dp, dp + n);
  ch[0][0] = ch[0][1] = -1;
  range[0][0] = 0;
  range[0][1] = n - 1;
  sz = 1;
  vector<pair<int, int> > pre;
  vector<pair<int, int> > cur;
  pre.push_back(pair<int, int>(0, 0));
  for (int len = 62; len >= 0; len--) {
    int cc = sz;
    sz = n;
    for (int i = 0; i < cc; i++) {
      build(i, len);
    }
    cur.clear();
    long long c0 = 0;
    for (int j = 0; j < (int)pre.size(); j++) {
      int u = pre[j].first;
      int v = pre[j].second;
      if (u == -1 || v == -1) continue;
      pair<long long, long long> uu = get(u, len);
      pair<long long, long long> vv = get(v, len);
      c0 += uu.first * vv.first + uu.second * vv.second;
    }
    if (c0 >= k) {
      for (int j = 0; j < (int)pre.size(); j++) {
        int u = pre[j].first;
        int v = pre[j].second;
        if (u == -1 || v == -1) continue;
        int x = get_ch(u, len, 0);
        int y = get_ch(v, len, 0);
        if (x != -1 && y != -1) cur.push_back(pair<int, int>(x, y));
        x = get_ch(u, len, 1);
        y = get_ch(v, len, 1);
        if (x != -1 && y != -1) cur.push_back(pair<int, int>(x, y));
      }
    } else {
      k -= c0;
      for (int j = 0; j < (int)pre.size(); j++) {
        int u = pre[j].first;
        int v = pre[j].second;
        if (u == -1 || v == -1) continue;
        int x = get_ch(u, len, 0);
        int y = get_ch(v, len, 1);
        if (x != -1 && y != -1) cur.push_back(pair<int, int>(x, y));
        x = get_ch(u, len, 1);
        y = get_ch(v, len, 0);
        if (x != -1 && y != -1) cur.push_back(pair<int, int>(x, y));
      }
    }
    sz -= n;
    for (int i = 0; i < sz; i++) {
      ch[i][0] = ch[i + n][0];
      ch[i][1] = ch[i + n][1];
      range[i][0] = range[i + n][0];
      range[i][1] = range[i + n][1];
    }
    pre = cur;
  }
  for (int j = 0; j < (int)cur.size(); j++) {
    int u = cur[j].first;
    int v = cur[j].second;
    if (u == -1 || v == -1) continue;
    u = range[u][0];
    v = range[v][0];
    cout << (dp[u] ^ dp[v]) << endl;
    return 0;
  }
  return 0;
}
