#include <bits/stdc++.h>
using namespace std;
int fin(int x, vector<int>& parent) {
  if (parent[x] != x) {
    parent[x] = fin(parent[x], parent);
  }
  return parent[x];
}
void h(int x, int y, vector<int>& rank, vector<int>& parent) {
  int xset = fin(x, parent);
  int yset = fin(y, parent);
  if (xset == yset) return;
  if (rank[xset] < rank[yset]) {
    parent[xset] = yset;
  } else if (rank[xset] > rank[yset]) {
    parent[yset] = xset;
  } else {
    parent[yset] = xset;
    rank[xset] = rank[xset] + 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<string> tab(n);
  vector<int> parent(n + 26);
  vector<int> rank(n + 26, 0);
  for (int i = 0; i < n + 26; i++) {
    parent[i] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
    for (int j = 0; j < tab[i].size(); j++) {
      int a = tab[i][j] - 'a';
      h(i, n + a, rank, parent);
    }
  }
  unordered_set<int> S;
  for (int i = 0; i < n; i++) {
    S.insert(fin(i, parent));
  }
  cout << S.size() << endl;
  return 0;
}
