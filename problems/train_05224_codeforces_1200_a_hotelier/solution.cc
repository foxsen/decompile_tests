#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n;
  cin >> n;
  string s;
  long long int b[10] = {0};
  cin >> s;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      for (long long int j = 0; j < 10; j++) {
        if (b[j] == 0) {
          b[j] = 1;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (long long int j = 9; j >= 0; j--) {
        if (b[j] == 0) {
          b[j] = 1;
          break;
        }
      }
    } else {
      int x = int(s[i] - '0');
      b[x] = 0;
    }
  }
  for (int i = 0; i < 10; i++) cout << b[i];
}
