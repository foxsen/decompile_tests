#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> t, g;
int main() {
  int n, k, sz;
  cin >> n >> k;
  cin >> s;
  if (n == 1 || k == 0) {
    cout << s << endl;
    return 0;
  }
  s = "a" + s;
  sz = s.size();
  for (int i = 1; i < s.size(); i++) {
    if (k == 0) break;
    if (s[i] == '4' && s[i + 1] == '7') {
      if (i % 2 == 1 && i + 2 < sz && s[i + 2] == '7') {
        k = k % 2;
        if (k == 1) s[i + 1] = '4';
        break;
      } else if (i % 2 == 0 && i - 1 >= 0 && s[i - 1] == '4') {
        k = k % 2;
        if (k == 1) s[i] = '7';
        break;
      } else {
        if (i % 2)
          s[i] = s[i + 1] = '4';
        else
          s[i] = s[i + 1] = '7';
        k--;
      }
    }
  }
  for (int i = 1; i < s.size(); i++) cout << s[i];
  puts("");
  return 0;
}
