#include <bits/stdc++.h>
int main() {
  int n, i = 0, j = 0, l = 0, r = 0, temp = 0, temp1 = 0, temp2 = 0, temp3 = 0,
         w = 0;
  char a[3000];
  scanf("%d", &n);
  scanf("%s", &a);
  while (a[i] == '.') {
    r++;
    i++;
  }
  if (a[r] != 'R' && a[r] != 'L') {
    w = r;
  }
  if (a[r] == 'R') {
    temp = r;
  } else
    temp = 0;
  i = n - 1;
  while (a[i] == '.') {
    l++;
    i--;
  }
  if (a[n - 1 - l] == 'L') {
    temp1 = l;
  } else
    temp1 = 0;
  for (i = r; i < n - l; i++) {
    for (j = i + 1; j < n - l; j++) {
      if (a[i] == 'L' && a[j] == 'R') {
        temp2 = temp2 + j - i - 1;
        i = j + 1;
      }
    }
  }
  for (i = r; i < n - l; i++) {
    for (j = i + 1; j < n - l; j++) {
      if (a[i] == 'R' && a[j] == 'L') {
        if (((j - i + 1) % 2 != 0)) {
          temp3 += 1;
          i = j + 1;
        } else {
          i = j + 1;
        }
      }
    }
  }
  printf("%d", (w + temp + temp1 + temp2 + temp3));
  return 0;
}
