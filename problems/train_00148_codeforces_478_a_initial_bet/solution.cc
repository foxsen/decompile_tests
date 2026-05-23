#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[5], sum = 0;
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
    sum += a[i];
  }
  n = sum / 5;
  if (sum == 0)
    cout << -1;
  else if (n * 5 == sum)
    cout << n;
  else
    cout << -1;
  return 0;
}
