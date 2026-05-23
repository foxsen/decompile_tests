#include <bits/stdc++.h>
using namespace std;
const int N = 100020;
const int mod = 1000000007;
int n;
int m;
int last[26];
int res[2000100];
int sum[2000100];
int k;
string s;
int main() {
  cin >> n >> k;
  cin >> s;
  n += (s.size());
  res[0] = 1;
  sum[1] = 1;
  for (int i = 1; i <= n; i++)
    if (i <= (s.size())) {
      res[i] = (sum[i] - sum[last[s[i - 1] - 'a']] + mod) % mod;
      sum[i + 1] = (sum[i] + res[i]) % mod;
      last[s[i - 1] - 'a'] = i;
    } else {
      int best = 0;
      for (int j = 0; j < k; j++)
        if (last[best] > last[j]) best = j;
      res[i] = (sum[i] - sum[last[best]] + mod) % mod;
      sum[i + 1] = (sum[i] + res[i]) % mod;
      last[best] = i;
    }
  printf("%d\n", sum[n + 1]);
  return 0;
}
