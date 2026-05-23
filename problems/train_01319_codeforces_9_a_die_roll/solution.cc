#include <bits/stdc++.h>
using namespace std;
int y, w;
int main() {
  cin >> y >> w;
  int maxi = max(y, w);
  int past = (6 - maxi) + 1;
  double res = past * 1.0 / 6;
  if (res == 1) {
    cout << "1/1" << endl;
    return 0;
  }
  if (past == 5) {
    cout << past << "/6" << endl;
    return 0;
  }
  if (past == 4) {
    cout << "2/3" << endl;
    return 0;
  }
  cout << past / past << "/" << 6 / past << endl;
  return 0;
}
