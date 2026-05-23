#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[2 * n];
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  int ct = 0, j;
  for (int i = 0; i < 2 * n; i++) {
    for (j = i + 1; j < 2 * n; j++) {
      if (a[j] == a[i]) break;
    }
    for (int k = j - 1; k > i; k--) {
      a[k + 1] = a[k];
      ct++;
    }
    i++;
  }
  cout << ct << endl;
}
