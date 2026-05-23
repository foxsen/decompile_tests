#include <bits/stdc++.h>
using namespace std;
int n, f[2][4];
char s[105];
int main() {
  cin >> n;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s;
      for (int k = 1; k <= n; k++) {
        f[0][i] += ((j & 1) ^ (k & 1)) ^ (s[k - 1] == '0'),
            f[1][i] += ((j & 1) ^ (k & 1)) ^ (s[k - 1] == '1');
      }
    }
  }
  printf("%d\n", min(f[0][0] + f[0][1] + f[1][2] + f[1][3],
                     min(f[0][0] + f[1][1] + f[0][2] + f[1][3],
                         min(f[1][0] + f[0][1] + f[0][2] + f[1][3],
                             min(f[0][0] + f[1][1] + f[1][2] + f[0][3],
                                 min(f[1][0] + f[0][1] + f[1][2] + f[0][3],
                                     min(f[1][0] + f[1][1] + f[0][2] + f[0][3],
                                         0x7fffffff)))))));
  return 0;
}
