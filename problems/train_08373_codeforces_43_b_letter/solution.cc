#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1E9 + 7;
long long h1[26], h2[26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("inp.txt", "r")) {
    freopen("inp.txt", "r", stdin);
    freopen("outp.txt", "w", stdout);
  }
  string s, t;
  getline(cin, s);
  getline(cin, t);
  long long i;
  for (i = 0; i < s.length(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z')
      h2[s[i] - 'A']++;
    else if (s[i] >= 'a' && s[i] <= 'z')
      h1[s[i] - 'a']++;
  }
  bool poss = true;
  for (i = 0; i < t.length() && poss; i++) {
    if (t[i] >= 'A' && t[i] <= 'Z') {
      if (h2[t[i] - 'A'])
        h2[t[i] - 'A']--;
      else
        poss = false;
    } else if (t[i] >= 'a' && t[i] <= 'z') {
      if (h1[t[i] - 'a'])
        h1[t[i] - 'a']--;
      else
        poss = false;
    }
  }
  if (poss)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
