#include <bits/stdc++.h>
using namespace std;
int power(int a, int n, int mod) {
  int res;
  if (n == 0) return 1;
  res = power(a, n / 2, mod);
  res = (int)((long long)res * (long long)res % mod);
  if (n % 2) res = (int)((long long)res * (long long)a % mod);
  return res;
}
int in, tot, root, size[110000], value[110000], n, yy, k, xx, id1, id2,
    ex[110000], mod, dist[110000];
int yes[110000], no[110000], rev[110000], inf = 1100000000;
long long one[2][110000], ans;
bool vis[110000], is_first;
struct pp {
  int id, v1, v2, deep, v3, now_v;
  long long msize;
  long long tsum[2];
  bool operator<(const pp &temp) const { return v3 < temp.v3; }
};
vector<pp> anc[110000];
pp lst[110000];
int cnt_list;
vector<int> adj[110000];
int lower_bound(int root, int left, int right, pp now) {
  int mid;
  while (left <= right) {
    mid = (left + right) >> 1;
    if (anc[root][mid] < now)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return left;
}
int upper_bound(int root, int left, int right, pp now) {
  int mid;
  while (left <= right) {
    mid = (left + right) >> 1;
    if (now < anc[root][mid])
      right = mid - 1;
    else
      left = mid + 1;
  }
  return right;
}
void dl_data(int root, int flag) {
  int i, j, s, p, q, siz, lo, hi, temp;
  long long sum, ptot = 0, same = 0, tnt = 0, tot_no = 0, tot = 0;
  pp now;
  if (root < 0) return;
  siz = anc[root].size();
  for (i = 0; i < siz; i++) {
    temp = ((xx - anc[root][i].v1) % mod + mod) % mod;
    temp = (int)((long long)temp * (long long)rev[anc[root][i].deep] % mod);
    anc[root][i].v3 = temp;
  }
  sort(anc[root].begin(), anc[root].end());
  sum = tot = 0;
  for (i = 0; i < siz; i++) {
    sum += one[0][anc[root][i].id];
    tot += one[1][anc[root][i].id];
    anc[root][i].tsum[0] = one[0][anc[root][i].id];
    anc[root][i].tsum[1] = one[1][anc[root][i].id];
    if (i > 0) {
      anc[root][i].tsum[0] += anc[root][i - 1].tsum[0];
      anc[root][i].tsum[1] += anc[root][i - 1].tsum[1];
    }
  }
  for (i = 0; i < siz; i++) {
    now.v3 = (anc[root][i].v2 - anc[root][i].now_v) % mod;
    if (now.v3 < 0) now.v3 += mod;
    lo = lower_bound(root, 0, siz - 1, now);
    hi = upper_bound(root, 0, siz - 1, now);
    long long ns = 0;
    tot_no += sum + tot;
    if (lo <= hi) {
      ns += anc[root][hi].tsum[0];
      if (lo > 0) ns -= anc[root][lo - 1].tsum[0];
      ns += anc[root][hi].tsum[1];
      if (lo > 0) ns -= anc[root][lo - 1].tsum[1];
      tot_no -= ns;
    }
  }
  ans += flag * (-tot_no + (long long)siz * (long long)sum);
}
void deal_data(int root, int flag, bool ff) {
  int temp, i, j, s, p, q, siz, lo, hi;
  pp now;
  if (root < 0) return;
  siz = anc[root].size();
  for (i = 0; i < siz; i++) {
    temp = ((xx - anc[root][i].v1) % mod + mod) % mod;
    temp = (int)((long long)temp * (long long)rev[anc[root][i].deep] % mod);
    anc[root][i].v3 = temp;
  }
  for (j = 0; j < 2; j++) {
    if (j == 1) {
      for (i = 0; i < siz; i++) {
        temp = (anc[root][i].v2 - anc[root][i].now_v) % mod;
        if (temp < 0) temp += mod;
        anc[root][i].v3 = temp;
        temp = (int)((long long)(xx - anc[root][i].v1) *
                     (long long)rev[anc[root][i].deep] % mod);
        if (temp < 0) temp += mod;
      }
    }
    sort(anc[root].begin(), anc[root].end());
    for (i = 0; i < siz; i++) {
      if (j == 0) {
        now.v3 = (anc[root][i].v2 - anc[root][i].now_v) % mod;
        if (now.v3 < 0) now.v3 += mod;
      } else {
        now.v3 = (int)((long long)(xx - anc[root][i].v1) *
                       (long long)rev[anc[root][i].deep] % mod);
        if (now.v3 < 0) now.v3 += mod;
      }
      lo = lower_bound(root, 0, siz - 1, now);
      hi = upper_bound(root, 0, siz - 1, now);
      int dnt = hi - lo + 1;
      one[j][anc[root][i].id] += flag * dnt;
    }
  }
}
void get_data(int root, int id1, int id2, int vv1, int vv2, int deep) {
  int id, i, j, s, p, q, siz = adj[id1].size(), nv1, nv2;
  pp now;
  now.id = id1;
  now.v1 = vv1;
  now.v2 = vv2;
  now.now_v = value[root];
  now.deep = deep;
  anc[root].push_back(now);
  for (i = 0; i < siz; i++) {
    id = adj[id1][i];
    if (id == id2 || vis[id]) continue;
    nv1 = (int)((long long)vv1 * (long long)k % mod);
    nv1 = (nv1 + value[id]) % mod;
    nv2 = (int)((long long)ex[deep + 1] * (long long)value[id] % mod);
    nv2 = (nv2 + vv2) % mod;
    get_data(root, id, id1, nv1, nv2, deep + 1);
  }
}
void get_size(int id1, int id2) {
  int rt, id, i, j, s, p, q, siz = adj[id1].size();
  size[id1] = 1;
  for (i = 0; i < siz; i++) {
    id = adj[id1][i];
    if (id == id2 || vis[id]) continue;
    get_size(id, id1);
    size[id1] += size[id];
  }
}
void choose_root(int id1, int id2) {
  int ax = tot - size[id1], id, i, j, s, p, q, siz = adj[id1].size();
  for (i = 0; i < siz; i++) {
    id = adj[id1][i];
    if (id == id2 || vis[id]) continue;
    choose_root(id, id1);
    ax = max(ax, size[id]);
  }
  if (in > ax) {
    in = ax;
    root = id1;
  }
}
void fir_dfs(int id1, int id2) {
  int id, i, j, s, p, q, siz = adj[id1].size();
  vector<pp> pt;
  vis[id1] = true;
  get_data(id1, id1, -1, value[id1], value[id1], 0);
  if (!is_first) {
    pt.clear();
    for (i = 0; i < anc[id1].size(); i++) {
      pt.push_back(anc[id1][i]);
      anc[id1][i] = lst[anc[id1][i].id];
    }
    deal_data(id1, -1, 0);
    for (i = 0; i < anc[id1].size(); i++) anc[id1][i] = pt[i];
  }
  deal_data(id1, 1, 0);
  is_first = false;
  for (i = 0; i < anc[id1].size(); i++) {
    id = anc[id1][i].id;
    lst[id] = anc[id1][i];
  }
  for (i = 0; i < siz; i++) {
    id = adj[id1][i];
    if (vis[id]) continue;
    get_size(id, -1);
    tot = size[id];
    in = inf;
    choose_root(id, -1);
    fir_dfs(root, -1);
  }
}
void sec_dfs(int id1, int id2) {
  int i, j, s, p, q, siz = adj[id1].size(), id;
  vector<pp> pt;
  vis[id1] = true;
  if (!is_first) {
    pt.clear();
    for (i = 0; i < anc[id1].size(); i++) {
      pt.push_back(anc[id1][i]);
      anc[id1][i] = lst[anc[id1][i].id];
    }
    dl_data(id1, -1);
    for (i = 0; i < anc[id1].size(); i++) anc[id1][i] = pt[i];
  }
  dl_data(id1, 1);
  for (i = 0; i < anc[id1].size(); i++) lst[anc[id1][i].id] = anc[id1][i];
  is_first = false;
  for (i = 0; i < siz; i++) {
    id = adj[id1][i];
    if (vis[id]) continue;
    get_size(id, -1);
    tot = size[id];
    in = inf;
    choose_root(id, -1);
    sec_dfs(root, -1);
  }
}
int main() {
  int i, j, s, p, q, id;
  scanf("%d%d%d%d", &n, &yy, &k, &xx);
  mod = yy;
  for (i = 0; i < n; i++) {
    scanf("%d", &value[i]);
    adj[i].clear();
  }
  ex[0] = 1;
  rev[0] = 1;
  for (i = 1; i <= n; i++) {
    ex[i] = (int)((long long)ex[i - 1] * (long long)k % mod);
    rev[i] = power(ex[i], mod - 2, mod);
  }
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &id1, &id2);
    id1--;
    id2--;
    adj[id1].push_back(id2);
    adj[id2].push_back(id1);
  }
  for (i = 0; i < n; i++) anc[i].clear();
  memset(vis, false, sizeof(vis));
  get_size(0, -1);
  tot = size[0];
  in = inf;
  choose_root(0, -1);
  memset(one, 0, sizeof(one));
  for (i = 0; i < n; i++) lst[i].id = i;
  is_first = true;
  ans = 0;
  fir_dfs(root, -1);
  memset(vis, false, sizeof(vis));
  get_size(0, -1);
  tot = size[0];
  in = inf;
  choose_root(0, -1);
  ans = 0;
  is_first = true;
  sec_dfs(root, -1);
  for (i = 0; i < n; i++) ans += (n - one[0][i]) * (n - one[0][i]);
  printf("%I64d\n", ans);
  return 0;
}
