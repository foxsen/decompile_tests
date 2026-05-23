#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  int i, j;
  cin >> a >> b;
  if (b.size() != a.size()) {
    cout << "NO";
    return 0;
  }
  for (i = 0; i < a.size(); i++)
    if (a[i] != '0') break;
  for (j = 0; j < b.size(); j++)
    if (b[j] != '0') break;
  if ((i == a.size() || j == b.size()) && i != j) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
