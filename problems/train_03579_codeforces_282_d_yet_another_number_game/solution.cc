#include <bits/stdc++.h>
using namespace std;
const int MAXA = 300;
bool dp[MAXA][MAXA][MAXA];
int vals[3];
int n;
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < (int)(MAXA); i++)
    for (int j = 0; j < (int)(MAXA); j++)
      for (int k = 0; k < (int)(MAXA); k++) dp[i][j][k] = false;
  cin >> n;
  if (n == 1) {
    cin >> vals[0];
    cout << (vals[0] == 0 ? "BitAryo" : "BitLGM") << "\n";
  } else if (n == 2) {
    cin >> vals[0] >> vals[1];
    sort(vals, vals + 2);
    for (int i = 0; i < MAXA; i++) {
      for (int j = i; j < MAXA; j++) {
        if (dp[i][j][0]) continue;
        for (int l = 1; l + j < MAXA; l++) dp[i + l][j + l][0] = true;
        for (int l = j + 1; l < MAXA; l++) dp[i][l][0] = true;
        for (int l = i + 1; l <= j; l++) dp[l][j][0] = true;
        for (int l = j + 1; l < MAXA; l++) dp[j][l][0] = true;
      }
    }
    cout << (dp[vals[0]][vals[1]][0] ? "BitLGM" : "BitAryo") << "\n";
  } else {
    cin >> vals[0] >> vals[1] >> vals[2];
    sort(vals, vals + 3);
    for (int i = 0; i < MAXA; i++) {
      for (int j = i; j < MAXA; j++) {
        for (int k = j; k < MAXA; k++) {
          if (dp[i][j][k]) continue;
          for (int l = 1; k + l < MAXA; l++) dp[i + l][j + l][k + l] = true;
          for (int l = k + 1; l < MAXA; l++) dp[i][j][l] = true;
          for (int l = j + 1; l <= k; l++) dp[i][l][k] = true;
          for (int l = k + 1; l < MAXA; l++) dp[i][k][l] = true;
          for (int l = i + 1; l <= j; l++) dp[l][j][k] = true;
          for (int l = j + 1; l <= k; l++) dp[j][l][k] = true;
          for (int l = k + 1; l < MAXA; l++) dp[j][k][l] = true;
        }
      }
    }
    cout << (dp[vals[0]][vals[1]][vals[2]] ? "BitLGM" : "BitAryo") << "\n";
  }
  return 0;
}
