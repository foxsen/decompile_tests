#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a = 0, b = 0;
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'X')
      a++;
    else
      b++;
  }
  if (a == b) {
    cout << 0 << endl;
    cout << str;
  } else if (a > b) {
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'X') {
        a--;
        b++;
        str[i] = 'x';
        cnt++;
      }
      if (a == b) break;
    }
    cout << cnt << endl;
    cout << str;
  } else {
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'x') {
        a++;
        b--;
        str[i] = 'X';
        cnt++;
      }
      if (a == b) break;
    }
    cout << cnt << endl;
    cout << str;
  }
}
