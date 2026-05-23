#include <bits/stdc++.h>
using namespace std;
int main() {
  int min1, min2, arr[7] = {97, 117, 98, 114, 66, 115, 108};
  int sto[7] = {0, 0, 0, 0, 0, 0, 0};
  char str[100005];
  gets(str);
  int len = strlen(str);
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < 7; ++j)
      if (int(str[i]) == arr[j]) {
        sto[j] += 1;
        break;
      }
  }
  min1 = sto[2];
  for (int i = 3; i <= 6; ++i)
    if (sto[i] < min1) {
      min1 = sto[i];
    }
  min2 = sto[0];
  if (sto[1] < min2) min2 = sto[1];
  for (int i = min1; i >= 0; --i)
    if (min2 >= (i * 2)) {
      cout << i;
      break;
    }
}
