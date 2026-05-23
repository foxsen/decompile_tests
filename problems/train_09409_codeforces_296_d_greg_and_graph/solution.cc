#include <bits/stdc++.h>
using namespace std;
int const mxsz = 509;
long long w[mxsz][mxsz];
bool ver[mxsz];
int main() {
  vector<int> er;
  vector<long long> res;
  int n;
  scanf("%d", &n);
  er.resize(n);
  for (int i = 0; i < n; ++i) {
    int x;
    for (int j = 0; j < n; ++j) {
      scanf("%d", &x);
      w[i][j] = x;
    }
  }
  for (int i = 0; i < n; ++i) scanf("%d", &er[i]);
  reverse(er.begin(), er.end());
  for (int k = 0; k < n; ++k) {
    er[k]--;
    ver[er[k]] = 1;
    long long R = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        w[i][j] = min(w[i][j], w[i][er[k]] + w[er[k]][j]);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (ver[i] && ver[j]) R += w[i][j];
    res.push_back(R);
  }
  for (int i = n - 1; i >= 0; --i) cout << res[i] << " ";
  return 0;
}
