#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "Yes";
    return 0;
  }
  string a;
  cin >> a;
  int b[125] = {0};
  for (int i = 0; i < n; i++) {
    b[a[i]]++;
  }
  for (int i = 97; i <= 122; i++) {
    if (b[i] >= 2) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
