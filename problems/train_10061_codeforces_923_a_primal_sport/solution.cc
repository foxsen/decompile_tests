#include <bits/stdc++.h>
using namespace std;
int P[1000005];
void init() {
  for (int j = 2; j < 1000001; j++) {
    if (P[j] != 0) continue;
    for (int k = 2; k * j < 1000001; k++) {
      P[j * k] = j;
    }
  }
}
int main() {
  init();
  int x;
  cin >> x;
  int mini = INT_MAX;
  for (int j = x; j > x - P[x]; j--) {
    if (P[j] == 0)
      continue;
    else {
      int t = j - P[j];
      if (t % P[j] == 0) t++;
      mini = min(mini, t);
    }
  }
  cout << mini << "\n";
  return 0;
}
