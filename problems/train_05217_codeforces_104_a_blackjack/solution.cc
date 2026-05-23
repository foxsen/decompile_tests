#include <bits/stdc++.h>
using namespace std;
int a[12] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 15, 4};
int main() {
  int n, m = 0;
  cin >> n;
  if (n - 10 <= 0 || n - 10 >= 12)
    cout << 0 << endl;
  else
    cout << a[n - 10] << endl;
  return 0;
}
