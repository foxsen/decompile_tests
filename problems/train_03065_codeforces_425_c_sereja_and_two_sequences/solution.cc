#include <bits/stdc++.h>
using namespace std;
const int INF = 1E9 + 7;
template <class C>
void mini(C& a4, C b4) {
  a4 = in(a4, b4);
}
set<int> gdzie[2][100005];
int t[2][100005];
int best[100005][305];
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  for (int i = (1); i <= (n); ++i) {
    cin >> t[0][i];
  }
  for (int i = (1); i <= (m); ++i) {
    cin >> t[1][i];
    gdzie[1][t[1][i]].insert(i);
  }
  for (int i = (1); i <= (n); ++i) {
    int a = t[0][i];
    if (((int)(gdzie[1][a]).size())) {
      int pos = *(gdzie[1][a].begin());
      best[i][1] = pos;
    } else
      best[i][1] = INF;
  }
  for (int k = (2); k <= (300); ++k) {
    int be = INF;
    for (int i = (1); i <= (n); ++i) {
      best[i][k] = INF;
      int a = t[0][i];
      set<int>::iterator l = gdzie[1][a].upper_bound(be);
      if (l != gdzie[1][a].end()) best[i][k] = *l;
      be = min(be, best[i][k - 1]);
    }
  }
  int wyn = 0;
  for (int k = (1); k <= (300); ++k) {
    int ene_cost = INF;
    for (int i = (1); i <= (n); ++i) {
      ene_cost = min(ene_cost, i + best[i][k]);
    }
    ene_cost += k * e;
    if (ene_cost <= s) wyn = k;
  }
  cout << wyn << endl;
  return 0;
}
