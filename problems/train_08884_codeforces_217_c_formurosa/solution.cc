#include <bits/stdc++.h>
using namespace std;
int n;
char txt[1000006];
int st1[1000006];
int sn1 = 0;
char st2[1000006];
int sn2 = 0;
char toi(char a) {
  if (a == '^') return 2;
  if (a == '&') return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  scanf("%s", txt);
  int pos = 0;
  while (txt[pos]) {
    char c = txt[pos++];
    switch (c) {
      case '(': {
      } break;
      case '0': {
        st1[sn1++] = (1 << 0);
      } break;
      case '1': {
        st1[sn1++] = (1 << 15);
      } break;
      case '?': {
        st1[sn1++] = (1 << 3) | (1 << 5);
      } break;
      case '|':
      case '&':
      case '^': {
        st2[sn2++] = c;
      } break;
      case ')': {
        sn2--;
        int r1 = st1[--sn1];
        int r2 = st1[--sn1];
        int a = 0;
        if (st2[sn2] == '|') {
          for (int i = 15; i >= 0; --i) {
            if (r1 & (1 << i)) {
              for (int j = 15; j >= 0; --j) {
                if (r2 & (1 << j)) {
                  a |= (1 << (i | j));
                }
              }
            }
          }
        } else if (st2[sn2] == '&') {
          for (int i = 15; i >= 0; --i) {
            if (r1 & (1 << i)) {
              for (int j = 15; j >= 0; --j) {
                if (r2 & (1 << j)) {
                  a |= (1 << (i & j));
                }
              }
            }
          }
        } else if (st2[sn2] == '^') {
          for (int i = 15; i >= 0; --i) {
            if (r1 & (1 << i)) {
              for (int j = 15; j >= 0; --j) {
                if (r2 & (1 << j)) {
                  a |= (1 << (i ^ j));
                }
              }
            }
          }
        } else {
          while (1)
            ;
        }
        st1[sn1++] = a;
      } break;
    }
  }
  if (st1[0] & 0x7dbe) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
