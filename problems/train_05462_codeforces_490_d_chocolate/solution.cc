#include <bits/stdc++.h>
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void CI(int &_x) { scanf("%d", &_x); }
void CO(int &_x) { cout << _x; }
template <typename T>
void getarray(T a[], int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void printarray(T a[], int n) {
  for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
int dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dr4[4] = {0, 0, 1, -1};
int dc4[4] = {-1, 1, 0, 0};
int kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int main() {
  int a1, b1, a2, b2, aa1, bb1, aa2, bb2;
  cin >> a1 >> b1 >> a2 >> b2;
  aa1 = a1, bb1 = b1, aa2 = a2, bb2 = b2;
  int a1_2 = 0, a1_3 = 0, b1_2 = 0, b1_3 = 0, a2_2 = 0, a2_3 = 0, b2_2 = 0,
      b2_3 = 0;
  while (a1 % 3 == 0) {
    a1_3 += 1;
    a1 /= 3;
    a1 *= 2;
  }
  while (a1 % 2 == 0) {
    a1_2 += 1;
    a1 /= 2;
  }
  while (a2 % 3 == 0) {
    a2_3 += 1;
    a2 /= 3;
    a2 *= 2;
  }
  while (a2 % 2 == 0) {
    a2_2 += 1;
    a2 /= 2;
  }
  while (b1 % 3 == 0) {
    b1_3 += 1;
    b1 /= 3;
    b1 *= 2;
  }
  while (b1 % 2 == 0) {
    b1_2 += 1;
    b1 /= 2;
  }
  while (b2 % 3 == 0) {
    b2_3 += 1;
    b2 /= 3;
    b2 *= 2;
  }
  while (b2 % 2 == 0) {
    b2_2 += 1;
    b2 /= 2;
  }
  if ((a1 * b1) != (a2 * b2)) {
    puts("-1");
    return 0;
  }
  int ans = 0;
  int two, three;
  two = max(a1_2 + b1_2, a2_2 + b2_2) - min(a1_2 + b1_2, a2_2 + b2_2);
  ans += two;
  three = max(a1_3 + b1_3, a2_3 + b2_3) - min(a1_3 + b1_3, a2_3 + b2_3);
  ans += three;
  if (a1_3 + b1_3 > a2_3 + b2_3) {
    while (three && aa1 % 3 == 0) {
      aa1 /= 3;
      aa1 *= 2;
      three--;
    }
    while (three && bb1 % 3 == 0) {
      bb1 /= 3;
      bb1 *= 2;
      three--;
    }
  } else {
    while (three && aa2 % 3 == 0) {
      aa2 /= 3;
      aa2 *= 2;
      three--;
    }
    while (three && bb2 % 3 == 0) {
      bb2 /= 3;
      bb2 *= 2;
      three--;
    }
  }
  if (a1_2 + b1_2 > a2_2 + b2_2) {
    while (aa1 % 2 == 0 && two) {
      two--;
      aa1 /= 2;
    }
    while (bb1 % 2 == 0 && two) {
      two--;
      bb1 /= 2;
    }
  } else {
    while (aa2 % 2 == 0 && two) {
      two--;
      aa2 /= 2;
    }
    while (bb2 % 2 == 0 && two) {
      two--;
      bb2 /= 2;
    }
  }
  cout << ans << "\n";
  cout << aa1 << " " << bb1 << "\n";
  cout << aa2 << " " << bb2 << "\n";
}
