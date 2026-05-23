#include <bits/stdc++.h>
using namespace std;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<V<T>>;
template <typename T>
istream& operator>>(istream& cin, V<T>& arr) {
  for (T& val : arr) {
    cin >> val;
  }
  return cin;
}
template <typename T>
ostream& operator<<(ostream& cout, V<T>& arr) {
  for (T& val : arr) {
    cout << val << " ";
  }
  return cout;
}
void dfs(vector<vector<long long>>& g, vector<long long>& visited,
         long long pos, bool& flag) {
  visited[pos] = true;
  flag = flag && g[pos].size() == 2;
  for (long long i = 0; i < g[pos].size(); i++) {
    if (!visited[g[pos][i]]) {
      dfs(g, visited, g[pos][i], flag);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<vector<long long>> g(n, vector<long long>(n));
  for (long long i = 0; i < n; i++) {
    cin >> g[i];
  }
  vector<bool> isDeleted(n, true);
  vector<long long> vertices(n);
  cin >> vertices;
  for (long long& i : vertices) {
    i--;
  }
  vector<long long> ans(n);
  vector<vector<long long>> minDist(n, vector<long long>(n, 10e5 + 10));
  for (long long l = n - 1; l >= 0; l--) {
    long long v = vertices[l];
    isDeleted[v] = false;
    for (long long k = 0; k < n; k++) {
      if (!isDeleted[k]) {
        for (long long i = 0; i < n; i++) {
          if (!isDeleted[i]) {
            g[i][v] = min(g[i][v], g[i][k] + g[k][v]);
            g[v][i] = min(g[v][i], g[v][k] + g[k][i]);
          }
        }
      }
    }
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      if (!isDeleted[i]) {
        for (long long j = 0; j < n; j++) {
          if (!isDeleted[j]) {
            g[i][j] = min(g[i][j], g[i][v] + g[v][j]);
            sum += g[i][j];
          }
        }
      }
    }
    ans[l] = sum;
  }
  cout << ans;
  return 0;
}
