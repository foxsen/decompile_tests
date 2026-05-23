#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, al;
  int k;
  cin >> s >> al;
  cin >> k;
  vector<int> cum(s.length() + 1, 0);
  for (int i = 1; i <= s.length(); i++) {
    cum[i] = cum[i - 1] + (al[s[i - 1] - 'a'] == '0');
  }
  vector<string> suf;
  string an = "";
  for (int i = s.length() - 1; i >= 0; i--) {
    an = s[i] + an;
    suf.push_back(an);
  }
  sort(suf.begin(), suf.end());
  int lcp[suf.size() + 2];
  int lcm[suf.size() + 2];
  for (int i = 0; i < suf.size() - 1; i++) {
    int j = 0;
    for (; j < min(suf[i].size(), suf[i + 1].size()); j++) {
      if (suf[i][j] != suf[i + 1][j]) {
        break;
      }
    }
    lcp[i] = j;
    int start = s.length() - suf[i].size();
    lcm[i] = cum[start + j] - cum[start];
  }
  int cnt = 0;
  for (int i = 0; i < suf[0].size(); i++) {
    int start = s.length() - suf[0].size();
    if (cum[start + i + 1] - cum[start] <= k) cnt++;
  }
  for (int i = 1; i < suf.size(); i++) {
    int start = s.length() - suf[i].size();
    for (int j = start + lcp[i - 1]; j < s.length(); j++) {
      if (cum[j + 1] - cum[start + lcp[i - 1]] + lcm[i - 1] <= k) {
        cnt++;
      } else
        break;
    }
  }
  cout << cnt << endl;
  return 0;
}
