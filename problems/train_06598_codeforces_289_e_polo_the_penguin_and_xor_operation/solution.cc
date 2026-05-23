#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1000010;
int N, P[NMAX];
void Solve(int Bit, int Left, int Right) {
  if (Left > Right) return;
  if (Left == Right) {
    P[Left] = Left;
    return;
  }
  for (int i = Bit; i >= 0; --i) {
    vector<int> B;
    for (int j = Left; j <= Right; ++j)
      if (j & (1 << i))
        B.push_back(1);
      else
        B.push_back(0);
    if (B[0] == 0 && B.back() == 1) {
      for (int j = 0; j < B.size() - 1; ++j)
        if (B[j] == 0 && B[j + 1] == 1) {
          int PtrLeft = j, PtrRight = j + 1;
          while (PtrLeft >= 0 && PtrRight < B.size()) {
            P[PtrLeft + Left] = PtrRight + Left;
            P[PtrRight + Left] = PtrLeft + Left;
            PtrLeft--;
            PtrRight++;
          }
          Solve(i - 1, Left, PtrLeft);
          Solve(i - 1, PtrRight, Right);
          return;
        }
    }
  }
}
int main() {
  scanf("%i", &N);
  Solve(21, 0, N);
  long long Ans = 0;
  for (int i = 0; i <= N; ++i) Ans += 1LL * (i ^ P[i]);
  printf("%I64d\n", Ans);
  for (int i = 0; i <= N; ++i) printf("%i ", P[i]);
}
