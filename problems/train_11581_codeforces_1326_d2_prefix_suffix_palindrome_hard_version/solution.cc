#include <bits/stdc++.h>
using namespace std;
long long int* getLPS(string& p) {
  long long int len = p.size();
  long long int* LPS = new long long int[len];
  long long int i = 1, j = 0;
  LPS[0] = 0;
  while (i < len) {
    if (p[i] == p[j]) {
      LPS[i] = j + 1;
      i++;
      j++;
    } else {
      if (j != 0) {
        j = LPS[j - 1];
      } else {
        LPS[i] = 0;
        i++;
      }
    }
  }
  return LPS;
}
string findMid(string a, string b) {
  string s = a + '$' + b;
  long long int* lps = getLPS(s);
  long long int len = lps[s.size() - 1];
  return a.substr(0, len);
}
void solve(long long int caseno) {
  long long int i, j, n;
  string s, ans1 = "", ans2 = "", ans3 = "";
  cin >> s;
  n = s.length();
  i = 0;
  j = n - 1;
  while (i < j && s[i] == s[j]) {
    i++;
    j--;
  }
  cout << s.substr(0, i);
  string mid = s.substr(i, j - i + 1);
  string midr = mid;
  reverse(midr.begin(), midr.end());
  string myans2a = findMid(mid, midr);
  string myans2b = findMid(midr, mid);
  if (myans2a.size() >= myans2b.size())
    ans2 = myans2a;
  else
    ans2 = myans2b;
  cout << ans2;
  cout << s.substr(j + 1, n - j - 1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
