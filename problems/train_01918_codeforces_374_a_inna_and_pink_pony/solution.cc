#include <bits/stdc++.h>
using namespace std;
const int INF = ~0u >> 1;
int main() {
  int n, m, i, j, a, b;
  cin >> n >> m >> i >> j >> a >> b;
  int num = 10000000;
  if ((i + a <= n || i - a >= 1) && (j + b <= m || j - b >= 1)) {
    int cnta = i - 1;
    int cntb = j - 1;
    if (cnta % a == 0 && cntb % b == 0 &&
        (max(cnta / a, cntb / b) - min(cnta / a, cntb / b)) % 2 == 0) {
      num = min(num, max(cnta / a, cntb / b));
    }
    cnta = i - 1;
    cntb = m - j;
    if (cnta % a == 0 && cntb % b == 0 &&
        (max(cnta / a, cntb / b) - min(cnta / a, cntb / b)) % 2 == 0) {
      num = min(num, max(cnta / a, cntb / b));
    }
    cnta = n - i;
    cntb = j - 1;
    if (cnta % a == 0 && cntb % b == 0 &&
        (max(cnta / a, cntb / b) - min(cnta / a, cntb / b)) % 2 == 0) {
      num = min(num, max(cnta / a, cntb / b));
    }
    cnta = n - i;
    cntb = m - j;
    if (cnta % a == 0 && cntb % b == 0 &&
        (max(cnta / a, cntb / b) - min(cnta / a, cntb / b)) % 2 == 0) {
      num = min(num, max(cnta / a, cntb / b));
    }
  }
  if ((i == 1 || i == n) && (j == 1 || j == m)) num = 0;
  if (num != 10000000)
    cout << num << endl;
  else
    cout << "Poor Inna and pony!" << endl;
  return 0;
}
