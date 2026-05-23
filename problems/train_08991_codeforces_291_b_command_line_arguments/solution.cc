#include <bits/stdc++.h>
using namespace std;
char c;
string s;
int main() {
  while (scanf("%c", &c) == true) {
    if (c == '\n') break;
    if (c == ' ') continue;
    if (c == '"') {
      s = "<";
      while (scanf("%c", &c) == true) {
        if (c == '"') {
          s += ">";
          break;
        } else
          s += c;
      }
      cout << s << endl;
      continue;
    }
    s = "<";
    s += c;
    while (scanf("%c", &c) == true) {
      if (c == '\n' || c == ' ') {
        s += ">";
        break;
      } else
        s += c;
    }
    cout << s << endl;
  }
}
