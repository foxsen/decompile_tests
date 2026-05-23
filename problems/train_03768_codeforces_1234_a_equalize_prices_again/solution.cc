#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    long double sum = 0.0;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      sum += x;
    }
    long long result = ceil(sum / n);
    cout << result << endl;
  }
}
