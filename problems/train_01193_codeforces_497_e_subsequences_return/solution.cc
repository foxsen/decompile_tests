#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e1 + 5;
const int LOG = 6e1 + 5;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
int d[LOG];
struct Matrix {
  int n, m, M[maxN][maxN];
  Matrix(int _n = 0, int _m = 0) {
    n = _n;
    m = _m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) M[i][j] = 0;
    return;
  }
  int* operator[](int i) { return M[i]; }
  Matrix operator*(const Matrix& A) {
    Matrix B(n, A.m);
    for (int i = 0; i < n; i++)
      for (int k = 0; k < m; k++)
        for (int j = 0; j < A.m; j++)
          B[i][j] = (0ll + B[i][j] + 1ll * M[i][k] * A.M[k][j] % MOD) % MOD;
    return B;
  }
  void print() {
    for (int i = 0; i < n; i++, printf("\n"))
      for (int j = 0; j < m; j++) printf("%d ", M[i][j]);
    printf("\n");
    return;
  }
} K[LOG];
int main() {
  time_t START = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  int k;
  scanf("%lld%d", &n, &k);
  for (int i = 0; i < LOG; i++) K[i] = Matrix(k + 1, k + 1);
  for (int i = 1; i < LOG; i++)
    for (int j = 0; j <= k; j++) K[i][j][j] = 1;
  Matrix S(k + 1, k + 1), T(k + 1, k + 1);
  Matrix R(k + 1, k + 1), t(k + 1, k + 1);
  for (int i = 0; i < k; i++) {
    S[i][(k + i - 1) % k] = 1;
    T[(k + i - 1) % k][i] = 1;
  }
  S[k][k] = T[k][k] = 1;
  for (int i = 0; i <= k; i++) K[0][0][i] = K[0][i][i] = 1;
  long long m = n;
  int cnt = 0;
  for (int i = 1; m >= k; m /= k, i++) {
    d[cnt++] = m % k;
    for (int j = 0; j <= k; j++) K[i][j][j] = 1;
    t = K[i - 1];
    for (int j = 0; j < k; j++) {
      K[i] = t * K[i];
      t = (S * t) * T;
    }
  }
  d[cnt] = m;
  for (int i = 0; i <= k; i++) R[i][i] = 1;
  int sum = 0;
  for (cnt; cnt > -1; cnt--) {
    t = K[cnt];
    for (int i = 0; i < sum; i++) t = (S * t) * T;
    for (int i = 0; i < d[cnt]; i++) {
      R = t * R;
      t = (S * t) * T;
    }
    sum = (sum + d[cnt]) % k;
  }
  int ans = 0;
  for (int i = 0; i <= k; i++) ans = (ans + R[i][k]) % MOD;
  printf("%d\n", ans);
  time_t FINISH = clock();
  cerr << "Execution time: "
       << (long double)(FINISH - START) / CLOCKS_PER_SEC * 1000.0
       << " milliseconds.\n";
  return 0;
}
