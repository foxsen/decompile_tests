#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long maxi = LLONG_MIN;
  for (long long i = 1LL; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    maxi = max(maxi, x + y);
  }
  cout << maxi << endl;
}
