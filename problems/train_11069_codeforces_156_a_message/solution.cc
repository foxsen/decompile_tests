#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int k = 0;
  string star = "*";
  for (int i = 0; i < 12; i++) star = star + star;
  a = star + a + star;
  int res = 3000;
  for (int i = 0; i < a.size(); i++) {
    int u = 0;
    for (int j = 0; j < b.size(); j++)
      if (a[i + j] != b[j]) u++;
    res = min(res, u);
  }
  cout << res << endl;
  return 0;
}
