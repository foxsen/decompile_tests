#include <bits/stdc++.h>
using namespace std;
int A[101], B[101], n, k, M[101][101], G[101], ng;
int comb3(int n) { return (n * (n - 1) * (n - 2)) / 6; }
int comb2(int n) { return (n * (n - 1)) / 2; }
void Combs() {
  for (int i = 3; i <= 100; i++) {
    A[i] = comb3(i);
    B[i] = comb2(i);
  }
  B[2] = comb2(2);
}
int kcompleto() {
  int j = 100;
  while (true) {
    if (A[j] > n) {
      j--;
    } else {
      n -= A[j];
      return j;
    }
  }
}
void Gerarkcompleto() {
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      if (i != j) {
        M[i][j] = 1;
      }
    }
  }
}
void CriarGuloso() {
  int j = 100;
  ng = 0;
  while (n > 0) {
    if (B[j] > n) {
      j--;
    } else {
      G[++ng] = j;
      n -= B[j];
    }
  }
}
void GraphIncrement() {
  for (int i = k + 1; i <= k + ng; i++) {
    for (int j = 1; j <= G[i - k]; j++) {
      M[i][j] = 1;
      M[j][i] = 1;
    }
  }
  k += ng;
}
void PrintGraph() {
  cout << k << endl;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      cout << M[i][j];
    }
    cout << endl;
  }
}
int main() {
  cin >> n;
  Combs();
  k = kcompleto();
  Gerarkcompleto();
  CriarGuloso();
  GraphIncrement();
  PrintGraph();
}
