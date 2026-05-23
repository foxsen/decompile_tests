#include <bits/stdc++.h>
using namespace std;
string solve() {
  string a, s, b = "";
  cin >> a >> s;
  reverse(a.begin(), a.end());
  reverse(s.begin(), s.end());
  int k = 0;
  for (int i = 0; i < a.size(); i++) {
    if (i + k >= s.size()) {
      return "-1";
    }
    if (a[i] == s[i + k]) {
      b = "0" + b;
    }
    if (a[i] < s[i + k]) {
      char h = s[i + k] - a[i] + 48;
      b = h + b;
    }
    if (a[i] > s[i + k]) {
      if (i + k == s.size() - 1) return "-1";
      string b1 = s.substr(i + k, 2);
      reverse(b1.begin(), b1.end());
      int h = stoi(b1) - (a[i] - 48);
      if (h >= 10 || h < 0) return "-1";
      b = to_string(h) + b;
      k++;
    }
  }
  if (a.size() + k < s.size()) {
    string h = s.substr(a.size() + k, s.size() - a.size() - k);
    reverse(h.begin(), h.end());
    b = h + b;
  }
  while (b[0] == '0' && b.size() > 1) {
    b.erase(0, 1);
  }
  return b;
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    cout << solve() << endl;
    t--;
  }
  return 0;
}
