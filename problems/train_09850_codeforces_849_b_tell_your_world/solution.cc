#include <bits/stdc++.h>
using namespace std;
long long y[1010];
vector<int> line1, line2;
int main() {
  int n;
  cin >> n;
  int plan1 = 1, plan2 = 1, plan3 = 1;
  for (int i = 1; i <= n; i++) cin >> y[i];
  line1.push_back(1);
  line1.push_back(2);
  for (int i = 3; i <= n; i++) {
    if ((y[i] - y[1]) * (i - 2) == (y[i] - y[2]) * (i - 1))
      line1.push_back(1);
    else {
      if (line2.empty())
        line2.push_back(i);
      else {
        if ((y[i] - y[line2[0]]) * (2 - 1) == (y[2] - y[1]) * (i - line2[0]))
          line2.push_back(i);
        else {
          plan1 = 0;
        }
      }
    }
  }
  if (line2.empty()) {
    cout << "No" << endl;
    return 0;
  }
  if (plan1) {
    cout << "Yes" << endl;
    return 0;
  }
  line1.clear();
  line2.clear();
  line1.push_back(1);
  line2.push_back(2);
  line1.push_back(3);
  for (int i = 4; i <= n; i++) {
    if ((y[i] - y[1]) * (3 - 1) == (y[3] - y[1]) * (i - 1))
      line1.push_back(i);
    else if ((y[i] - y[2]) * (3 - 1) == (y[3] - y[1]) * (i - 2))
      line2.push_back(i);
    else {
      plan2 = 0;
    }
  }
  if (plan2) {
    cout << "Yes" << endl;
    return 0;
  }
  line1.clear();
  line2.clear();
  line1.push_back(1);
  line2.push_back(2);
  line2.push_back(3);
  for (int i = 4; i <= n; i++) {
    if ((y[i] - y[2]) * (3 - 2) == (y[3] - y[2]) * (i - 2))
      line1.push_back(i);
    else if ((y[i] - y[1]) * (3 - 2) == (y[3] - y[2]) * (i - 1))
      line2.push_back(i);
    else {
      plan3 = 0;
    }
  }
  if (plan3) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
