#include <bits/stdc++.h>
using namespace std;
int i, j, k, q, s, a, b, c, n, m, mej, q1, q2;
int main() {
  cin >> n >> m;
  if (n == 1) {
    cout << (m + 1) / 2 << endl;
    return 0;
  }
  if (m == 2) {
    for (i = 1; i <= n; i++) {
      if (q % 2 == 0) {
        cout << 1 << endl;
        q++;
        continue;
      } else {
        cout << 2 << endl;
        q++;
        continue;
      }
    }
    return 0;
  }
  if (m % 2 == 1) {
    mej = (m + 1) / 2;
    cout << mej << endl;
    for (i = 1; i < n; i++) {
      if (q % 2 == 0) {
        q1++;
        if (mej - q1 > 0) {
          cout << mej - q1 << endl;
          q++;
          continue;
        } else {
          cout << mej << endl;
          q = 0;
          q1 = 0;
          q2 = 0;
          continue;
        }
      } else {
        q2++;
        if (mej + q2 <= m) {
          cout << mej + q2 << endl;
          q++;
          continue;
        } else {
          cout << mej << endl;
          q = 0;
          q1 = 0;
          q2 = 0;
          continue;
        }
      }
    }
    return 0;
  }
  int mek = m / 2;
  int pop = mek;
  int erku = mek + 1;
  for (i = 1; i <= n / 2; i++) {
    if (mek != 0) {
      cout << mek << endl;
      cout << erku << endl;
      mek--;
      erku++;
      continue;
    } else {
      mek = pop;
      erku = pop + 1;
      cout << mek << endl;
      cout << erku << endl;
      mek--;
      erku++;
    }
  }
  if (n % 2 == 1) {
    if (mek == 0) {
      cout << pop << endl;
      return 0;
    } else {
      cout << mek << endl;
      return 0;
    }
  }
  return 0;
}
