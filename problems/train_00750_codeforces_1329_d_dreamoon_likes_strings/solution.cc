#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 100;
const long long inf = 0x3f3f3f3f;
const long long iinf = 1 << 30;
const long long linf = 2e18;
const long long mod = 998244353;
const double eps = 1e-7;
template <class T = long long>
T chmin(T &a, T b) {
  return a = min(a, b);
}
template <class T = long long>
T chmax(T &a, T b) {
  return a = max(a, b);
}
template <class T = long long>
T read() {
  T f = 1, a = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    a = (a << 3) + (a << 1) + ch - '0';
    ch = getchar();
  }
  return a * f;
}
long long t, n, ans, dif_sum;
char s[maxn];
long long sum[maxn];
set<pair<long long, long long>> dif, col;
set<pair<pair<long long, long long>, pair<long long, long long>>> near[maxn];
struct node {
  long long l, r, val;
  long long tag;
} tr[maxn];
void build(long long tot, long long l, long long r) {
  tr[tot].l = l, tr[tot].r = r, tr[tot].val = tr[tot].tag = 0;
  if (l == r) return;
  build((tot << 1), l, ((tr[tot].l + tr[tot].r) >> 1)),
      build((tot << 1 | 1), ((tr[tot].l + tr[tot].r) >> 1) + 1, r);
}
void stag(long long tot) {
  tr[tot].val = tr[tot].r - tr[tot].l + 1;
  if (tr[tot].l != tr[tot].r) tr[tot].tag = 1;
}
void pushdown(long long tot) {
  if (!tr[tot].tag) return;
  stag((tot << 1)), stag((tot << 1 | 1)), tr[tot].tag = 0;
}
void maintain(long long tot) {
  tr[tot].val = tr[(tot << 1)].val + tr[(tot << 1 | 1)].val;
}
void modify(long long tot, long long l, long long r) {
  if (tr[tot].l >= l && tr[tot].r <= r) return (void)(stag(tot));
  pushdown(tot);
  if (l <= ((tr[tot].l + tr[tot].r) >> 1)) modify((tot << 1), l, r);
  if (r > ((tr[tot].l + tr[tot].r) >> 1)) modify((tot << 1 | 1), l, r);
  maintain(tot);
}
long long query(long long tot, long long r) {
  if (tr[tot].r <= r) return tr[tot].val;
  pushdown(tot);
  long long ret = query((tot << 1), r);
  if (r > ((tr[tot].l + tr[tot].r) >> 1)) ret += query((tot << 1 | 1), r);
  return ret;
}
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    build(1, 1, n);
    dif_sum = 0;
    for (long long i = (1); i <= (n - 1); ++i)
      if (s[i] == s[i + 1])
        dif.insert(make_pair(i, s[i] - 'a')), sum[s[i] - 'a']--, dif_sum++;
    for (long long i = (0); i <= (25); ++i)
      if (sum[i]) col.insert(make_pair(sum[i], i));
    auto last = dif.begin();
    if (last == dif.end()) {
      puts("1");
      goto end;
    }
    for (auto i = ++dif.begin(); i != dif.end(); ++i) {
      if (i->second != last->second) {
        near[i->second].insert(make_pair(*last, *i));
        near[last->second].insert(make_pair(*last, *i));
      }
      last = i;
    }
    ans = max((dif_sum + 1) / 2, -col.begin()->first) + 1;
    printf("%lld\n", ans);
    while (col.size() > 1) {
      pair<long long, long long> b = *col.begin();
      pair<pair<long long, long long>, pair<long long, long long>> del =
          *near[b.second].begin();
      long long l = del.first.first + 1 - query(1, del.first.first + 1),
                r = del.second.first - query(1, del.second.first);
      printf("%lld %lld\n", l, r);
      modify(1, del.first.first + 1, del.second.first);
      near[del.first.second].erase(near[del.first.second].find(del));
      near[del.second.second].erase(near[del.second.second].find(del));
      auto posl = dif.find(del.first), posr = ++dif.find(del.second);
      if (posl != dif.begin()) {
        posl--;
        if (posl->second != del.first.second) {
          near[posl->second].erase(
              near[posl->second].find(make_pair(*posl, del.first)));
          near[del.first.second].erase(
              near[del.first.second].find(make_pair(*posl, del.first)));
        }
        posl++;
      }
      if (posr != dif.end()) {
        if (del.second.second != posr->second) {
          near[del.second.second].erase(
              near[del.second.second].find(make_pair(del.second, *posr)));
          near[posr->second].erase(
              near[posr->second].find(make_pair(del.second, *posr)));
        }
      }
      if (posl != dif.begin() && posr != dif.end()) {
        --posl;
        if (posl->second != posr->second) {
          near[posl->second].insert(make_pair(*posl, *posr));
          near[posr->second].insert(make_pair(*posl, *posr));
        }
      }
      dif.erase(dif.find(del.first)), dif.erase(dif.find(del.second));
      col.erase(col.find(make_pair(sum[del.first.second], del.first.second)));
      col.erase(col.find(make_pair(sum[del.second.second], del.second.second)));
      sum[del.first.second]++, sum[del.second.second]++;
      if (sum[del.first.second])
        col.insert(make_pair(sum[del.first.second], del.first.second));
      if (sum[del.second.second])
        col.insert(make_pair(sum[del.second.second], del.second.second));
    }
    if (col.size() == 1) {
      sum[col.begin()->second] = 0;
      col.clear();
      while (dif.size()) {
        auto top = dif.begin();
        printf("1 %lld\n", top->first - query(1, top->first));
        modify(1, 1, top->first);
        dif.erase(top);
      }
    }
  end:;
    printf("1 %lld\n", n - query(1, n));
  }
  return 0;
}
