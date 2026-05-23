#include <bits/stdc++.h>
using namespace std;
int main() {
  int tot = 0, crime = 0, n = 0, x = 0;
  cin >> n;
  while (n--) {
    cin >> x;
    tot += x;
    if (tot < 0) {
      crime++;
      tot++;
    }
  }
  cout << crime << endl;
  return 0;
}
