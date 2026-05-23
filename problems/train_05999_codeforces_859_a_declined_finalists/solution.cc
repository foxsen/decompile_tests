#include <bits/stdc++.h>
using namespace std;
int bitt = 0;
int main() {
  int n;
  cin >> n;
  int maxi = 0;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    maxi = max(maxi, x);
  }
  cout << max(0, maxi - 25) << endl;
}
