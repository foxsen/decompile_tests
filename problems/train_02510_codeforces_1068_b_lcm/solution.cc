#include <bits/stdc++.h>
using namespace std;
int main() {
  long long b;
  cin >> b;
  int ans = 0;
  for (int i = 1; i <= sqrt(b); i++)
    if (b % i == 0) ++ans;
  ans *= 2;
  long long t = sqrt(b);
  if (t * t == b) --ans;
  cout << ans;
}
