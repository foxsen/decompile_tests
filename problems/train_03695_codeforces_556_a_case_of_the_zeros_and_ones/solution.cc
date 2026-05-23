#include <bits/stdc++.h>
using namespace std;
char c;
int sz, a0, a1;
int main() {
  cin >> sz;
  for (int i = 0; i < sz; i++) {
    cin >> c;
    if (c == '0')
      a0++;
    else
      a1++;
  }
  cout << max(a1, a0) - min(a1, a0);
  return 0;
}
