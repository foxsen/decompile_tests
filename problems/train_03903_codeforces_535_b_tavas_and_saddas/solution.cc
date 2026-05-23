#include <bits/stdc++.h>
using namespace std;
int abs(int a) { return a < 0 ? -a : a; }
int main() {
  string str;
  cin >> str;
  int n = str.size();
  int res = (1 << n) - 1;
  int p = 0;
  for (int i = n - 1; i >= 0; --i) {
    res += (str[i] == '7') * (1 << p);
    p++;
  }
  printf("%d\n", res);
  return 0;
}
