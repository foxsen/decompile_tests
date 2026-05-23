#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int V = 2e6 + 5, MOD = 1e9 + 7;
map<int, pii> mp;
vector<int> p, phi, prm;
int n;
int lst[V];
static void get_lst() {
  for (int i = 2; i < V; ++i)
    if (lst[i] == 0)
      for (int j = i; j < V; j += i) lst[j] = i;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  i64 ant;
  int pr, ex;
  get_lst();
  cin >> n;
  p.resize(n);
  for (auto &i : p) cin >> i;
  sort(p.rbegin(), p.rend());
  for (auto i : p) {
    if (mp[i] == pii(0, 0)) {
      mp[i] = pii(0, 1);
      prm.push_back(i);
      continue;
    }
    if (i == 2) {
      mp[i].first = max(mp[i].first, 1);
      prm.push_back(2);
      continue;
    }
    i -= 1;
    phi.push_back(i);
    while (i > 1) {
      pr = lst[i];
      ex = 0;
      while (lst[i] == pr) {
        ex += 1;
        i /= lst[i];
      }
      auto &ref = mp[pr];
      if (ref.second <= ex) {
        ref.first = ref.second;
        ref.second = ex;
      } else if (ref.first < ex)
        ref.first = ex;
    }
  }
  ant = 1;
  for (auto i : mp)
    for (int j = 0; j < i.second.second; ++j) ant = ant * i.first % MOD;
  bool flag = false;
  for (auto i : prm) {
    bool ok = true;
    if (mp[i].second > 0 && mp[i].first > 0) {
      ant += 1;
      flag = true;
      break;
    }
  }
  if (!flag)
    for (auto i : phi) {
      bool ok = true;
      while (i > 1) {
        pr = lst[i];
        ex = 0;
        while (lst[i] == pr) {
          ex += 1;
          i /= lst[i];
        }
        auto &ref = mp[pr];
        ok &= ref.second && ex <= ref.first;
      }
      if (ok) {
        ant += 1;
        break;
      }
    }
  cout << ant << endl;
  return 0;
}
