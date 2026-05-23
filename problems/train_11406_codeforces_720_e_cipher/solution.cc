#include <bits/stdc++.h>
using namespace std;
int IN() {
  int x = 0, f = 0, ch;
  for (; (ch = getchar()) < '0' || ch > '9';) f = (ch == '-');
  for (; ch >= '0' && ch <= '9'; (ch = getchar())) x = x * 10 + ch - '0';
  return f ? -x : x;
}
int N;
long long Pow[25];
char A[25], B[25], s[25][25];
bool Equ(long long a, long long b) {
  for (int i = 0, lim = N - 1; i <= lim; i++) {
    if (s[i][a / Pow[i] % 10] != s[i][b / Pow[i] % 10]) return 0;
  }
  return 1;
}
long long Cal(int Bit, int v) {
  for (int i = 0, lim = N - 1; i <= lim; i++) B[i] = A[i];
  B[Bit] = v + '0';
  long long NA = 0, NB = 0;
  for (int i = 0, lim = N - 1; i <= lim; i++) {
    NA += Pow[i] * (A[i] - '0');
    NB += Pow[i] * (B[i] - '0');
  }
  if (NA < NB) swap(NA, NB);
  long long ret = Pow[N] - NA;
  for (int i = Bit, lim = N - 1; i <= lim; i++) {
    long long x = NA / Pow[i] * Pow[i];
    for (int j = 1, lim = 10; j <= lim; j++) {
      x += Pow[i];
      long long t = x - NA;
      if (t >= ret) break;
      if (!Equ(NA + t, NB + t)) ret = min(ret, t);
    }
  }
  return ret;
}
int main(int argc, char* argv[]) {
  Pow[0] = 1;
  for (int i = 1, lim = 18; i <= lim; i++) Pow[i] = Pow[i - 1] * 10;
  for (int Test = IN(); Test--;) {
    N = IN();
    scanf("%s", A);
    reverse(A, A + N);
    for (int i = N - 1, lim = 0; i >= lim; i--) scanf("%s", s[i]);
    long long Ans = 0;
    for (int i = 0, lim = N - 1; i <= lim; i++)
      for (int j = 0, lim = 9; j <= lim; j++)
        if (s[i][j] == s[i][A[i] - '0'] && j != A[i] - '0') {
          Ans = max(Ans, Cal(i, j));
        }
    printf("%lld\n", Ans);
  }
  return 0;
}
