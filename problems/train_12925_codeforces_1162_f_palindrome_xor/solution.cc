#include <bits/stdc++.h>
using namespace std;
int readInt() {
  int x;
  if (scanf(" %d", &x) != EOF) return x;
  return -1;
}
long long int readLint() {
  long long int x;
  if (cin >> x) return x;
  return -1;
}
string readString() {
  string s;
  if (cin >> s) return s;
  return "";
}
struct Graph {
  int n;
  vector<vector<vector<int> > > edge;
  vector<int> color;
  Graph(int n) : n(n) {
    edge = vector<vector<vector<int> > >(2, vector<vector<int> >(n));
  }
  void addEdge(int type, int u, int v) {
    edge[type][u].push_back(v);
    edge[type][v].push_back(u);
  }
  bool isBipartite(int u, vector<int>& color, int curColor) {
    if (color[u] >= 0) return color[u] == curColor;
    color[u] = curColor;
    for (int k = 0; k < 2; ++k)
      for (auto v : edge[k][u])
        if (!isBipartite(v, color, (curColor + k) % 2)) return false;
    return true;
  }
  pair<bool, int> isBipartite() {
    color = vector<int>(n, -1);
    int components = 0;
    for (int i = 0; i < n; ++i)
      if (color[i] == -1) {
        components++;
        if (!isBipartite(i, color, 0)) {
          return {false, components};
        }
      }
    return {true, components};
  }
};
struct SingleCase {
  vector<int> v;
  static const long long int mod = 998244353;
  long long int computeForLength(vector<int>& v, int L) {
    int n = v.size();
    Graph g(n + L + 2);
    g.addEdge(1, 0, 1);
    for (int k = 0; k < n; ++k) g.addEdge(0, 2 + k, 2 + n - 1 - k);
    for (int k = 0; k < L; ++k) g.addEdge(0, 2 + n + k, 2 + n + L - 1 - k);
    g.addEdge(0, 1, 2 + n - 1);
    g.addEdge(0, 1, 2 + n + L - 1);
    for (int k = 0; k < L; ++k)
      if (v[n - 1 - k] <= 1) g.addEdge(v[n - 1 - k], 2 + k, 2 + n + k);
    for (int k = 0; k < n; ++k)
      if (k >= L && v[n - 1 - k] <= 1) g.addEdge(0, 2 + k, v[n - 1 - k]);
    auto R = g.isBipartite();
    if (!R.first) return 0;
    int c = R.second;
    long long int ret = 1;
    for (int i = 0; i < c; ++i)
      if (i) ret = ret * 2 % mod;
    return ret;
  }
  bool solveCase() {
    string s = readString();
    if (s == "") return false;
    int n = s.size();
    v = vector<int>(n, 0);
    for (int i = 0; i < n; ++i)
      v[i] = (s[i] == '1' ? 1 : (s[i] == '?' ? 2 : 0));
    long long int ret = 0;
    for (int L = 0; L < n; ++L)
      if (L) {
        long long int cur = computeForLength(v, L);
        ret = (ret + cur) % mod;
      }
    cout << ret << endl;
    return true;
  }
};
int main() {
  while (SingleCase().solveCase()) {
  }
}
