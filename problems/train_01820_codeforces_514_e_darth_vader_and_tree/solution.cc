#include <bits/stdc++.h>
using namespace std;
long long n, x;
const long long MAXN = 222222;
const long long mod = 1e9 + 7;
long long a[MAXN],
    cnt[MAXN] =
        {
            0,
},
    dp[120] = {
        0,
};
void preProcess() {
  dp[0] = 1;
  for (long long i = 1; i <= 100; i++) {
    for (long long j = 0; j < i; j++) {
      dp[i] += dp[j] * cnt[i - j];
      dp[i] %= mod;
    }
  }
}
void makeMatrix(long long r, long long c, vector<vector<long long> > &m) {
  m.resize(r);
  for (long long i = 0; i < r; i++) m[i].resize(c);
}
vector<vector<long long> > unit(long long r, long long c) {
  vector<vector<long long> > temp;
  makeMatrix(r, c, temp);
  for (long long i = 0; i < r; i++)
    for (long long j = 0; j < c; j++) {
      temp[i][j] = (i == j) ? 1 : 0;
    }
  return temp;
}
vector<vector<long long> > mul(vector<vector<long long> > &a,
                               vector<vector<long long> > &b) {
  vector<vector<long long> > temp;
  makeMatrix((long long)a.size(), (long long)b[0].size(), temp);
  for (long long i = 0; i < a.size(); i++) {
    for (long long j = 0; j < a[0].size(); j++) {
      for (long long k = 0; k < b.size(); k++) {
        temp[i][j] += a[i][k] * b[k][j];
        temp[i][j] %= mod;
      }
    }
  }
  return temp;
}
vector<vector<long long> > Pow(long long n, vector<vector<long long> > c) {
  vector<vector<long long> > u;
  u = unit(101, 101);
  long long i = 0;
  while (n) {
    if (n & (1 << i)) {
      n -= (1 << i);
      u = mul(u, c);
    }
    c = mul(c, c);
    i++;
  }
  return u;
}
int main() {
  cin >> n >> x;
  memset(dp, 0, sizeof(dp));
  for (long long i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
  preProcess();
  long long sum = 0;
  if (x <= 100) {
    for (long long i = 0; i <= x; i++) {
      sum += dp[i];
      sum %= mod;
    }
    cout << sum;
    exit(0);
  }
  sum = 0;
  for (int i = 0; i <= 100; i++) {
    sum += dp[i];
    sum %= mod;
  }
  vector<vector<long long> > w, ans;
  makeMatrix(101, 101, w);
  w[100][100] = 1;
  for (long long i = 0; i <= 98; i++) w[i][i + 1] = 1;
  for (long long i = 0; i <= 99; i++)
    w[99][i] = cnt[100 - i], w[100][i] = cnt[100 - i];
  ans = Pow(x - 100, w);
  sum *= ans[100][100];
  for (int i = 0; i < 100; i++) {
    sum += (dp[i + 1] % mod) * (ans[100][i] % mod);
    sum %= mod;
  }
  cout << sum;
  return 0;
}
