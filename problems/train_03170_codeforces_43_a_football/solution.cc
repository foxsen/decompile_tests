#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, s;
  while (cin >> t) {
    string a[1005];
    for (int i = 0; i < t; i++) {
      cin >> a[i];
    }
    sort(a, a + t);
    cout << a[t / 2] << endl;
  }
}
