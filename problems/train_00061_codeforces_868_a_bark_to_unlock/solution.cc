#include <bits/stdc++.h>
using namespace std;
char s[101][3];
int main() {
  int n, i, k = 0, c1 = 0, c2 = 0;
  cin.get(s[0], 3);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin.get();
    cin.get(s[i], 3);
  }
  for (i = 1; i <= n && k < 2; i++) {
    if (s[0][0] == s[i][1] && c1 == 0) {
      k++;
      c1 = 1;
    }
    if (s[0][1] == s[i][0] && c2 == 0) {
      k++;
      c2 = 1;
    }
    if (strcmp(s[0], s[i]) == NULL) k = 2;
  }
  if (k == 2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
