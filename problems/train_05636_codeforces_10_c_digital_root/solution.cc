#include <bits/stdc++.h>
using namespace std;
long long int cant[9];
int main() {
  int n;
  cin >> n;
  for (int r = 0; r < (int)(9); r++) cant[r] = n / 9;
  for (int r = (int)(((n / 9) * 9) + 1); r < ((int)n + 1); r++) cant[r % 9]++;
  long long int res = 0;
  for (int i = 0; i < (int)(9); i++)
    for (int j = 0; j < (int)(9); j++) {
      int k = (i * j) % 9;
      res += cant[i] * cant[j] * cant[k];
    }
  for (int i = (int)(1); i < ((int)n + 1); i++) {
    int j = n / i;
    res -= j;
  }
  cout << res << endl;
  return 0;
}
