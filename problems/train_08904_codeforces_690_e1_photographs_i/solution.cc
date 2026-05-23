#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e6) + 256;
const int INF = int(1e9) + 7;
int main() {
  ios_base ::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int dx, dy;
    cin >> dx >> dy;
    int px[600][600];
    vector<int> px_sum(dx + 1, 0);
    for (int i = 0; i < dx; i++) {
      for (int j = 0; j < dy; j++) {
        cin >> px[i][j];
        px_sum[i] += px[i][j];
      }
    }
    int max_dif = 0;
    for (int i = 1; i < dx; i++)
      max_dif = max(max_dif, abs(px_sum[i] - px_sum[i - 1]));
    if (max_dif > 10000)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
