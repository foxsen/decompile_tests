#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[110][110];
int res;
void enter() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
}
int process(vector<int> A) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= m; j++) cnt += a[i][j] != A[j - 1];
    res += min(cnt, m - cnt);
  }
  return res;
}
int process1(vector<int> A) {
  int res = 0;
  for (int j = 1; j <= m; j++) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += a[i][j] != A[i - 1];
    res += min(cnt, n - cnt);
  }
  return res;
}
int main() {
  enter();
  res = 1000000007;
  if (n > 10) {
    for (int i = 1; i <= n; i++) {
      vector<int> A;
      A.clear();
      for (int j = 1; j <= m; j++) A.push_back(a[i][j]);
      res = min(res, process(A));
    }
  } else {
    vector<int> A;
    for (int i = 0; i <= (1 << n) - 1; i++) {
      A.clear();
      for (int j = 1; j <= n; j++) A.push_back((i >> (j - 1)) & 1);
      res = min(res, process1(A));
    }
  }
  if (res > k)
    cout << -1;
  else
    cout << res;
}
