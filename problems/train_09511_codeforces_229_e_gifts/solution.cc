#include <bits/stdc++.h>
using namespace std;
int Get() {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  int X = 0;
  while (c >= '0' && c <= '9') {
    X = X * 10 + c - 48;
    c = getchar();
  }
  return X;
}
const double eps = 1e-7;
int main() {
  int N = Get(), M = Get(), Total = 0;
  static int K[1000], Value[1000][1000], Data[1000];
  for (int i = 0; i < M; i++) {
    K[i] = Get();
    for (int j = 0; j < K[i]; j++) Value[i][j] = Data[Total++] = Get();
  }
  sort(Data, Data + Total);
  int Min = Data[Total - N], Need = 1;
  while (Need < N && Data[Total - N + Need] == Min) Need++;
  static int A[1000], B[1000];
  for (int i = 0; i < M; i++)
    for (int j = A[i] = B[i] = 0; j < K[i]; j++)
      if (Value[i][j] > Min)
        A[i]++;
      else if (Value[i][j] == Min)
        B[i]++;
  static int Sum[1001];
  for (int i = Sum[0] = 0; i < M; i++) Sum[i + 1] = Sum[i] + B[i];
  static double C[1001][1001];
  for (int i = 0; i <= 1000; i++)
    for (int j = 0; j <= i; j++)
      if (!j || i == j)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  static double DP[1001][1000];
  memset(DP, 0, sizeof(DP));
  DP[0][0] = 1;
  for (int i = 0; i < M; i++)
    for (int j = 0; j <= Sum[i]; j++)
      for (int k = 0; k <= B[i] && j + k <= Need; k++) {
        double Temp = DP[i][j];
        Temp *= C[B[i]][k] / C[K[i]][A[i] + k];
        Temp *= C[Sum[i]][j] / C[Sum[i + 1]][j + k];
        DP[i + 1][j + k] += Temp;
      }
  printf("%0.10lf\n", DP[M][Need]);
  return 0;
}
