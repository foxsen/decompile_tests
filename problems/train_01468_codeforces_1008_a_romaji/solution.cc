#include <bits/stdc++.h>
using namespace std;
int dx[9] = {1, -1, 0, 0, 1, 1, -1, -1, 0};
int dy[9] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  int i, f = 1;
  cin >> s;
  if (s.length() == 1) {
    if (s.front() == 'a' || s.front() == 'e' || s.front() == 'i' ||
        s.front() == 'o' || s.front() == 'u' || s.front() == 'n')
      cout << "YES";
    else
      cout << "NO";
  } else {
    for (i = 0; i < s.length() - 1; i++) {
      if (s[i] != 'a' && s[i] != 'e' && s[i] != 'o' && s[i] != 'i' &&
          s[i] != 'u' && s[i] != 'n') {
        if (s[i + 1] != 'a' && s[i + 1] != 'e' && s[i + 1] != 'i' &&
            s[i + 1] != 'o' && s[i + 1] != 'u') {
          f = 0;
          break;
        } else
          continue;
      } else
        continue;
    }
    if (s.back() != 'a' && s.back() != 'e' && s.back() != 'i' &&
        s.back() != 'o' && s.back() != 'u' && s.back() != 'n')
      f = 0;
    if (f == 1)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
