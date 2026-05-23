#include <bits/stdc++.h>
using namespace std;
long long A[5 * 1000 + 3][5 * 1000 + 3];
long long sum[5 * 1000 + 3];
int main() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  if (a > b) {
    a = n - a + 1;
    b = n - b + 1;
  }
  for (int j = 1; j <= b / 2; j++) A[j][1] = b - 2;
  A[b - 1][1] = 0;
  for (int j = b - 2; j > b / 2; j--) A[j][1] = A[j + 1][1] + 2;
  for (int i = 2; i <= k; i++) {
    sum[b] = 0;
    A[b - 1][i] = 0;
    for (int j = b - 1; j > 0; j--)
      sum[j] = (sum[j + 1] + A[j][i - 1]) % (1000 * 1000 * 1000 + 7);
    for (int j = b - 1; j > b / 2; j--)
      A[j][i] = (sum[2 * j - b + 1] - A[j][i - 1] + (1000 * 1000 * 1000 + 7)) %
                (1000 * 1000 * 1000 + 7);
    for (int j = 1; j <= b / 2; j++)
      A[j][i] = (sum[1] - A[j][i - 1] + (1000 * 1000 * 1000 + 7)) %
                (1000 * 1000 * 1000 + 7);
  }
  cout << A[a][k];
  return 0;
}
