#include <bits/stdc++.h>
using namespace std;
int C[1010][1010] = {};
int main() {
  int k, b, sum = 0;
  long long ans = 1;
  cin >> k;
  C[0][0] = 1;
  for (int i = (int)(1); i <= (int)(1000); i++)
    for (int j = (int)(0); j <= (int)(i); j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
  ;
  for (int i = (int)(1); i <= (int)(k); i++) {
    scanf("%d", &b);
    ans = (ans * C[sum + b - 1][b - 1]) % 1000000007;
    ;
    sum += b;
  }
  cout << ans;
  return 0;
}
