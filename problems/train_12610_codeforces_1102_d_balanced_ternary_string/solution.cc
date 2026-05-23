#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, c[3] = {0}, cc[3] = {0};
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.size(); ++i) {
    c[s[i] - '0']++;
  }
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < s[i] - '0'; ++j) {
      if (c[s[i] - '0'] > n / 3 && c[j] < n / 3) {
        c[s[i] - '0']--;
        c[j]++;
        s[i] = j + '0';
      }
    }
    cc[s[i] - '0']++;
    if (cc[s[i] - '0'] > n / 3) {
      for (int j = 0; j < 3; ++j) {
        if (c[j] < n / 3) {
          c[j]++;
          c[s[i] - '0']--;
          cc[s[i] - '0']--;
          cc[j]++;
          s[i] = j + '0';
          break;
        }
      }
    }
  }
  cout << s << endl;
}
