#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  unsigned long long temp;
  unsigned long long ans = 0;
  unsigned long long minodd = 9999999999;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp % 2) {
      if (temp < minodd) minodd = temp;
    }
    ans += temp;
  }
  if (ans % 2) {
    ans = ans - minodd;
    if (ans % 2) {
      printf("0\n");
    } else {
      cout << ans << endl;
    }
  } else
    cout << ans << endl;
}
