#include <bits/stdc++.h>
using namespace std;
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
const int sq = 225;
int ar[tam];
int res[tam];
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first / sq == b.first.first / sq)
    return a.first.second < b.first.second;
  return a.first.first / sq < b.first.first / sq;
}
struct trie {
  int maxo, mino, nam;
  trie* ce;
  trie* un;
  trie() {
    ce = un = NULL;
    maxo = 0;
    mino = MOD;
  }
};
typedef trie* ptrie;
void del(ptrie t) {
  if (t) {
    del(t->ce);
    del(t->un);
    delete t;
  }
}
void add(string& second, int ind, int num, ptrie t, int nam) {
  if (ind < second.size()) {
    ptrie go;
    if (second[ind] == '0') {
      if (t->ce == NULL) t->ce = new trie();
      go = t->ce;
    } else {
      if (t->un == NULL) t->un = new trie();
      go = t->un;
    }
    add(second, ind + 1, num, go, nam);
  } else
    t->nam = nam;
  t->maxo = max(max(t->ce ? t->ce->maxo : 0, t->un ? t->un->maxo : 0), num);
  t->mino = min(min(t->ce ? t->ce->mino : MOD, t->un ? t->un->mino : MOD), num);
}
int ask1(string& second, int ind, int num, ptrie t) {
  if (ind == second.size()) return t->nam;
  ptrie go;
  if (second[ind] == '0') {
    if (t->un != NULL && t->un->maxo > num)
      go = t->un;
    else if (t->ce != NULL && t->ce->maxo > num)
      go = t->ce;
    else
      return -1;
  } else {
    if (t->ce != NULL && t->ce->maxo > num)
      go = t->ce;
    else if (t->un != NULL && t->un->maxo > num)
      go = t->un;
    else
      return -1;
  }
  return ask1(second, ind + 1, num, go);
}
int ask2(string& second, int ind, int num, ptrie t) {
  if (ind == second.size()) return t->nam;
  ptrie go;
  if (second[ind] == '0') {
    if (t->un != NULL && t->un->mino < num)
      go = t->un;
    else if (t->ce != NULL && t->ce->mino < num)
      go = t->ce;
    else
      return -1;
  } else {
    if (t->ce != NULL && t->ce->mino < num)
      go = t->ce;
    else if (t->un != NULL && t->un->mino < num)
      go = t->un;
    else
      return -1;
  }
  return ask2(second, ind + 1, num, go);
}
string tost(int n) {
  string res = "";
  while (n > 0) {
    res += (n % 2) + '0';
    n /= 2;
  }
  while (res.size() < 22) res += '0';
  reverse((res).begin(), (res).end());
  return res;
}
int xo[1000010];
int ros[tam];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i < 1000010; i++) xo[i] = xo[i - 1] ^ i;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> ar[i];
  int a, b;
  vector<pair<pair<int, int>, int>> que;
  ptrie t1 = 0, t2 = 0;
  int ras;
  string s1, s2;
  int x, y, x1, y1;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    if (b - a < sq) {
      del(t1);
      del(t2);
      t1 = new trie();
      t2 = new trie();
      ras = 0;
      for (int i = a; i < b + 1; i++) {
        x = ar[i] - 1;
        y = ar[i];
        s1 = tost(xo[x]);
        s2 = tost(xo[y]);
        add(s1, 0, x, t2, xo[x]);
        add(s2, 0, y, t1, xo[y]);
        x1 = ask1(s1, 0, x, t1);
        y1 = ask2(s2, 0, y, t2);
        ras = max(ras,
                  max(xo[x] ^ ask1(s1, 0, x, t1), xo[y] ^ ask2(s2, 0, y, t2)));
      }
      res[i] = ras;
    } else
      que.push_back({{a, b}, i});
  }
  sort((que).begin(), (que).end(), comp);
  int level = 0;
  int nu = sq;
  while (nu <= n) {
    for (int i = nu - 1; i > nu - sq - 1; i--) {
      ros[i] = ros[i + 1];
      for (int j = i; j < nu; j++)
        ros[i] = max(ros[i], ar[i] > ar[j] ? xo[ar[i]] ^ xo[ar[j] - 1]
                                           : xo[ar[i] - 1] ^ xo[ar[j]]);
    }
    nu += sq;
  }
  int divo = -1, lasto = -1, rus;
  for (int i = 0; i < que.size(); i++) {
    if (que[i].first.first / sq != divo) {
      divo = que[i].first.first / sq;
      lasto = que[i].first.first / sq * sq + sq;
      del(t1);
      del(t2);
      t1 = new trie();
      t2 = new trie();
      ras = 0;
    }
    while (que[i].first.second >= lasto) {
      x = ar[lasto] - 1;
      y = ar[lasto];
      s1 = tost(xo[x]);
      s2 = tost(xo[y]);
      add(s1, 0, x, t2, xo[x]);
      add(s2, 0, y, t1, xo[y]);
      ras =
          max(ras, max(xo[x] ^ ask1(s1, 0, x, t1), xo[y] ^ ask2(s2, 0, y, t2)));
      lasto++;
    }
    rus = ros[que[i].first.first];
    for (int j = que[i].first.first; j < que[i].first.first / sq * sq + sq;
         j++) {
      x = ar[j] - 1;
      y = ar[j];
      s1 = tost(xo[x]);
      s2 = tost(xo[y]);
      rus =
          max(rus, max(xo[x] ^ ask1(s1, 0, x, t1), xo[y] ^ ask2(s2, 0, y, t2)));
    }
    res[que[i].second] = max(rus, ras);
  }
  for (int i = 0; i < m; i++) cout << res[i] << '\n';
  return 0;
}
