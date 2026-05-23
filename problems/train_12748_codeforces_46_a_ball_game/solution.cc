#include <bits/stdc++.h>
using namespace std;
int static fast = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();
int main() {
  long long n;
  cin >> n;
  long long add = 1, pos = 0;
  for (int i = 0; i < n - 1; i++) {
    pos += add;
    pos %= n;
    cout << (pos + 1) << " ";
    add += 1;
  }
  return 0;
}
