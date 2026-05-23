#include <bits/stdc++.h>
using namespace std;
const int size = 200 * 1000 + 100;
int ans[size];
int a[size];
int mycur[size];
int t, n;
int d;
int shift[size];
int ord[size];
int nod(int a, int b) {
  if (b == 0)
    return a;
  else
    return nod(b, a % b);
}
int pwr(int a, int b, int mdl) {
  if (b == 0) return 1 % mdl;
  int d = pwr(a, b / 2, mdl);
  d = (d * 1ll * d) % mdl;
  if (b & 1) d = (d * 1ll * a) % mdl;
  return d;
}
map<int, int> factor(int val) {
  map<int, int> res;
  for (int i = 2; i * i <= val; i++) {
    if (val % i == 0) {
      res[i] = 0;
      while (val % i == 0) {
        res[i] += 1;
        val /= i;
      }
    }
  }
  if (val > 1) {
    res[val] = 1;
  }
  return res;
}
int main() {
  scanf("%d%d", &t, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  set<int> hps;
  int cur = 0ll;
  for (int i = 0; i < n; i++) {
    mycur[i] = cur;
    if (hps.count(mycur[i]))
      ans[i] = 0;
    else
      ans[i] = 1;
    hps.insert(mycur[i]);
    cur += a[(i + 1) % n];
    cur %= t;
  }
  d = nod(t, cur);
  map<int, int> fact = factor(t / d);
  int phi = 1;
  for (auto& e : fact) {
    for (int i = 0; i < (int)e.second - 1; i++) phi *= e.first;
    phi *= (e.first - 1);
  }
  int back = pwr(cur / d, phi - 1, t / d);
  for (int i = 0; i < n; i++) {
    if (ans[i] == 0 || cur == 0) continue;
    shift[i] = mycur[i] % d;
    ord[i] = ((mycur[i] / d) * 1ll * back) % (t / d);
  }
  if (cur > 0) {
    map<int, vector<pair<int, int> > > ords;
    for (int i = 0; i < n; i++) {
      if (ans[i] > 0) {
        ords[shift[i]].push_back(make_pair(ord[i], i));
      }
    }
    for (auto& e : ords) {
      sort(e.second.begin(), e.second.end());
      for (int j = 0; j < (int)e.second.size() - 1; j++)
        ans[e.second[j].second] = e.second[j + 1].first - e.second[j].first;
      ans[e.second.back().second] =
          t / d - e.second.back().first + e.second[0].first;
    }
  }
  for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i == n - 1]);
  return 0;
}
