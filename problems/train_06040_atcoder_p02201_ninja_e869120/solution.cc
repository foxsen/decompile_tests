#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int res = 0;
  while (n--) {
    string s;
    cin >> s;
    res += s == "E869120";
  }
  cout << res << '\n';
}

