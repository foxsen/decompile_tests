#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int i = 0, count = 0;
    while (s[i] != '\0') {
      count++;
      i++;
    }
    if (s[count - 2] == 's' && s[count - 1] == 'u') cout << "JAPANESE" << endl;
    if (s[count - 2] == 'p' && s[count - 1] == 'o') cout << "FILIPINO" << endl;
    if (s[count - 2] == 'd' && s[count - 1] == 'a') cout << "KOREAN" << endl;
  }
}
