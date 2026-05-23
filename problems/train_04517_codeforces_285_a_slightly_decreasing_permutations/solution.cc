#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, k = 0;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cout << (n - i) << " ";
  }
  cout << "1 ";
  for (int i = 2; i <= n - k; ++i) {
    cout << i << " ";
  }
  cout << " \n ";
  return 0;
}
