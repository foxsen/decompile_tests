#include <bits/stdc++.h>
using namespace std;
const int OO = INT_MAX;
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a;
  string b;
  cin >> a >> b;
  reverse(b.begin(), b.end());
  while (true) {
    a++;
    int x = a;
    string s;
    while (x > 0) {
      if (x % 10 == 7)
        s.push_back('7');
      else if (x % 10 == 4)
        s.push_back('4');
      x /= 10;
    }
    if (s == b) {
      cout << a << endl;
      return 0;
    }
  }
  return 0;
}
