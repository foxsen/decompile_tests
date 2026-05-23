#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:255000000")
bool firstout = 1;
template <class T>
T &minn(T &a, T b) {
  if (b < a) a = b;
  return a;
}
template <class T>
T &maxx(T &a, T b) {
  if (a < b) a = b;
  return a;
}
int &madd(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
int &msub(int &a, int b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
int &mmult(int &a, int b) { return a = (long long)a * b % 1000000007; }
int mdiv(long long a, long long b, long long m) {
  a = (a % m + m) % m;
  b = (b % m + m) % m;
  if (a % b == 0) return a / b;
  return (a + m * mdiv(-a, m, b)) / b;
}
int n, m, q;
int A[105][105];
char S[105][105];
bool valid(int i, int j) { return 0 <= i && i < n && 0 <= j && j < n; }
int main() {
  int i, j, k;
  char c;
  int a, d;
  int ts;
  for (ts = 1; scanf("%"
                     "d",
                     &(n)) > 0;
       ++ts) {
    for (i = (0); i < (n); ++i)
      scanf(
          "%"
          "s",
          &(S[i]));
    for (i = (0); i < (n + n + 1); ++i)
      for (j = (0); j < (n + n + 1); ++j) A[i][j] = 0;
    int o = n - 1;
    int x, y;
    for (x = (-(n - 1)); x < (n); ++x)
      for (y = (-(n - 1)); y < (n); ++y) {
        if (x == 0 && y == 0) continue;
        int r = 1;
        for (i = (0); i < (n); ++i)
          for (j = (0); j < (n); ++j)
            if (S[i][j] == 'o' && valid(i + x, j + y) && S[i + x][j + y] == '.')
              r = 0;
        A[o + x][o + y] = r;
      }
    for (x = (-(n - 1)); x < (n); ++x)
      for (y = (-(n - 1)); y < (n); ++y) {
        if (!A[o + x][o + y]) continue;
        for (i = (0); i < (n); ++i)
          for (j = (0); j < (n); ++j)
            if (S[i][j] == 'o' && valid(i + x, j + y) && S[i + x][j + y] == 'x')
              S[i + x][j + y] = '.';
      }
    int res = 0;
    for (i = (0); i < (n); ++i)
      for (j = (0); j < (n); ++j) res += S[i][j] == 'x';
    if (res)
      printf(
          "%"
          "s",
          ("NO")),
          printf("\n"), firstout = 1;
    else {
      printf(
          "%"
          "s",
          ("YES")),
          printf("\n"), firstout = 1;
      for (x = (-(n - 1)); x < (n); ++x) {
        for (y = (-(n - 1)); y < (n); ++y) {
          if (x == 0 && y == 0)
            printf(
                "%"
                "c",
                ('o'));
          else
            printf(
                "%"
                "c",
                (A[o + x][o + y] ? 'x' : '.'));
        }
        printf("\n"), firstout = 1;
      }
    }
  }
  return 0;
}
