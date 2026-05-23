#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-11;
const int inf = 1e9 + 99;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int i = 0, j = n - 1, z = 0;
  for (; i < n && s[i] == '<';) ++i, ++z;
  for (; j >= 0 && s[j] == '>';) --j, ++z;
  cout << z << endl;
}
