#include <bits/stdc++.h>
using namespace std;

using PP = pair<int, int>;
int n, m;
vector<PP> G[50];
int p[50], q[50];
long ps[50][50];

void rec(int st, int from, int prev, long path) {
  ps[st][from] = path;
  for (PP e : G[from]) {
    int to = e.first;
    int id = e.second;
    if (to == prev) continue;
    path ^= 1l << id;
    rec(st, to, from, path);
    path ^= 1l << id;
  }
}

long sub(int s) {
  long cons = 0;
  for (int k = 0; k < m; ++k) {
    if ((s >> k) & 1) {
      cons |= ps[p[k]][q[k]];
    }
  }
  
  int cnt = __builtin_popcountll(cons);
  return 1l << (n - 1 - cnt);
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(PP(b, i));
    G[b].push_back(PP(a, i));
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> p[i] >> q[i];
    --p[i]; --q[i];
  }
  
  for (int i = 0; i < n; ++i) {
    rec(i, i, -1, 0l);
  }
  
  long sum = 0;
  for (int s = 0; s < (1 << m); ++s) {
    int sgn = __builtin_popcountll(s) % 2 == 0 ? 1 : -1;
    sum += sgn * sub(s);
  }
  cout << sum << endl;
}