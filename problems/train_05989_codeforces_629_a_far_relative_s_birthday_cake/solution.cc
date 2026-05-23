#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  string a;
  int str[n], stl[n], s = 0;
  char c;
  for (int i = 0; i < n; i++) {
    str[i] = 0;
    stl[i] = 0;
  }
  getline(cin, a);
  for (int i = 0; i < n; i++) {
    getline(cin, a);
    for (int j = 0; j < n; j++) {
      if (a[j] == 'C') {
        str[j]++;
        stl[i]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (str[i] == 2)
      s++;
    else
      s += str[i] * (str[i] - 1) / 2;
    if (stl[i] == 2)
      s++;
    else
      s += stl[i] * (stl[i] - 1) / 2;
  }
  printf("%d", s);
  return 0;
}
