#include <bits/stdc++.h>
using namespace std;
int main() {
  char a, b;
  int A, B;
  cin >> a >> A;
  cin >> b >> B;
  int chess[9][9] = {0};
  for (int i = 1; i < 9; i++) {
    chess[i][A] = 1;
  }
  for (int i = 1; i < 9; i++) {
    chess[a - 96][i] = 1;
  }
  if (b - 98 > 0) {
    if (B - 1 > 0) {
      chess[b - 98][B - 1] = 1;
    }
    if (B + 1 < 9) {
      chess[b - 98][B + 1] = 1;
    }
  }
  if (b - 94 < 9) {
    if (B - 1 > 0) {
      chess[b - 94][B - 1] = 1;
    }
    if (B + 1 < 9) {
      chess[b - 94][B + 1] = 1;
    }
  }
  if (B - 2 > 0) {
    if (b - 97 > 0) {
      chess[b - 97][B - 2] = 1;
    }
    if (b - 95 < 9) {
      chess[b - 95][B - 2] = 1;
    }
  }
  if (B + 2 < 9) {
    if (b - 97 > 0) {
      chess[b - 97][B + 2] = 1;
    }
    if (b - 95 < 9) {
      chess[b - 95][B + 2] = 1;
    }
  }
  if (a - 97 > 0) {
    if (A + 2 < 9) {
      chess[a - 97][A + 2] = 1;
    }
    if (A - 2 > 0) {
      chess[a - 97][A - 2] = 1;
    }
  }
  if (a - 95 < 9) {
    if (A + 2 < 9) {
      chess[a - 95][A + 2] = 1;
    }
    if (A - 2 > 0) {
      chess[a - 95][A - 2] = 1;
    }
  }
  if (A - 1 > 0) {
    if (a - 94 < 9) {
      chess[a - 94][A - 1] = 1;
    }
    if (a - 98 > 0) {
      chess[a - 98][A - 1] = 1;
    }
  }
  if (A + 1 < 9) {
    if (a - 94 < 9) {
      chess[a - 94][A + 1] = 1;
    }
    if (a - 98 > 0) {
      chess[a - 98][A + 1] = 1;
    }
  }
  chess[b - 96][B] = 1;
  int w = 0;
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      if (chess[i][j] == 0) {
        w++;
      }
    }
  }
  cout << w;
  return 0;
}
