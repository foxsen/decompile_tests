#include <bits/stdc++.h>
using namespace std;
const long long A = 100000000000000LL, N = 10000;
long long x[2], y[2], o[2], i, j, n, m;
int main() {
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  o[0] = x[0] + y[0], o[1] = max(x[1], y[1]);
  if (o[0] <= o[1])
    cout << "Polycarp\n";
  else if (x[0] <= x[1] && y[0] <= y[1])
    cout << "Polycarp\n";
  else
    cout << "Vasiliy\n";
}
