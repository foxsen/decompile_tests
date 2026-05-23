#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 10;
const long long INF = 1e9 + 10;
const long long Mod = 1e9 + 7;
struct node {
  long long val, lazy;
  bool zero;
  node() {
    val = 0;
    lazy = 0;
    zero = false;
  }
};
node segt_2[4 * MAXN];
vector<pair<int, pair<int, int> > > query[MAXN];
int segt_1[4 * MAXN];
void set_update(int id, int l, int r, int p, int d) {
  if (l > p || r < p) {
    return;
  }
  if (l == r) {
    segt_1[id] = d;
    return;
  }
  int mid = (l + r) / 2;
  set_update(2 * id + 1, l, mid, p, d);
  set_update(2 * id + 2, mid + 1, r, p, d);
  segt_1[id] = min(segt_1[2 * id + 1], segt_1[2 * id + 2]);
}
int get_min(int id, int L, int R, int l, int r) {
  if (L > r || R < l) {
    return INF;
  }
  if (L >= l && R <= r) {
    return segt_1[id];
  }
  int mid = (L + R) / 2;
  return min(get_min(2 * id + 1, L, mid, l, r),
             get_min(2 * id + 2, mid + 1, R, l, r));
}
void lzu(int id) {
  if (segt_2[id].zero) {
    segt_2[2 * id + 1].val = 0;
    segt_2[2 * id + 1].lazy = 0;
    segt_2[2 * id + 2].val = 0;
    segt_2[2 * id + 2].lazy = 0;
    segt_2[2 * id + 1].zero = true;
    segt_2[2 * id + 2].zero = true;
  }
  segt_2[2 * id + 1].val += segt_2[id].lazy;
  segt_2[2 * id + 1].val %= Mod;
  segt_2[2 * id + 2].val += segt_2[id].lazy;
  segt_2[2 * id + 2].val %= Mod;
  ;
  segt_2[2 * id + 1].lazy += segt_2[id].lazy;
  segt_2[2 * id + 1].lazy %= Mod;
  segt_2[2 * id + 2].lazy += segt_2[id].lazy;
  segt_2[2 * id + 2].lazy %= Mod;
  ;
  segt_2[id].lazy = 0;
  segt_2[id].zero = false;
}
void add_update(int id, int L, int R, int l, int r, int d) {
  if (l > r || L > r || R < l) {
    return;
  }
  if (L >= l && R <= r) {
    segt_2[id].val += d;
    segt_2[id].val %= Mod;
    segt_2[id].lazy += d;
    segt_2[id].lazy %= Mod;
    return;
  }
  lzu(id);
  int mid = (L + R) / 2;
  add_update(2 * id + 1, L, mid, l, r, d);
  add_update(2 * id + 2, mid + 1, R, l, r, d);
  segt_2[id].val = segt_2[2 * id + 1].val + segt_2[2 * id + 2].val;
}
void zero_update(int id, int L, int R, int l, int r) {
  if (l > r || L > r || R < l) {
    return;
  }
  if (L >= l && R <= r) {
    segt_2[id].val = 0;
    segt_2[id].lazy = 0;
    segt_2[id].zero = true;
    return;
  }
  lzu(id);
  int mid = (L + R) / 2;
  zero_update(2 * id + 1, L, mid, l, r);
  zero_update(2 * id + 2, mid + 1, R, l, r);
  segt_2[id].val = segt_2[2 * id + 1].val + segt_2[2 * id + 2].val;
}
long long get_res(int id, int l, int r, int p) {
  if (l > p || r < p) {
    return 0;
  }
  if (l == r) {
    return segt_2[id].val;
  }
  lzu(id);
  long long mid = (l + r) / 2;
  return get_res(2 * id + 1, l, mid, p) + get_res(2 * id + 2, mid + 1, r, p);
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    query[x1].push_back(make_pair(1LL, make_pair(y1, y2)));
    query[x2 + 1].push_back(make_pair(0LL, make_pair(y1, y2)));
  }
  set_update(0, 0, m + 1, m + 1, m + 1);
  for (long long i = 0; i <= m; i++) {
    set_update(0, 0, m + 1, i, INF);
  }
  for (int i = 1; i <= n; i++) {
    sort(query[i].begin(), query[i].end());
    for (int j = 0; j < query[i].size(); j++) {
      if (query[i][j].first) {
        set_update(0, 0, m + 1, query[i][j].second.second,
                   query[i][j].second.first);
      } else {
        set_update(0, 0, m + 1, query[i][j].second.second, INF);
      }
    }
    if (i == 1) {
      add_update(0, 0, m + 1, 1, get_min(0, 0, m + 1, 0, m + 1) - 1, 1);
    }
    for (int j = (int)(query[i].size()) - 1; j >= 0; j--) {
      if (query[i][j].first) {
        zero_update(0, 0, m + 1, query[i][j].second.first,
                    query[i][j].second.second);
      } else {
        add_update(
            0, 0, m + 1, query[i][j].second.first,
            get_min(0, 0, m + 1, query[i][j].second.first - 1, m + 1) - 1,
            get_res(0, 0, m + 1, query[i][j].second.first - 1));
      }
    }
  }
  cout << get_res(0, 0, m + 1, m);
}
