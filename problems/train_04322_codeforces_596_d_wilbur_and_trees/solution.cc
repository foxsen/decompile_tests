#include <bits/stdc++.h>
using namespace std;
int n, i, j, l[2002], r[2002];
long double p, h, x[2002];
bool mark[2002][2002][2][2];
long double dp[2002][2002][2][2], z = 0.5;
void rec(int s, int e, int f1, int f2) {
  if (mark[s][e][f1][f2]) return;
  long double answ = 0;
  mark[s][e][f1][f2] = true;
  rec(s + 1, e, 0, f2);
  if (f1 == 0)
    answ += z * p * (min(h, x[s] - x[s - 1]) + dp[s + 1][e][0][f2]);
  else
    answ += z * p * (min(h, x[s] - x[s - 1] - h) + dp[s + 1][e][0][f2]);
  rec(s, e - 1, f1, 0);
  if (f2 == 0)
    answ += z * (1 - p) * (min(h, x[e + 1] - x[e]) + dp[s][e - 1][f1][0]);
  else
    answ += z * (1 - p) * (min(h, x[e + 1] - x[e] - h) + dp[s][e - 1][f1][0]);
  if (r[s] > e)
    answ += z * (1 - p) * (x[e] - x[s] + min(h, x[e + 1] - x[e] - f2 * h));
  else {
    rec(r[s], e, 1, f2);
    answ += z * (1 - p) * (x[r[s] - 1] - x[s] + h + dp[r[s]][e][1][f2]);
  }
  if (l[e] < s)
    answ += z * p * (x[e] - x[s] + min(h, x[s] - x[s - 1] - f1 * h));
  else {
    rec(s, l[e], f1, 1);
    answ += z * p * (x[e] - x[l[e] + 1] + h + dp[s][l[e]][f1][1]);
  }
  dp[s][e][f1][f2] = answ;
}
int main() {
  cout.setf(ios::fixed);
  cout.precision(8);
  cin >> n >> h >> p;
  for (i = 1; i <= n; i++) {
    cin >> x[i];
  }
  if (n == 1) {
    cout << h << endl;
    return 0;
  }
  sort(x + 1, x + n + 1);
  x[0] = -1000000000.0;
  x[n + 1] = 1000000000.0;
  for (i = 1; i <= n; i++) {
    dp[i][i][0][0] =
        p * (min(h, x[i] - x[i - 1])) + (1 - p) * (min(h, x[i + 1] - x[i]));
    dp[i][i][1][1] = p * (min(h, x[i] - x[i - 1] - h)) +
                     (1 - p) * (min(h, x[i + 1] - x[i] - h));
    dp[i][i][0][1] =
        p * (min(h, x[i] - x[i - 1])) + (1 - p) * (min(h, x[i + 1] - x[i] - h));
    dp[i][i][1][0] =
        p * (min(h, x[i] - x[i - 1] - h)) + (1 - p) * (min(h, x[i + 1] - x[i]));
    mark[i][i][0][0] = true;
    mark[i][i][1][1] = true;
    mark[i][i][0][1] = true;
    mark[i][i][1][0] = true;
  }
  for (i = 1; i <= n; i++) {
    j = i + 1;
    while (j <= n && x[j] - x[j - 1] < h) j++;
    r[i] = j;
  }
  for (i = n; i >= 1; i--) {
    j = i - 1;
    while (j >= 1 && x[j + 1] - x[j] < h) j--;
    l[i] = j;
  }
  mark[0][0][0][0] = true;
  mark[0][0][1][1] = true;
  mark[0][0][0][1] = true;
  mark[0][0][1][0] = true;
  mark[n + 1][n + 1][0][0] = true;
  mark[n + 1][n + 1][1][1] = true;
  mark[n + 1][n + 1][0][1] = true;
  mark[n + 1][n + 1][1][0] = true;
  rec(1, n, 0, 0);
  cout << dp[1][n][0][0] << endl;
  return 0;
}
