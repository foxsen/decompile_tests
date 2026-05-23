#include <bits/stdc++.h>
using namespace std;
int main() {
  int m;
  cin >> m;
  int c[m];
  int sum1 = 0;
  for (int i = 0; i < m; i++) {
    cin >> c[i];
    sum1 += c[i];
  }
  int x, y;
  cin >> x >> y;
  int flag = 0;
  int k = 1;
  int sum2 = 0;
  if (sum2 >= x && sum2 <= y && sum1 - sum2 >= x && sum1 - sum2 <= y) {
    flag = 1;
    cout << "1" << endl;
  } else {
    for (int i = 1; i <= m; i++) {
      k = i;
      sum2 += c[i - 1];
      if (sum2 >= x && sum2 <= y && sum1 - sum2 >= x && sum1 - sum2 <= y) {
        flag = 1;
        cout << i + 1 << endl;
        break;
      }
    }
  }
  if (flag == 0) {
    cout << "0" << endl;
  }
  return 0;
}
