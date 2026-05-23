#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s[6] == '1' || s[6] == '3' || s[6] == '5' || s[6] == '7' || s[6] == '9') {
    cout << 1;
  } else
    cout << 0;
}
