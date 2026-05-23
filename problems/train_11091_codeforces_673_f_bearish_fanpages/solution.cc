#include <bits/stdc++.h>
using namespace std;
int Q, N, M, K, L;
long long FAN[100001];
int p[100001];
long long v[100001];
struct comp {
  bool operator()(const int& a, const int& b) const {
    if (v[a] != v[b]) return v[a] < v[b];
    return a < b;
  }
};
set<int, comp> children[100001];
int deg[100001];
multiset<long long> mulset;
long long value_for_other(int a) { return FAN[a] / (2 + deg[a]); }
long long value_for_self(int a) {
  return FAN[a] - (1 + deg[a]) * value_for_other(a);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> FAN[i];
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    p[i]--;
    children[p[i]].insert(i);
    deg[p[i]]++;
  }
  for (int i = 0; i < N; i++) {
    v[i] += value_for_self(i);
    for (int child : children[i]) v[i] += value_for_other(child);
  }
  for (int i = 0; i < N; i++) {
    children[p[i]].erase(i);
    children[p[i]].insert(i);
  }
  for (int n = 0; n < N; n++) {
    long long pv = value_for_other(n);
    if (!deg[n]) continue;
    mulset.insert(v[*children[n].begin()] + pv);
    mulset.insert(v[*children[n].rbegin()] + pv);
  }
  for (int q = 0; q < M; q++) {
    int a, b, c;
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
      b--;
      c--;
      set<int> go = {b, c, p[b], p[c], p[p[b]]};
      set<int> go2 = go;
      for (int n : go) go2.insert(p[n]);
      for (int n : go2) {
        if (!deg[n]) continue;
        long long pv = value_for_other(n);
        mulset.erase(mulset.find(v[*children[n].begin()] + pv));
        mulset.erase(mulset.find(v[*children[n].rbegin()] + pv));
      }
      for (int n : go) children[p[n]].erase(n);
      for (int n : go) {
        v[n] -= value_for_self(n);
        for (int m : go)
          if (p[m] == n) v[n] -= value_for_other(m);
      }
      deg[p[b]]--;
      p[b] = c;
      deg[p[b]]++;
      for (int n : go) {
        v[n] += value_for_self(n);
        for (int m : go)
          if (p[m] == n) v[n] += value_for_other(m);
      }
      for (int n : go) children[p[n]].insert(n);
      for (int n : go2) {
        if (!deg[n]) continue;
        long long pv = value_for_other(n);
        mulset.insert(v[*children[n].begin()] + pv);
        mulset.insert(v[*children[n].rbegin()] + pv);
      }
    }
    if (a == 2) {
      cin >> b;
      b--;
      cout << v[b] + value_for_other(p[b]) << "\n";
    }
    if (a == 3) {
      cout << *mulset.begin() << " " << *mulset.rbegin() << "\n";
    }
  }
  cin >> N;
}
