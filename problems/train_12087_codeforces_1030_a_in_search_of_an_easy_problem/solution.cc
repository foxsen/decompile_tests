#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    if (m == 1) {
      cout << "HARD";
      return 0;
    }
  }
  cout << "EASY";
}
