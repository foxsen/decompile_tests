#include <bits/stdc++.h>
using namespace std;
template <class T>
string tostring(T x) {
  ostringstream out;
  out << x;
  return out.str();
}
long long toint(string s) {
  istringstream in(s);
  long long x;
  in >> x;
  return x;
}
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int kx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int ky[8] = {2, -2, 2, -2, 1, -1, 1, -1};
long long dp[2222][2222];
char buf[2222];
string s;
long long sum1[2222];
long long sum2[2222][2222];
bool used[2222];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", buf);
  s = string(buf);
  dp[n][0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= k; j++) {
      memset(used, false, sizeof(used));
      dp[i][j] = (s[i] - 'a') * dp[i + 1][j];
      if (j - (n - i) >= 0) dp[i][j] += ('z' - s[i]) * dp[i + 1][j - (n - i)];
      for (int l = n - 1; l > i; l--) {
        used[l] = true;
        if ((n - l) * (l - i + 1) <= j)
          dp[i][j] += ('z' - s[l]) * dp[l + 1][j - (n - l) * (l - i + 1)];
        else
          break;
      }
      for (int l = i + 1; l < n; l++) {
        if (used[l]) break;
        if ((n - l) * (l - i + 1) <= j)
          dp[i][j] += ('z' - s[l]) * dp[l + 1][j - (n - l) * (l - i + 1)];
        else
          break;
      }
      dp[i][j] += sum1[j];
      if (j == 0) dp[i][j]++;
      dp[i][j] %= 1000000007;
      sum1[j] = (sum1[j] + (s[i] - 'a') * dp[i + 1][j]) % 1000000007;
    }
  }
  cout << dp[0][k] << endl;
  return 0;
}
