#include <bits/stdc++.h>
using namespace std;
bool s_end(size_t c) { return (c == string ::npos) ? true : false; }
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int lane = (k + 2 * m - 1) / (2 * m);
  k -= (lane - 1) * 2 * m;
  int desk = (k + 1) / 2;
  char side = (k % 2) ? 'L' : 'R';
  cout << lane << " " << desk << " " << side;
  return 0;
}
