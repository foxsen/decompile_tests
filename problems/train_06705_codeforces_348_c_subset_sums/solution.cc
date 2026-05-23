#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100009], bigs, smalls;
long long int a[100009], vals[100009], updates[100009];
int f[100009];
int store[320 + 10][100009], storeb[320 + 10][320 + 10];
int invb[100009], invs[100009];
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    if (x > 320) {
      bigs.push_back(i);
      invb[i] = bigs.size() - 1;
    } else {
      smalls.push_back(i);
      invs[i] = smalls.size() - 1;
    }
    while (x--) {
      int y;
      cin >> y;
      adj[i].push_back(y);
      vals[i] += a[y];
    }
  }
  for (int i = 0; i < bigs.size(); i++) {
    int x = bigs[i];
    for (int j = 0; j < adj[x].size(); j++) {
      f[adj[x][j]]++;
    }
    for (int j = 0; j < smalls.size(); j++) {
      int y = smalls[j];
      for (int k = 0; k < adj[y].size(); k++) {
        if (f[adj[y][k]]) store[i][j]++;
      }
    }
    for (int j = 0; j < bigs.size(); j++) {
      int y = bigs[j];
      for (int k = 0; k < adj[y].size(); k++) {
        if (f[adj[y][k]]) storeb[i][j]++;
      }
    }
    for (int j = 0; j < adj[x].size(); j++) {
      f[adj[x][j]]--;
    }
  }
  while (q--) {
    string x;
    cin >> x;
    if (x[0] == '?') {
      int y;
      cin >> y;
      if (adj[y].size() > 320) {
        long long int sol = vals[y];
        for (int i = 0; i < bigs.size(); i++) {
          sol += updates[bigs[i]] * 1ll * storeb[invb[y]][i];
        }
        cout << sol << "\n";
      } else {
        long long int sol = 0;
        for (int j = 0; j < adj[y].size(); j++) {
          sol += a[adj[y][j]];
        }
        for (int j = 0; j < bigs.size(); j++) {
          sol += store[j][invs[y]] * 1ll * updates[bigs[j]];
        }
        cout << sol << "\n";
      }
    } else {
      int y, z;
      cin >> y >> z;
      if (adj[y].size() > 320) {
        updates[y] += z;
      } else {
        for (int j = 0; j < adj[y].size(); j++) {
          a[adj[y][j]] += z;
        }
        for (int j = 0; j < bigs.size(); j++) {
          vals[bigs[j]] += z * 1ll * store[j][invs[y]];
        }
      }
    }
  }
}
