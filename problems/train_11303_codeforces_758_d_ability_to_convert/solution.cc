#include <bits/stdc++.h>
using namespace std;
int n;
string x;
int main() {
  cin >> n >> x;
  long long pn = 1;
  long long ans = 0;
  for (int i = x.size() - 1; i >= 0;) {
    long long val, up;
    val = x[i] - '0';
    up = 10;
    int j = i - 1;
    int lst = i;
    while (j >= 0 && (x[j] - '0') * up + val < n) {
      if (x[j] != '0') lst = j;
      val = (x[j--] - '0') * up + val, up *= 10;
      if (up > n) break;
    }
    ans += pn * val;
    pn *= n;
    i = lst - 1;
  }
  cout << ans << '\n';
  return 0;
}
