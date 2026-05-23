#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
inline long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
}
long long fac[200005];
void FacGen() {
  fac[0] = 1;
  for (int i = 1; i <= 200000; i++) fac[i] = (fac[i - 1] * i) % MOD;
}
long long COM(long long a, long long b) {
  if (a < b) return 0;
  return ((fac[a] * BigMod((fac[b] * fac[a - b]) % MOD, MOD - 2, MOD)) % MOD +
          MOD) %
         MOD;
}
long long prefix[200005], cum[200005];
string str;
long long n, k;
vector<pair<int, int> > v;
int main() {
  FacGen();
  cin >> n >> k;
  cin >> str;
  long long answer = 0;
  long long al = 0;
  for (int i = n - 1; i >= 1; i--) {
    al = (al + BigMod(10, n - i - 1, MOD) * COM(i - 1, k - 1)) % MOD;
    long long dig = str[i - 1] - '0';
    answer = (answer + al * dig) % MOD;
    answer =
        answer + (((COM(i - 1, k) * dig) % MOD) * BigMod(10, n - i, MOD)) % MOD;
    answer %= MOD;
  }
  answer += (str.back() - '0') * COM(n - 1, k);
  answer %= MOD;
  cout << answer << endl;
}
