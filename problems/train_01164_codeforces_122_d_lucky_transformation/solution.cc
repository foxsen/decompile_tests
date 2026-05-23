#include <bits/stdc++.h>
char A[100001];
int op;
int cnt;
int n;
int at;
inline void solve() {
  while (cnt < op) {
    if (at == n - 1) {
      break;
    } else {
      if (A[at] == '4' && A[at + 1] == '7') {
        if (at % 2 == 0) {
          if (at == n - 2) {
            A[at + 1] = '4';
            cnt++;
            at++;
          } else if (A[at + 2] != 7) {
            A[at + 1] = '4';
            cnt++;
            at++;
          } else {
            if ((op - cnt) % 2 == 1) {
              A[at + 1] = '4';
            }
            cnt = op + 1;
          }
        } else {
          if (at > 0) {
            if (A[at - 1] == '4') {
              if ((op - cnt) % 2 == 1) {
                A[at] = '7';
              }
              cnt = op + 1;
            } else {
              cnt++;
              A[at] = '7';
              at++;
            }
          }
        }
      } else {
        at++;
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &op);
  scanf("%s", A);
  if (n > 1) {
    at = 0;
    solve();
  }
  printf("%s\n", A);
  return 0;
}
