#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k = 1, l = 1;
  cin >> n;
  for (int i = 0; i < 3 * n - 3; i++) {
    l *= 3;
    l = l % 1000000007;
  }
  l *= 27;
  for (int i = 0; i < n; i++) {
    k *= 7;
    k = k % 1000000007;
  }
  cout << (l - k) % 1000000007;
}
