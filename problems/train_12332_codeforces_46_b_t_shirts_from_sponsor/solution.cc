#include <bits/stdc++.h>
using namespace std;
int a[5], t;
string e[5] = {"S", "M", "L", "XL", "XXL"}, s;
int p() {
  if (s == "S") return 0;
  if (s == "M") return 1;
  if (s == "L") return 2;
  if (s == "XL") return 3;
  if (s == "XXL") return 4;
}
int main() {
  for (int i = (0); i < (5); i++) cin >> a[i];
  cin >> t;
  while (t--) {
    cin >> s;
    int x = p();
    for (int i = (0); i < (5); i++) {
      if (x + i < 5 && a[x + i] > 0) {
        x += i;
        break;
      }
      if (x - i >= 0 && a[x - i] > 0) {
        x -= i;
        break;
      }
    }
    cout << e[x] << endl;
    a[x]--;
  }
  return 0;
}
