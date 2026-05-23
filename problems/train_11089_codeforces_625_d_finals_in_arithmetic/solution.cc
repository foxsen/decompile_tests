#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int a[100005];
int main() {
  T = 1;
  while (T--) {
    cin >> s;
    for (int i = 0; i < s.size(); ++i) a[i] = s[i] - '0';
    int l = 0, r = s.size() - 1;
    if (a[l] != a[r]) {
      a[l]--;
      a[l + 1] += 10;
      if (!a[l]) l++;
    }
    while (l <= r) {
      if (a[l] != a[r]) {
        if (a[l] - a[r] >= 10 && a[r] < 10) a[r] += 10, a[r - 1]--;
        if (a[l] - a[r] == 1) a[l]--, a[l + 1] += 10;
      }
      if (a[l] != a[r]) break;
      if (l == r) {
        if (a[l] % 2 == 0)
          a[l] /= 2;
        else
          break;
      } else {
        a[r] /= 2;
        a[l] -= a[r];
      }
      if (a[l] < 0 || a[l] > 9 || a[r] < 0 || a[r] > 9) break;
      l++;
      r--;
    }
    if (l <= r)
      printf("0");
    else {
      if (a[0]) cout << a[0];
      for (int i = 1; i < s.size(); ++i) printf("%d", a[i]);
    }
  }
}
