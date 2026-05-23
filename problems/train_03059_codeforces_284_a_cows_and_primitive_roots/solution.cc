#include <bits/stdc++.h>
using namespace std;
int main() {
  int p;
  cin >> p;
  int t;
  int flag = 0;
  int ans = 0;
  for (int i = 1; i < p; i++) {
    t = i;
    for (int j = 1; j <= p - 2; j++) {
      if ((t - 1) % p != 0) {
        t = (t % p) * i;
      } else {
        flag = 1;
        break;
      }
    }
    if (flag == 0 && (t - 1) % p == 0) {
      ans++;
    }
    flag = 0;
  }
  cout << ans;
}
