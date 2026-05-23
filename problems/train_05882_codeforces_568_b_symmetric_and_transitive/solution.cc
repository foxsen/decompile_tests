#include <bits/stdc++.h>
using namespace std;
long long int choose[4001][4001];
long long int f[4001], g[4001];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (int)4001; ++i) choose[i][i] = choose[i][0] = 1;
  for (int i = 0; i < (int)n + 1; ++i)
    if (i)
      for (int j = 0; j < (int)i; ++j)
        if (j)
          choose[i][j] =
              (((choose[i - 1][j] + choose[i - 1][j - 1]) % 1000000007 +
                1000000007) %
               1000000007);
  f[0] = 1;
  for (int i = 0; i < (int)n + 1; ++i)
    if (i) {
      for (int j = 0; j < (int)i; ++j) {
        (f[i]) = ((((f[i]) + (((f[i - 1 - j] * choose[i - 1][j] *
                                (long long int)(j == 0 ? 2 : 1)) %
                               1000000007))) %
                       1000000007 +
                   1000000007) %
                  1000000007);
      }
    }
  long long int res = f[n];
  for (int i = 0; i < (int)n + 1; ++i)
    if (i) {
      long long int x = 1;
      if (i % 2) x = -1;
      (res) =
          ((((res) + (x * choose[n][i] * f[n - i])) % 1000000007 + 1000000007) %
           1000000007);
    }
  cout << (((f[n] - res) % 1000000007 + 1000000007) % 1000000007) << endl;
}
