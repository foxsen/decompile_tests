#include <bits/stdc++.h>
using namespace std;
int base = 1000000007;
string s, t, S;
int ok[100100], prv[200100];
vector<int> pi;
void pf(string s) {
  int n = s.length();
  pi.resize(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
}
long long f[100100], sum[100100], sumsum[100100];
int main() {
  cin >> s >> t;
  S = t + '#' + s;
  pf(S);
  for (int i = t.length() + 1; i < S.length(); i++)
    if (pi[i] == t.length()) ok[i - t.length() - 1] = 1;
  memset(prv, -1, sizeof(prv));
  for (int i = t.length() - 1; i < s.length(); i++) {
    if (i > 0) prv[i] = prv[i - 1];
    if (ok[i] == 1) prv[i] = i + 1 - (int)t.length();
  }
  for (int i = 0; i < s.length(); i++) {
    if (prv[i] != -1) {
      f[i] = prv[i] + 1;
      if (prv[i] > 0) f[i] += sumsum[prv[i] - 1];
      f[i] %= base;
      if (i > 0) sum[i] = sum[i - 1];
      sum[i] += f[i];
      sum[i] %= base;
      if (i > 0) sumsum[i] = sumsum[i - 1];
      sumsum[i] += sum[i];
      sumsum[i] %= base;
    }
  }
  cout << sum[s.length() - 1] << "\n";
  return 0;
}
