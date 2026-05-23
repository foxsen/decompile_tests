#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1[4];
  for (int i = 0; i < 4; i++) cin >> a1[i];
  bool a = 1, g = 1;
  for (int i = 2; i < 4; i++) {
    if (a1[i] - a1[i - 1] != a1[i - 1] - a1[i - 2]) a = 0;
    if (a1[i] * 1.0 / a1[i - 1] != a1[i - 1] * 1.0 / a1[i - 2]) g = 0;
  }
  if (!a && !g)
    cout << "42\n";
  else if (!a) {
    if ((a1[3] * a1[2]) % a1[1])
      cout << 42 << endl;
    else
      cout << a1[3] * a1[2] / a1[1] << endl;
  } else
    cout << a1[3] + a1[2] - a1[1] << endl;
}
