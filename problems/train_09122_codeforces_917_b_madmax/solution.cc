#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
int n, m;
const int MAXN = 100;
int winner[MAXN][MAXN][26];
vector<pair<int, int> > gr[MAXN];
inline int get_winner(int a, int b, int c) {
  if (winner[a][b][c]) return winner[a][b][c];
  winner[a][b][c] = 2;
  for (auto u : gr[a]) {
    if (u.second >= c) {
      if (get_winner(b, u.first, u.second) == 2) {
        return winner[a][b][c] = 1;
      }
    }
  }
  return 2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int p, q;
    char c;
    cin >> p >> q >> c;
    gr[--p].push_back(make_pair(--q, c - 'a'));
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << (get_winner(i, j, 0) == 1 ? 'A' : 'B');
    }
    cout << '\n';
  }
}
