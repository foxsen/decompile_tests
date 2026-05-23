#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  cin >> n;
  vector<int> tm;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;
    int sum = a + b + c + d;
    tm.push_back(sum);
  }
  int john = tm[0];
  sort(tm.begin(), tm.end());
  for (int i = n - 1; i >= 0; i--) {
    if (tm[i] == john) {
      cout << n - i;
      return 0;
    }
  }
}
