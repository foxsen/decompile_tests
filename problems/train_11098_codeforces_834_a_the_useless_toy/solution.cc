#include <bits/stdc++.h>
using namespace std;
int func(int A[], char ch) {
  switch (ch) {
    case 'v': {
      A[0] = 1;
      return 0;
      break;
    }
    case '<': {
      A[1] = 1;
      return 1;
      break;
    }
    case '^': {
      A[2] = 1;
      return 2;
      break;
    }
    case '>': {
      A[3] = 1;
      return 3;
    }
  }
}
int main() {
  char c1, c2;
  long long n;
  cin >> c1 >> c2 >> n;
  int A[4];
  for (int i = 0; i < 4; i++) {
    A[i] = 0;
  }
  int i1 = func(A, c1);
  int i2 = func(A, c2);
  int z = n % 4;
  if (z == 2 || z == 0) {
    cout << "undefined";
  } else {
    if (i2 > i1) {
      if ((i2 - i1) % 4 == z) {
        cout << "cw";
      } else {
        cout << "ccw";
      }
    } else {
      if ((i2 - i1 + 4) % 4 == z) {
        cout << "cw";
      } else {
        cout << "ccw";
      }
    }
  }
  return 0;
}
