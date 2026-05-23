#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long n, m, a, b, c, k, x, y;
const int MAXN = 1e5 + 11, mod = 1e9 + 7;
long long max(long long a, long long b) { return ((a > b) ? a : b); }
long long min(long long a, long long b) { return ((a > b) ? b : a); }
vector<long long> read(int n) {
  vector<long long> v(n);
  for (int i = 0; i < v.size(); i++) cin >> v[i];
  return v;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pair<long long, long long> intersection(pair<long long, long long> p1,
                                        pair<long long, long long> p2) {
  if (p1.first > p2.first) swap(p1, p2);
  if (p2.first > p1.second) return {0, -1};
  return {p2.first, min(p1.second, p2.second)};
}
long long tree[20025];
long long qfst(int l, int r) {
  long long res = 0;
  for (l += 10001, r += 10001; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += tree[l++];
    if (r & 1) res += tree[--r];
  }
  return res;
}
void modify(int p, int value) {
  for (tree[p += 10001] = value; p > 1; p >>= 1)
    tree[p >> 1] = tree[p] + tree[p ^ 1];
}
void sol(void) {
  cin >> n;
  vector<pair<long long, pair<long long, long long>>> vph, vpv;
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 == y2 && x1 > x2) {
      swap(x1, x2);
    } else if (x1 == x2 && y1 > y2) {
      swap(y1, y2);
    }
    x1 += 5000;
    x2 += 5000;
    y1 += 5000;
    y2 += 5000;
    if (x1 == x2)
      vpv.push_back({y1, {x1, y2}});
    else
      vph.push_back({y1, {x1, x2}});
  }
  sort(vph.begin(), vph.end());
  sort(vpv.begin(), vpv.end());
  long long ans = 0;
  set<pair<long long, long long>> s;
  int r = 0;
  for (int i = 0; i < vph.size(); i++) {
    while (r < vpv.size() && vpv[r].first <= vph[i].first) {
      s.insert({vpv[r].second.second, vpv[r].second.first});
      modify(vpv[r].second.first,
             qfst(vpv[r].second.first, vpv[r].second.first + 1) + 1);
      r++;
    }
    set<pair<long long, long long>> temp;
    for (int j = i + 1; j < vph.size(); j++) {
      while (s.size() && (*s.begin()).first < vph[j].first) {
        modify((*s.begin()).second,
               qfst((*s.begin()).second, (*s.begin()).second + 1) - 1);
        temp.insert(*s.begin());
        s.erase(s.begin());
      }
      pair<long long, long long> p = intersection(vph[i].second, vph[j].second);
      if (p.second - p.first + 1 > 0) {
        long long calc = qfst(p.first, p.second + 1);
        ans += (calc * (calc - 1));
      }
    }
    while (temp.size()) {
      if ((*temp.begin()).first < vph[i].first)
        temp.erase(temp.begin());
      else {
        s.insert(*temp.begin());
        modify((*temp.begin()).second,
               qfst((*temp.begin()).second, (*temp.begin()).second + 1) + 1);
        temp.erase(temp.begin());
      }
    }
  }
  cout << (ans >> 1);
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  for (int i = 1; i <= test; i++) sol();
}
