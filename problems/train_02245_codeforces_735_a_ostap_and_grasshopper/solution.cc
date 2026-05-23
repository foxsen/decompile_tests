#include <bits/stdc++.h>
using namespace std;
char s[110];
int main() {
  int n, k, a, b, i, j;
  cin >> n >> k;
  getchar();
  for (i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] == 'G') {
      a = i;
    }
    if (s[i] == 'T') {
      b = i;
    }
  }
  if (b > a) {
    for (i = (a + k); i < n; i += k) {
      if (s[i] == '#') {
        cout << "NO";
        return 0;
      }
      if (i > b) {
        cout << "NO";
        return 0;
      }
      if (s[i] == 'T') {
        cout << "YES";
        return 0;
      }
    }
    cout << "NO";
  } else {
    for (i = a; i >= 0; i -= k) {
      if (s[i] == '#') {
        cout << "NO";
        return 0;
      }
      if (i < b) {
        cout << "NO";
        return 0;
      }
      if (s[i] == 'T') {
        cout << "YES";
        return 0;
      }
    }
    cout << "NO";
  }
  return 0;
}
