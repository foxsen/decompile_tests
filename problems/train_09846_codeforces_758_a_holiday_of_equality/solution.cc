#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mx, sum;
  mx = sum = 0;
  cin >> n;
  int abc[n];
  for (int i = 0; i < n; i++) {
    cin >> abc[i];
    if (mx < abc[i]) mx = abc[i];
  }
  for (int k = 0; k < n; k++) {
    sum = sum + (mx - abc[k]);
  }
  cout << sum << endl;
  return 0;
}
