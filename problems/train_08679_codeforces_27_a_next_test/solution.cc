#include <bits/stdc++.h>
using namespace std;
int T[3002];
int main() {
  int n, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    T[t] = 1;
  }
  for (int i = 1; i <= 3001; i++)
    if (T[i] == 0) {
      cout << i << "\n";
      break;
    }
  return 0;
}
