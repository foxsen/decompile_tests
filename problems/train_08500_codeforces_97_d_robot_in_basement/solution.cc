#include <bits/stdc++.h>
using namespace std;
const int EXP = 22505;
const int DIM = 100015;
char str[DIM];
bitset<EXP> wal, rom, ext, cur;
int main(void) {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    for (int j = 0; j < m; ++j) {
      if (str[j] == '#') wal[i * m + j] = true;
      if (str[j] != '#') rom[i * m + j] = cur[i * m + j] = true;
      if (str[j] == 'E') ext[i * m + j] = true;
    }
  }
  int ans = -1;
  if (ext == cur) ans = 0;
  cin >> str;
  for (int i = 0; i <= k and ans == -1; ++i) {
    switch (str[i]) {
      case 'U':
        cur = ((cur >> m) & rom) | (cur & (wal << m));
        break;
      case 'D':
        cur = ((cur << m) & rom) | (cur & (wal >> m));
        break;
      case 'L':
        cur = ((cur >> 1) & rom) | (cur & (wal << 1));
        break;
      case 'R':
        cur = ((cur << 1) & rom) | (cur & (wal >> 1));
        break;
    }
    if (cur == ext) ans = i + 1;
  }
  cout << ans << endl;
  return 0;
}
