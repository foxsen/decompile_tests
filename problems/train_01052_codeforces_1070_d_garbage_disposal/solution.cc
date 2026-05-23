#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k;
  int n;
  int i;
  while (cin >> n >> k) {
    int d = n + 1;
    long long ara[d];
    long long t1 = 0, c = 0, t, temp = 0, is = 1;
    for (i = 1; i <= n; i++) cin >> ara[i];
    for (i = 1; i <= n; i++) {
      ara[i] = temp + ara[i];
      if (ara[i] >= k) {
        temp = ara[i] % k;
        c += ara[i] / k;
      } else if (ara[i] > 0 && temp > 0) {
        c += 1;
        temp = 0;
      } else {
        temp = ara[i];
      }
    }
    if (temp > 0)
      cout << c + 1 << endl;
    else
      cout << c << endl;
  }
  return 0;
}
