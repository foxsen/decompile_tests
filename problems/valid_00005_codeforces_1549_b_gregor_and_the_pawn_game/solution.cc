#include <bits/stdc++.h>
using namespace std;
int T;
int n;
string s1, s2;
int main(int argc, char *argv[]) {
  cin >> T;
  while (T--) {
    int ans = 0;
    cin >> n;
    std::cin >> s1;
    std::cin >> s2;
    for (int i = 1; i <= n; i++) {
      if (s1[i - 1] == '1') {
        if (i - 1 == 0) {
          if (s2[i] == '1') {
            ans++;
            s2[i] = '0';
          }
        } else {
          if (s2[i - 2] == '1') {
            ans++;
            s2[i - 2] = '0';
          } else if (s2[i] == '1') {
            ans++;
            s2[i] = '0';
          }
        }
      } else if (s1[i - 1] == '0') {
        if (s2[i - 1] == '1') {
          ans++;
          s2[i - 1] = '0';
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
