#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = (int)s.size();
  for (int i = 0; i < n; ++i) {
    char mx = s[i];
    int ind = -1;
    for (int j = i + 1; j < n && j - i <= k; ++j) {
      if (!k) {
        break;
      }
      if (mx < s[j]) {
        mx = s[j];
        ind = j;
      }
    }
    if (ind != -1) {
      for (int j = ind; j > i; j--) {
        swap(s[j], s[j - 1]);
        k--;
      }
    }
  }
  cout << s << endl;
  return 0;
}
