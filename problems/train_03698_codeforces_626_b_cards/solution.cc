#include <bits/stdc++.h>
using namespace std;
enum { BC = 1, GC = 2, RC = 4 };
char dp[201][201][201];
static int f(int B, int G, int R) {
  if (dp[B][G][R] != -1) return dp[B][G][R];
  if (B == 1 && G == 0 && R == 0) return (dp[B][G][R] = BC);
  if (B == 0 && G == 1 && R == 0) return (dp[B][G][R] = GC);
  if (B == 0 && G == 0 && R == 1) return (dp[B][G][R] = RC);
  char pos = 0;
  if (B >= 2) pos |= f(B - 1, G, R);
  if (G >= 2) pos |= f(B, G - 1, R);
  if (R >= 2) pos |= f(B, G, R - 1);
  if (B >= 1 && G >= 1) pos |= f(B - 1, G - 1, R + 1);
  if (G >= 1 && R >= 1) pos |= f(B + 1, G - 1, R - 1);
  if (R >= 1 && B >= 1) pos |= f(B - 1, G + 1, R - 1);
  dp[B][G][R] = pos;
  return pos;
}
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int R = 0, G = 0, B = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    switch (c) {
      case 'R':
        R++;
        break;
      case 'G':
        G++;
        break;
      case 'B':
        B++;
        break;
    }
  }
  memset(dp, -1, sizeof(dp));
  int fr = f(B, G, R);
  if (fr & BC) cout << "B";
  if (fr & GC) cout << "G";
  if (fr & RC) cout << "R";
  cout << endl;
  return 0;
}
