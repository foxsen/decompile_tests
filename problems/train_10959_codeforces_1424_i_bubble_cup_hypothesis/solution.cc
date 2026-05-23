#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long x;
void answer() {
  cin >> x;
  cout << ((x / 4 + 1) % mod * ((x / 2 - x / 4 + 1) % mod) % mod) << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) answer();
  return 0;
}
