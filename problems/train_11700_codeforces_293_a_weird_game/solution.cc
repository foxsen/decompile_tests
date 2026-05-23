#include <bits/stdc++.h>
char a[2000000], b[2000000];
int main(void) {
  int n, i, cnt, a_cnt, b_cnt, a_temp, b_temp;
  a_cnt = 0;
  b_cnt = 0;
  a_temp = 0;
  b_temp = 0;
  cnt = 0;
  scanf("%d", &n);
  scanf("%s", &a);
  for (i = 0; i < 2 * n; i++) {
    if (a[i] == '1') a_temp++;
  }
  scanf("%s", &b);
  for (i = 0; i < 2 * n; i++) {
    if (b[i] == '1') b_temp++;
    if (a[i] == '1' && a[i] == b[i]) cnt++;
  }
  if (cnt % 2 == 1)
    a_cnt += cnt / 2 + 1;
  else
    a_cnt += cnt / 2;
  b_cnt += cnt / 2;
  a_temp -= cnt;
  b_temp -= cnt;
  if (a_temp > b_temp) {
    a_cnt += b_temp;
    b_cnt += b_temp;
    if (cnt % 2 == 0) {
      a_cnt += (a_temp - b_temp) - (a_temp - b_temp) / 2;
    } else {
      a_cnt += (a_temp - b_temp) / 2;
    }
  } else {
    a_cnt += a_temp;
    b_cnt += a_temp;
    if (cnt % 2 == 0) {
      b_cnt += (b_temp - a_temp) / 2;
    } else {
      b_cnt += (b_temp - a_temp) - (b_temp - a_temp) / 2;
    }
  }
  if (a_cnt > b_cnt)
    printf("First");
  else if (a_cnt < b_cnt)
    printf("Second");
  else
    printf("Draw");
  return 0;
}
