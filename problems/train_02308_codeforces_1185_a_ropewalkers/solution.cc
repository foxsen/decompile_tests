#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);
  cout << max(0LL, 2 * d - min(d, (b - a)) - min(d, (c - b))) << '\n';
  return 0;
}
