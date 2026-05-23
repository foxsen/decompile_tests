#include <bits/stdc++.h>
using namespace std;
struct matrix {
  long double arr[128][128];
  long long int n;
};
long double p[128];
matrix matrix_multiplication(matrix x, matrix y) {
  matrix temp;
  temp.n = x.n;
  for (long long int i = 0; i < 128; ++i) {
    for (long long int j = 0; j < 128; ++j) {
      temp.arr[i][j] = 0;
      for (long long int k = 0; k < 128; ++k)
        temp.arr[i][j] += x.arr[i][k] * y.arr[k][j];
    }
  }
  return temp;
}
inline matrix power(matrix a, long long int b) {
  matrix ans;
  for (long long int i = 0; i < 128; ++i) {
    for (long long int j = 0; j < 128; ++j) ans.arr[i][j] = 0;
    ans.arr[i][i] = 1;
  }
  while (b > 0) {
    if (b & 1) {
      ans = matrix_multiplication(a, ans);
    }
    a = matrix_multiplication(a, a);
    b = b >> 1;
  }
  return ans;
}
int main() {
  long long int n, x;
  cin >> n >> x;
  for (long long int i = 0; i <= x; ++i) cin >> p[i];
  for (long long int i = x + 1; i < 128; ++i) p[i] = 0;
  matrix m;
  for (long long int i = 0; i < 128; ++i) {
    for (long long int j = 0; j < 128; ++j) m.arr[i][j] = p[i ^ j];
  }
  matrix ans = power(m, n);
  long double xx = 1.0 - ans.arr[0][0];
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(9);
  cout << xx << endl;
  return 0;
}
