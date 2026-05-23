#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int Max = 1e6 + 100;
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    Max = min(Max, r - l + 1);
  }
  cout << Max << endl;
  int sign = 0;
  for (int i = 0; i < n; i++) {
    cout << sign << " ";
    sign++;
    sign = sign % Max;
  }
  cout << endl;
  return 0;
}
