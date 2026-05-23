#include <bits/stdc++.h>
using namespace std;
long long int digits[20];
long long int digitsclone[20];
int dc = 0;
long long int arrofarr[20][20];
int main() {
  long long int input;
  cin >> input;
  if (input < 10) {
    cout << input;
    return 0;
  }
  while (input != 0) {
    digits[dc] = input % 10;
    digitsclone[dc] = digits[dc];
    input = input / 10;
    dc++;
  }
  reverse(digits, digits + dc);
  reverse(digitsclone, digitsclone + dc);
  for (int k = 0; k < dc; k++) {
    if (k == dc - 1) {
      for (int i = 0; i < dc; i++) {
        arrofarr[dc - 1][i] = digits[i];
      }
      break;
    }
    for (int m = 0; m < dc; m++) {
      digitsclone[m] = digits[m];
    }
    if (digitsclone[k] == 0) {
      continue;
    } else {
      digitsclone[k]--;
      for (int j = k + 1; j < dc; j++) {
        digitsclone[j] = 9;
      }
    }
    for (int m = 0; m < dc; m++) {
      arrofarr[k][m] = digitsclone[m];
    }
  }
  long long int sum[20] = {0};
  int sumd[20] = {0};
  long long int s = 1;
  for (int i = 0; i < dc; i++) {
    reverse(arrofarr[i], arrofarr[i] + dc);
    for (int k = 0; k < dc; k++) {
      sum[i] = sum[i] + arrofarr[i][k] * s;
      sumd[i] = sumd[i] + arrofarr[i][k];
      s *= 10;
    }
    s = 1;
  }
  long long maxs = sum[0];
  int max = sumd[0];
  for (int i = 1; i < dc; i++) {
    if (sumd[i] > max) {
      max = sumd[i];
      maxs = sum[i];
    }
    if (sumd[i] == max && sum[i] > maxs) {
      max = sumd[i];
      maxs = sum[i];
    }
  }
  cout << maxs;
  return 0;
}
