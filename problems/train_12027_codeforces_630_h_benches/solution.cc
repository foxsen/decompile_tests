#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans = 1;
  for (int i = 0; i < 5; i++) ans *= (n - i);
  long long tmp = ans;
  for (int i = 1; i <= 5; i++) ans /= i;
  cout << ans * tmp;
  return 0;
}
