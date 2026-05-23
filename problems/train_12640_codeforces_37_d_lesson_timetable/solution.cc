#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:50000000")
using namespace std;
const long long MOD = 1000000007;
int n, sum;
long long A[100], B[100];
long long DP[102][1002];
long long C[2000][2000];
int F[2000];
long long P[2000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) cin >> B[i];
  sum = 0;
  for (int i = 0; i < n; i++) sum += A[i];
  DP[0][0] = 1;
  for (int i = 0; i < 2000; i++) C[i][0] = 1;
  for (int i = 1; i < 2000; i++)
    for (int j = 1; j < i + 1; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
  F[0] = 1;
  for (int i = 1; i < 2000; i++)
    F[i] = ((long long)F[i - 1] * (long long)i) % MOD;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < sum + 1; j++)
      if (DP[i][j] > 0) {
        int t = min(B[i], j + A[i]);
        for (int k = 0; k < t + 1; k++) {
          DP[i + 1][j + A[i] - k] =
              (DP[i + 1][j + A[i] - k] +
               (((long long)DP[i][j] * (long long)C[j + A[i]][k]) % MOD)) %
              MOD;
        }
      }
  int res = DP[n][0];
  for (int i = 1; i < sum + 1; i++) {
    int t = i;
    for (int j = 2; j * j <= i; j++)
      while (t % j == 0) {
        P[j]++;
        t /= j;
      }
    if (t > 1) P[t]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < A[i] + 1; j++) {
      int t = j;
      for (int k = 2; k * k <= j; k++)
        while (t % k == 0) {
          P[k]--;
          t /= k;
        }
      if (t > 1) P[t]--;
    }
  }
  for (int i = 2; i < 2000; i++)
    for (int j = 0; j < P[i]; j++)
      res = (((long long)res * (long long)i)) % MOD;
  cout << res << endl;
  cin >> n;
  return 0;
}
