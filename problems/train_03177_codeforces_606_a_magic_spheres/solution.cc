#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3], b[3], x = 0, y = 0;
  for (int i = 0; i < 3; i++) cin >> a[i];
  for (int i = 0; i < 3; i++) cin >> b[i];
  for (int i = 0; i < 3; i++)
    if (a[i] >= b[i])
      x += (a[i] - b[i]) / 2;
    else
      y += (b[i] - a[i]);
  if (x >= y)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
