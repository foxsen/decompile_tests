#include <bits/stdc++.h>
using namespace std;
char X[102];
int t, n;
int A[102][2501];
int i, j;
int k, s, ct;
long long suma;
int main() {
  for (i = 0; i <= 25; i++) A[1][i] = 1;
  for (i = 1; i <= 100; i++) A[i][0] = 1;
  for (k = 2; k <= 100; k++)
    for (s = 1; s <= 2500; s++) {
      i = k - 1;
      j = s;
      ct = 0;
      while (ct <= 25 && (j - ct) >= 0) {
        A[k][s] = (A[k][s] + A[i][j - ct]) % 1000000007;
        ct++;
      }
    }
  cin >> t;
  cin.getline(X, 102);
  for (i = 1; i <= t; i++) {
    cin.getline(X, 102);
    suma = 0;
    n = strlen(X);
    for (j = 0; j < n; j++) suma += X[j] - 'a';
    cout << (A[n][suma] + 1000000006) % 1000000007 << endl;
  }
  return 0;
}
