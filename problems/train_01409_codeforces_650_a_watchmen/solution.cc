#include <bits/stdc++.h>
using namespace std;
void rdInt(int &n) {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  n = x * f;
}
map<int, int> mpx, mpy;
map<pair<int, int>, int> st;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    mpx.clear();
    mpy.clear();
    st.clear();
    long long an = 0;
    int x, y;
    for (int i = 0; i < n; i++) {
      rdInt(x);
      rdInt(y);
      an += mpx[x];
      an += mpy[y];
      an -= st[make_pair(x, y)];
      mpx[x]++;
      mpy[y]++;
      st[make_pair(x, y)]++;
    }
    printf("%I64d\n", an);
  }
  return 0;
}
