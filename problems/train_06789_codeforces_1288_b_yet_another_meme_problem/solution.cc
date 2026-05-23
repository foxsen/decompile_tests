#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long p) {
  long long j = 1;
  while (p--) j *= x;
  return j;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  cin >> test;
  while (test > 0) {
    long long a, b, cnt = 0, i, flag = 0, x, t;
    cin >> a >> b;
    x = b;
    for (; b > 0; b = b / 10) cnt++;
    for (i = 1; i <= cnt + 1; i++) {
      long long t = power(10, i) - 1;
      if (t == x) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      cout << a * cnt << endl;
    } else
      cout << a * (cnt - 1) << endl;
    test--;
  }
  return 0;
}
