#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
struct people {
  string name;
  int score;
};
int main() {
  int n;
  cin >> n;
  int x[n];
  int y[n];
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++) {
    int ri = 0, lef = 0, up = 0, dow = 0;
    for (int e = 0; e < n; e++) {
      if (x[e] > x[i] && y[e] == y[i]) {
        ri++;
      } else if (x[e] < x[i] && y[e] == y[i]) {
        lef++;
      } else if (x[e] == x[i] && y[e] > y[i])
        up++;
      else if (x[e] == x[i] && y[e] < y[i])
        dow++;
    }
    if (ri && dow && lef && up) ans++;
  }
  cout << ans;
}
