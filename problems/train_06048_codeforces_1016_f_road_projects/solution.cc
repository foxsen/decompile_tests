#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
int n, m;
vector<pair<long long, long long> > k[MAXN];
vector<long long> li;
long long di[MAXN];
long long subsz[MAXN];
long long shack[MAXN];
bool pa[MAXN];
long long pref[MAXN];
long long tp[MAXN], td[MAXN];
void pre(int v, int p = 0) {
  if (v == n) pa[v] = true;
  for (pair<long long, long long> first : k[v]) {
    long long u = first.first;
    if (u != p) {
      pre(u, v);
      if (pa[u]) pa[v] = true;
    }
  }
  if (pa[v]) li.push_back(v);
}
void dfs(int v, int p = 0) {
  subsz[v] = 1;
  di[v] = 0;
  for (pair<long long, long long> first : k[v]) {
    long long u = first.first;
    if (u != p) {
      dfs(u, v);
      subsz[v] += subsz[u];
      if (!pa[u]) di[v] = first.second;
      if (!pa[u]) shack[v] += subsz[u];
    }
  }
}
void cpref(int v, int p = 0, long long sum = 0) {
  pref[v] = sum;
  for (pair<long long, long long> first : k[v]) {
    if (first.first != p && pa[first.first])
      cpref(first.first, v, sum + first.second);
  }
}
long long find(long long l, long long r) {
  if (l == r) return 1e18;
  long long mid = (l + r) / 2;
  long long ret = 1e18;
  ret = min(ret, find(l, mid));
  ret = min(ret, find(mid + 1, r));
  long long bl = 1e18;
  long long br = 1e18;
  for (int i = l; i <= mid; i++)
    if (td[i] != 0) bl = min(bl, tp[mid] - tp[i] - td[i]);
  for (int i = mid + 1; i <= r; i++)
    if (td[i] != 0) br = min(br, tp[i] - tp[mid + 1] - td[i]);
  ret = min(ret, bl + br + tp[mid + 1] - tp[mid]);
  return ret;
}
int main() {
  scanf(" %d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    long long v, u, w;
    scanf(" %lld %lld %lld", &v, &u, &w);
    k[v].push_back(pair<long long, long long>(u, w));
    k[u].push_back(pair<long long, long long>(v, w));
  }
  pre(1);
  dfs(1);
  long long dif = 1e18;
  for (auto first : li)
    if (shack[first] > 1) dif = -1;
  long long cnt = 0;
  reverse(li.begin(), li.end());
  cpref(1);
  for (auto first : li) {
    ++cnt;
    td[cnt] = di[first];
    tp[cnt] = pref[first];
  }
  if (dif != -1) {
    for (int i = 1; i < cnt - 1; i++) dif = min(dif, tp[i + 2] - tp[i]);
    for (int i = 1; i <= cnt; i++) {
      if (td[i] != 0) {
        if (i != 1) dif = min(dif, tp[i] - tp[i - 1] - td[i]);
        if (i != cnt) dif = min(dif, tp[i + 1] - tp[i] - td[i]);
      }
    }
    dif = min(dif, find(1, cnt));
  }
  for (int i = 0; i < m; i++) {
    long long first;
    scanf(" %lld", &first);
    printf("%lld\n", min(tp[cnt], tp[cnt] - dif + first));
  }
}
