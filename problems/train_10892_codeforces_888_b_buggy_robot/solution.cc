#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int totL = 0, totR = 0;
  int totU = 0, totD = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == 'L')
      totL++;
    else if (s[i] == 'R')
      totR++;
    else if (s[i] == 'D')
      totD++;
    else
      totU++;
  printf("%d\n", min(totL, totR) * 2 + min(totD, totU) * 2);
}
int main() {
  solve();
  return 0;
}
