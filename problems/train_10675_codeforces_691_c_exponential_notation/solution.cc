#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
inline void gmax(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline void gmin(T1 &a, T2 b) {
  if (b < a) a = b;
}
const int N = 1e6 + 10;
const long long INF = 1e18;
int casenum, casei;
const int Z = 1e9 + 7;
int n, m;
char s[N];
int st, ed, dot, E;
int main() {
  while (~scanf("%s", s)) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      if (s[i] == '0' || s[i] == '.')
        continue;
      else {
        st = i;
        break;
      }
    }
    dot = -1;
    for (int i = 0; i < len; i++) {
      if (s[i] == '.') {
        dot = i;
        break;
      }
    }
    if (dot == -1) dot = len;
    if (dot > st)
      E = dot - st - 1;
    else
      E = dot - st;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] == '0' || s[i] == '.')
        continue;
      else {
        ed = i;
        break;
      }
    }
    printf("%c", s[st]);
    if (ed > st) printf(".");
    for (int i = st + 1; i <= ed; i++)
      if (s[i] != '.') printf("%c", s[i]);
    if (E) {
      printf("E");
      printf("%d", E);
    }
    puts("");
  }
  return 0;
}
