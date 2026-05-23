#include <bits/stdc++.h>
using namespace std;
int cs[12];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int m, d;
  cin >> m >> d;
  int ans = 1;
  int mes = 30;
  if (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12)
    mes++;
  if (m == 2) mes = 28;
  for (int i = 1; i <= d; i++) cs[i]++;
  for (int i = 1; i < mes; i++) {
    cs[(i + d) % 7]++;
  }
  int ma = -10;
  for (int i = 0; i < 9; i++) {
    if (cs[i] > ma) ma = cs[i];
  }
  cout << ma << endl;
  return 0;
}
