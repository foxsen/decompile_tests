#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastio();
  long long int n, i, k, j;
  cin >> n;
  string s;
  long long int count = 0;
  cin >> s;
  for (i = 1; i <= n - 1; i++) {
    if (i == n - 1) {
      if (s[i] == s[i - 1]) {
        count++;
        if (s[i - 1] == 'G')
          s[i] = 'R';
        else if (s[i - 1] == 'R')
          s[i] = 'G';
        else if (s[i - 1] == 'B')
          s[i] = 'R';
      }
    } else if (s[i] == s[i - 1]) {
      count++;
      if (s[i - 1] == 'G') {
        if (s[i + 1] == 'R')
          s[i] = 'B';
        else
          s[i] = 'R';
      } else if (s[i - 1] == 'B') {
        if (s[i + 1] == 'R')
          s[i] = 'G';
        else
          s[i] = 'R';
      } else if (s[i - 1] == 'R') {
        if (s[i + 1] == 'G')
          s[i] = 'B';
        else
          s[i] = 'G';
      }
    }
  }
  cout << count << endl;
  cout << s << endl;
  return 0;
}
