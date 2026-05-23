#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = 1;
  bool check = 0;
  while (1) {
    if (ans >= a && ans <= b) {
      cout << (long long)ans << " ";
      check = 1;
    }
    if (b / ans < c) break;
    ans = ans * c;
  }
  if (!check) puts("-1");
  return 0;
}
