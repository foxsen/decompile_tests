#include <bits/stdc++.h>
using namespace std;
int a[50], b[50], n;
string s, s1;
char c, o;
bool u, v;
int k, kt, k2;
long long rs;
int main() {
  cin >> n;
  k2 = 26;
  while (n--) {
    cin >> c >> s;
    if (v && ((c == '!') || c == '?'))
      rs++;
    else {
      switch (c) {
        case '!': {
          k++;
          k2 = 0;
          for (int i = 0; i < s.size(); i++) {
            if (a[(int)s[i] - 'a'] == k - 1) {
              a[(int)s[i] - 'a'] = k;
              k2++;
            }
          }
          if (k2 == 1) {
            v = 1;
          }
          break;
        }
        case '.': {
          for (int i = 0; i < s.size(); i++) {
            if (a[(int)s[i] - 'a'] == k) k2--;
            a[(int)s[i] - 'a'] = -1;
          }
          if (k2 == 1) {
            v = 1;
          }
          break;
        }
        case '?': {
          if (a[(int)s[0] - 'a'] == k) {
            k2--;
            a[(int)s[0] - 'a'] = -1;
          }
          if (k2 == 1) {
            v = 1;
          }
          break;
        }
      }
    }
  }
  if (v) rs--;
  cout << rs;
  return 0;
}
