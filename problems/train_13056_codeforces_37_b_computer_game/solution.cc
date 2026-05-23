#include <bits/stdc++.h>
int n, h, r;
struct Spell {
  int index;
  int pow;
  int dmg;
  bool used;
};
Spell s[1111];
struct Result {
  int t, index;
};
Result result[2222];
int main() {
  scanf("%d%d%d", &n, &h, &r);
  int maxi = h;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &s[i].pow, &s[i].dmg);
    s[i].index = i + 1;
    s[i].used = false;
  }
  bool ok = false, defeated = false;
  int cnt = 0, total = 0, anslen = 0;
  while (!ok || cnt < 3000) {
    ok = true;
    int ih = h;
    h -= total;
    h += r;
    if (h <= 0) {
      defeated = true;
      break;
    }
    if (h > maxi) h = maxi;
    if (ih > h) ok = false;
    int now = 0, id = -1;
    for (int i = 0; i < n; i++) {
      if (!s[i].used && s[i].pow / 100.0 - 1.0 * h / maxi > -10e-8) {
        if (now < s[i].dmg) {
          now = s[i].dmg;
          id = s[i].index;
        }
      }
    }
    if (id != -1) {
      ok = false;
      result[anslen].t = cnt;
      result[anslen].index = id;
      s[id - 1].used = true;
      anslen++;
      total += now;
    }
    cnt++;
  }
  if (defeated) {
    printf("YES\n");
    printf("%d %d\n", cnt, anslen);
    for (int i = 0; i < anslen; i++) {
      printf("%d %d\n", result[i].t, result[i].index);
    }
  } else
    printf("NO\n");
  return 0;
}
