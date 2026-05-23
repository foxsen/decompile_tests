#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  int i, x;
  set<char> b;
  getline(cin, a);
  for (i = 1; i < a.size() - 1; i += 3) {
    b.insert(a[i]);
  }
  cout << b.size() << endl;
  return 0;
}
