#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")
using namespace std;
std::vector<long long> adj[10000];
bool visited[10000];
string str;
long long dis(long long x1, long long x2, long long x3, long long x4) {
  long long aa = (((x2 - x1) * (x2 - x1)) + ((x3 - x4) * (x3 - x4)));
  return aa;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  while (test--) {
    long long n, m;
    cin >> n >> m;
    long long x = min(n, m);
    cout << x + 1 << "\n";
    for (long long i = 0; i < x + 1; i++) cout << i << " " << x - i << "\n";
  }
}
