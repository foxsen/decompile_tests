#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long sum = 0;
    int j = (n - 1) / 2;
    for (int i = 0; i < j; i++) {
      sum += pow(i + 1, 2) * 8;
    }
    cout << sum << "\n";
  }
}
