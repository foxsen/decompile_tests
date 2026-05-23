#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
void add_fenwick(vector<int>* arr, int i, int dy) {
  while (i < arr->size()) {
    (*arr)[i] = ((*arr)[i] + dy) % MOD;
    i |= (i + 1);
  }
}
int sum_fenwick(vector<int>* arr, int n) {
  int sum = 0;
  while (n > 0) {
    sum = (sum + (*arr)[n - 1]) % MOD;
    n &= (n - 1);
  }
  return sum;
}
int index_of(vector<int>* arr, int x) {
  return lower_bound(arr->begin(), arr->end(), x) - arr->begin();
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> parents = vector<int>(n);
  parents[0] = -1;
  for (int u = 1; u < n; u++) {
    cin >> parents[u];
    --parents[u];
  }
  vector<int> sizes = vector<int>(n);
  vector<vector<int> > children = vector<vector<int> >(n);
  for (int u = 0; u < n; u++) {
    sizes[u] = 0;
    children[u] = vector<int>();
  }
  for (int u = n - 1; u >= 0; --u) {
    ++sizes[u];
    reverse(children[u].begin(), children[u].end());
    if (parents[u] >= 0) {
      sizes[parents[u]] += sizes[u];
      children[parents[u]].push_back(u);
    }
  }
  vector<int> levels = vector<int>(n);
  int treeHeight = 0;
  levels[0] = 0;
  for (int u = 1; u < n; u++) {
    levels[u] = levels[parents[u]] + 1;
    treeHeight = max(treeHeight, levels[u]);
  }
  vector<int> heavyChildren = vector<int>(n);
  vector<bool> isHeavyChild = vector<bool>(n);
  for (int u = 0; u < n; u++) isHeavyChild[u] = false;
  for (int u = 0; u < n; u++) {
    heavyChildren[u] = -1;
    for (int v : children[u]) {
      if ((sizes[v] * 2) > (sizes[u] - 1)) {
        heavyChildren[u] = v;
        isHeavyChild[v] = true;
      }
    }
  }
  vector<vector<int>*> hld = vector<vector<int>*>(n);
  vector<vector<int>*> xHld = vector<vector<int>*>(n);
  vector<vector<int>*> kHld = vector<vector<int>*>(n);
  vector<vector<int>*> khHld = vector<vector<int>*>(n);
  for (int u = 0; u < n; u++) {
    if (isHeavyChild[u]) {
      hld[u] = hld[parents[u]];
      xHld[u] = xHld[parents[u]];
      kHld[u] = kHld[parents[u]];
      khHld[u] = khHld[parents[u]];
    } else {
      hld[u] = new vector<int>();
      xHld[u] = new vector<int>();
      kHld[u] = new vector<int>();
      khHld[u] = new vector<int>();
    }
    hld[u]->push_back(u);
    xHld[u]->push_back(0);
    kHld[u]->push_back(0);
    khHld[u]->push_back(0);
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, x, k;
      cin >> u >> x >> k;
      --u;
      add_fenwick(xHld[u], index_of(hld[u], u), x);
      add_fenwick(kHld[u], index_of(hld[u], u), k);
      add_fenwick(khHld[u], index_of(hld[u], u),
                  (k * (long long)levels[u]) % MOD);
    } else {
      int u;
      cin >> u;
      --u;
      int u0 = u;
      int sumX = 0;
      int sumK = 0;
      int sumKH = 0;
      while (u >= 0) {
        sumX = (sumX + sum_fenwick(xHld[u], index_of(hld[u], u) + 1)) % MOD;
        sumK = (sumK + sum_fenwick(kHld[u], index_of(hld[u], u) + 1)) % MOD;
        sumKH = (sumKH + sum_fenwick(khHld[u], index_of(hld[u], u) + 1)) % MOD;
        u = parents[hld[u]->at(0)];
      }
      int result =
          (sumX + (long long)sumKH - (sumK * (long long)levels[u0])) % MOD;
      if (result < 0) result += MOD;
      cout << result << endl;
    }
  }
  return 0;
}
