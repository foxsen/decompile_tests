#include <bits/stdc++.h>
using namespace std;
char s[105];
void judge(int l) {
  for (int i = l - 1; i >= 0; i--) {
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
      if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
          s[i] == 'U' || s[i] == 'Y' || s[i] == 'a' || s[i] == 'e' ||
          s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      return;
    }
  }
}
int main() {
  gets(s);
  int l = strlen(s);
  judge(l);
}
