#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int swap[2] = {0};
  int color[2][2] = {0};
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0 && s[i] == 'r') color[0][0] += 1;
    if (i % 2 == 1 && s[i] == 'b') color[0][1] += 1;
    if (i % 2 == 0 && s[i] == 'b') color[1][0] += 1;
    if (i % 2 == 1 && s[i] == 'r') color[1][1] += 1;
  }
  cout << min(max(color[0][0], color[0][1]), max(color[1][0], color[1][1]))
       << endl;
}
