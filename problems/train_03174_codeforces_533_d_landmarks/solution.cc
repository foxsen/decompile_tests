#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long pos[100004];
  long long dur[100004];
  for (int i = 0; i < n + 2; ++i) cin >> pos[i];
  for (int i = 1; i <= n; ++i) {
    cin >> dur[i];
    dur[i] *= 2;
  }
  long long ans = pos[n + 1] - pos[0];
  long long rend[100004];
  long long lend[100004];
  long long st[100004];
  long long sind[100004];
  int sp = -1;
  rend[0] = pos[n + 1];
  sp++;
  st[0] = rend[0];
  sind[0] = 0;
  for (int i = 1; i <= n; ++i) {
    while (st[sp] < pos[i]) sp--;
    rend[i] = pos[i] + dur[i] - (pos[i] - pos[sind[sp]]);
    if (rend[i] >= pos[n + 1]) ans = 0;
    if (rend[i] > pos[i]) {
      sp++;
      st[sp] = rend[i];
      sind[sp] = i;
    }
  }
  sp = -1;
  lend[n + 1] = pos[0];
  sp++;
  st[0] = lend[n + 1];
  sind[0] = n + 1;
  for (int i = n; i >= 1; i--) {
    while (st[sp] > pos[i]) sp--;
    lend[i] = pos[i] - (dur[i] - (pos[sind[sp]] - pos[i]));
    if (lend[i] < pos[i]) {
      sp++;
      st[sp] = lend[i];
      sind[sp] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    long long lpos = rend[i] - dur[i];
    long long rpos = lend[i] + dur[i];
    ans = min(ans, rpos - lpos);
  }
  sp = 0;
  st[0] = -rend[0];
  sind[0] = 0;
  for (int i = 1; i <= n + 1; ++i) {
    if (lend[i] < pos[i]) {
      int q = lower_bound(st, st + sp + 1, -lend[i]) - st;
      q--;
      if (q <= sp && q >= 0) {
        ans = min(ans, pos[i] - pos[sind[q]]);
      }
    }
    if (rend[i] > pos[i]) {
      while (st[sp] >= rend[i]) sp--;
      sp++;
      st[sp] = -rend[i];
      sind[sp] = i;
    }
  }
  float f = ans;
  printf("%0.9f\n", f / 2);
  return 0;
}
