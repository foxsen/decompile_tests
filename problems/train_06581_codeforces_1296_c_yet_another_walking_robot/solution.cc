#include <bits/stdc++.h>
using namespace std;
void solve(string s, int n) {
  map<pair<int, int>, int> pos;
  map<pair<int, int>, bool> mep;
  pair<int, int> at = {0, 0};
  pos[at] = 0;
  mep[at] = true;
  int ans = 202020;
  int lans = -1, rans = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') at.second++;
    if (s[i] == 'D') at.second--;
    if (s[i] == 'L') at.first--;
    if (s[i] == 'R') at.first++;
    if (mep[at]) {
      if ((i + 1) - pos[at] < ans) {
        ans = (i + 1) - pos[at];
        lans = pos[at] + 1;
        rans = i + 1;
      }
    }
    mep[at] = true;
    pos[at] = i + 1;
  }
  if (lans == rans)
    cout << "-1\n";
  else
    cout << lans << " " << rans << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int n;
    cin >> n;
    cin >> s;
    solve(s, n);
  }
  return 0;
}
