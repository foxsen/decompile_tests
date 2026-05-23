#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<char> t(300, 0);
  int p, n;
  cin >> p >> n;
  int col = -1;
  for (int i = 0; i < n; ++i) {
    int z;
    cin >> z;
    z %= p;
    if (t[z] && col == -1) {
      col = i + 1;
    }
    t[z] = 1;
  }
  cout << col;
  return 0;
}
