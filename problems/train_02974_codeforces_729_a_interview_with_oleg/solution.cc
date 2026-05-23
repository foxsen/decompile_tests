#include <bits/stdc++.h>
using namespace std;
int n;
string s, a[51];
void Filler() {
  a[1] = "ogo";
  for (int i = 2; i <= 50; ++i) a[i] = a[i - 1] + "go";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Filler();
  cin >> n;
  cin >> s;
  while (s.size() != 0) {
    if ((s[0] == 'o') && (s[1] == 'g') && (s[2] == 'o')) {
      int i = 1;
      while (s.find(a[i], 0) == 0) i++;
      s.erase(0, a[i - 1].size());
      cout << "***";
    } else {
      cout << s[0];
      s.erase(0, 1);
    }
  }
  return 0;
}
