#include <bits/stdc++.h>
using namespace std;
long long int counter[2][((long long int)(1 << 20) + 2)];
int main() {
  counter[1][0] = 1;
  long long int n;
  cin >> n;
  long long int x = 0;
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    long long int f;
    cin >> f;
    x ^= f;
    ans += counter[i % 2][x];
    counter[i % 2][x]++;
  }
  cout << ans;
  return 0;
}
