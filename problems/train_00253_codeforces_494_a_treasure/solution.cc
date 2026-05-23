#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0, sl = 0;
  char s[100010];
  cin >> s;
  for (int i = 0; i < strlen(s); i++)
    if (s[i] == '#') {
      t++;
    } else if (s[i] == '(')
      sl++;
    else
      sl--;
  if (sl <= 0)
    cout << "-1";
  else {
    int t1 = 0, t2 = 0;
    for (int i = 0; i < strlen(s); i++) {
      if (s[i] == '#') {
        t1++;
        if (t1 != t) {
          t2--;
        } else
          t2 = t2 - sl + t - 1;
      } else if (s[i] == '(')
        t2++;
      else
        t2--;
      if (t2 < 0) {
        cout << "-1";
        return 0;
      }
    }
    for (int i = 1; i < t; i++) cout << '1' << endl;
    cout << sl - t + 1;
  }
}
