#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  set<int> positions;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    int s_pos = -1;
    int g_pos = -1;
    for (int j = 0; j < m; j++) {
      if (row[j] == 'G') {
        g_pos = j;
      } else if (row[j] == 'S') {
        s_pos = j;
      }
      if (g_pos != -1 && s_pos != -1) {
        break;
      }
    }
    int diff = s_pos - g_pos;
    if (diff < 0) {
      cout << -1;
      return 0;
    }
    positions.insert(diff);
  }
  cout << positions.size();
  return 0;
}
