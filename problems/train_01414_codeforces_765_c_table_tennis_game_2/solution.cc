#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, a, b;
  cin >> k >> a >> b;
  long long int g1 = a / k;
  long long int g2 = b / k;
  long long int mod2 = b % k;
  long long int mod1 = a % k;
  if (mod1 != 0 && g2 == 0) {
    cout << "-1";
    return 0;
  }
  if (mod2 != 0 && g1 == 0) {
    cout << "-1";
    return 0;
  }
  cout << g1 + g2;
  return 0;
}
