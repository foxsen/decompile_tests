#include <bits/stdc++.h>
using namespace std;
int block[101];
int nuclea[101];
int inst[101][101];
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> inst[j][i];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (nuclea[j] == 0) block[inst[i][j]]++;
    }
    block[0] = 0;
    for (int j = 0; j < n; j++) {
      if (block[inst[i][j]] > 1 && nuclea[j] == 0) {
        nuclea[j] = i + 1;
      }
    }
    for (int i = 1; i < 101; i++) {
      if (block[i] < 2) block[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) cout << nuclea[i] << endl;
  return 0;
}
