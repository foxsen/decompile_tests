#include <bits/stdc++.h>
using namespace std;
string minEquivalent(string s) {
  if (s.length() % 2) return s;
  string s1 = minEquivalent(s.substr(0, s.length() / 2));
  string s2 = minEquivalent(s.substr(s.length() / 2, s.length() / 2));
  if (s1 < s2)
    return s1 + s2;
  else
    return s2 + s1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  if (minEquivalent(a) == minEquivalent(b)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
