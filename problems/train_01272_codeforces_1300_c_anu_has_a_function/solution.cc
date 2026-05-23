#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
const int loose = 0;
const int tight = 1;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
struct Edge {
  long long to, cap, rev;
  Edge(long long _to, long long _cap, long long _rev) {
    to = _to;
    cap = _cap;
    rev = _rev;
  }
};
void add_edge(vector<vector<Edge> >& G, long long from, long long to,
              long long cap, bool revFlag, long long revCap) {
  G[from].push_back(Edge(to, cap, (long long)G[to].size()));
  if (revFlag)
    G[to].push_back(Edge(from, revCap, (long long)G[from].size() - 1));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  vector<vector<long long> > sum(n, vector<long long>(31, 0));
  for (long long(i) = 0; (i) < (n); (i)++) {
    long long aa;
    cin >> aa;
    a[i] = aa;
    long long con = 0;
    while (aa > 0) {
      sum[i][con] = aa % 2;
      aa /= 2;
      con++;
    }
  }
  for (long long(j) = 0; (j) < (31); (j)++) {
    for (long long(i) = 0; (i) < (n - 1); (i)++) {
      sum[i + 1][j] += sum[i][j];
    }
  }
  long long big = 0;
  for (long long i = 30; i >= 0; i--) {
    if (sum[n - 1][i] == 1) {
      for (long long(j) = 0; (j) < (n); (j)++) {
        if (sum[j][i] == 1) {
          big = j;
          break;
        }
      }
      break;
    }
  }
  cout << a[big];
  for (long long(i) = 0; (i) < (n); (i)++) {
    if (i != big) {
      cout << " " << a[i];
    }
  }
  cout << endl;
  return 0;
}
