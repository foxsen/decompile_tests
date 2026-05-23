#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, i, k;
  cin >> n >> t;
  string s;
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == '.') break;
  }
  if (i == n) {
    cout << s << endl;
    return 0;
  }
  i++;
  for (k = i; k < n; k++) {
    if (s[k] >= '5') break;
  }
  if (k == n) {
    cout << s << endl;
    return 0;
  }
  k--;
  int end, flag = 0;
  if (s[k] != '.') {
    while (t > 0 && k >= i && s[k + 1] >= '5') {
      s[k] += 1;
      k--;
      t--;
    }
    end = k + 1;
    if (s[k] == '.' && t != 0) {
      if (s[k + 1] >= '5') {
        flag = 1;
        end = k - 1;
      }
    }
  } else {
    end = k - 1;
    flag = 1;
  }
  s = s.substr(0, end + 1);
  int end_s = i - 2;
  if (t > 0 && flag == 1) {
    while (end_s >= 0 && s[end_s] == '9') {
      s[end_s] = '0';
      end_s--;
    }
    if (end_s == -1)
      s = '1' + s;
    else
      s[end_s]++;
  }
  cout << s << endl;
  return 0;
}
