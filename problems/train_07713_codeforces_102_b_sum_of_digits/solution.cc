#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int c = 0;
  cin >> s;
  long long int n = 0, t;
  if (s.size() == 1) {
    cout << c;
    exit(0);
  }
  for (int i = 0; i < s.size(); ++i) {
    n += s[i] - '0';
  }
  c++;
  t = n;
  while (n / 10) {
    n = 0;
    while (t > 0) {
      n += t % 10;
      t /= 10;
    }
    c++;
    t = n;
  }
  cout << c << "\n";
}
