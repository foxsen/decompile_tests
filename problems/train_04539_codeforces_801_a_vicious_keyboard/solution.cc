#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[105];
  int book[105], sum = 0, su = 0;
  while (cin.getline(s, 105)) {
    memset(book, 0, sizeof(book));
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++) {
      if (s[i] == 'V' && s[i + 1] == 'K' && book[i] == 0 && book[i + 1] == 0) {
        book[i] = 1;
        book[i + 1] = 1;
        sum++;
      }
    }
    for (int i = 0; i < len - 1; i++) {
      if (s[i] == 'V' && s[i + 1] == 'V' && book[i] == 0 && book[i + 1] == 0 ||
          s[i] == 'K' && s[i + 1] == 'K' && book[i] == 0 && book[i + 1] == 0) {
        su++;
      }
    }
    if (su != 0) sum++;
    cout << sum << endl;
    sum = 0;
    su = 0;
  }
}
