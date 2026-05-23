#include <bits/stdc++.h>
using namespace std;
const long long N = 1003;
long long a, b, c, d, e, f, h, i, j;
long long g[N][N];
long long row[N * N], col[N * N], K, P;
long long an = -(1LL << 60);
void Init() {
  cin >> a >> b >> K >> P;
  for (long long ii = 1; ii <= a; ii++)
    for (long long jj = 1; jj <= b; jj++) scanf("%I64d", &g[ii][jj]);
}
void Work() {
  priority_queue<long long> Dui;
  for (long long ii = 1; ii <= a; ii++) {
    long long tt = 0;
    for (long long jj = 1; jj <= b; jj++) tt += g[ii][jj];
    Dui.push(tt);
  }
  for (long long ii = 1; ii <= K; ii++)
    row[ii] = Dui.top(), Dui.pop(), Dui.push(row[ii] - b * P);
  while (!Dui.empty()) Dui.pop();
  for (long long jj = 1; jj <= b; jj++) {
    long long tt = 0;
    for (long long ii = 1; ii <= a; ii++) tt += g[ii][jj];
    Dui.push(tt);
  }
  for (long long ii = 1; ii <= K; ii++)
    col[ii] = Dui.top(), Dui.pop(), Dui.push(col[ii] - a * P);
  for (long long ii = 1; ii <= K; ii++) row[ii] += row[ii - 1];
  for (long long ii = 1; ii <= K; ii++) col[ii] += col[ii - 1];
  for (long long ii = 0; ii <= K; ii++)
    an = max(an, row[ii] + col[K - ii] - ii * (K - ii) * P);
  cout << an << endl;
}
int main() {
  Init(), Work();
  return 0;
}
