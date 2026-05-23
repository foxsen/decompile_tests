#include <bits/stdc++.h>
using namespace std;
int main() {
  string q, s;
  char arr[3][10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                     'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
                     'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
  cin >> q >> s;
  int k, l;
  for (int i = 0; i < s.length(); i++) {
    for (k = 0; k < 3; k++) {
      for (l = 0; l < 10; l++)
        if (s[i] == arr[k][l]) {
          if (q == "R")
            cout << arr[k][l - 1];
          else
            cout << arr[k][l + 1];
        }
    }
  }
  puts("");
}
