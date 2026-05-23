#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> lr(n);
  int tot = 0;
  int last_left = -1, last_right = -1;
  for (int i = 0; i < n; i++) {
    cin >> lr[i];
    if (lr[i] == 0) last_left = i + 1;
    if (lr[i] == 1) last_right = i + 1;
  }
  cout << min(last_left, last_right) << "\n";
  ;
}
