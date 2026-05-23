#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200000 + 10;
const long long INF = 1000000000 + 9;
long long n, h, w;
vector<pair<long long, long long>> v;
map<pair<long long, long long>, long long> M;
long long diag(pair<long long, long long> a) { return a.first + a.second; }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> w >> h;
  for (long long i = 0; i < n; i++) {
    long long g, p, t;
    cin >> g >> p >> t;
    if (g == 1) {
      v.push_back({p, -t});
      M[{p, -t}] = i;
    } else {
      v.push_back({-t, p});
      M[{-t, p}] = i;
    }
  }
  sort(begin(v), end(v),
       [](pair<long long, long long> a, pair<long long, long long> b) {
         if (diag(a) != diag(b)) return diag(a) < diag(b);
         return a.first < b.first;
       });
  vector<pair<long long, long long>> res(n);
  vector<vector<pair<long long, long long>>> ds;
  long long lastdiag = -INF;
  for (long long i = 0; i < n; i++) {
    if (diag(v[i]) != lastdiag) {
      ds.push_back(vector<pair<long long, long long>>());
      lastdiag = diag(v[i]);
    }
    ds.back().push_back(v[i]);
  }
  cerr << ds.size() << "\n";
  for (auto dia : ds) {
    long long l = 0;
    while (l < dia.size() && dia[l].first <= 0) l++;
    long long p = dia.size() - l;
    for (long long i = l; i < dia.size(); i++) {
      long long pp = (long long)dia.size() - i - 1;
      if (l > pp) {
        res[M[dia[i]]] = {w, dia[l - 1 - pp].second};
      } else {
        res[M[dia[i]]] = {dia[i + l].first, h};
      }
    }
    for (long long i = 0; i < l; i++) {
      long long ll = i;
      if (p > ll) {
        res[M[dia[i]]] = {dia[l + ll].first, h};
      } else {
        res[M[dia[i]]] = {w, dia[i - p].second};
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << res[i].first << " " << res[i].second << "\n";
  }
  return 0;
}
