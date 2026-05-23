#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int ar[n * k];
    for (int i = 0; i < n * k; i++) cin >> ar[i];
    int step = n - ((n + 1) / 2);
    long long int sum = 0;
    n = n * k;
    int i = n - step - 1;
    while (k--) {
      sum += ar[i];
      i = i - step - 1;
    }
    cout << sum << endl;
  }
  return 0;
}
