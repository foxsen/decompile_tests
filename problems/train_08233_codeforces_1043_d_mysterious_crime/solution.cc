#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long ret = 0;
  vector<vector<int>> a(m);
  int pos[100002][11];
  for (int i = 0; i < m; i++) {
    int aa;
    for (int j = 0; j < n; j++) {
      scanf("%d", &aa);
      a[i].push_back(aa);
      pos[aa][i] = j;
    }
  }
  bool flag1 = false;
  for (long long i = 0; i < n - 1; i++) {
    bool flag = true;
    long long k = i;
    while (flag) {
      int cu = a[0][k];
      int ne = a[0][k + 1];
      for (int j = 1; j < m; j++) {
        if (pos[ne][j] - pos[cu][j] != 1) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
      if (k + 1 == n - 1) flag1 = true;
      k++;
      if (k == n - 1) break;
    }
    ret += ((k - i + 2) * (k - i + 1)) / 2;
    i = k;
  }
  if (!flag1) ret++;
  cout << ret << endl;
  return 0;
}
