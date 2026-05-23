#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100 * 1000 + 10;
const long long D = 1000ll * 1000 * 1000 + 7;
pair<int, long long> par[Maxn];
pair<int, long long> find(int v) {
  if (v == par[v].first) return par[v];
  pair<int, long long> ret = find(par[v].first);
  par[v] = pair<int, long long>(ret.first,
                                (((ret.second + par[v].second) % D) + D) % D);
  return par[v];
}
long long n, ret;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long k, v, x;
    cin >> k;
    par[i].first = i;
    for (int j = 0; j < k; j++) {
      cin >> v >> x;
      find(v);
      ret = (((ret + x + par[v].second) % D) + D) % D;
      par[par[v].first] = pair<int, long long>(i, par[v].second + x);
    }
  }
  cout << ret << endl;
  return 0;
}
