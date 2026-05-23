#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000 + 3;
int val;
int n;
char str[20000];
int coeff[MAX], dir[MAX];
pair<int, int> p[1003];
int main() {
  scanf("%d", &val);
  scanf("%s", str);
  int len = strlen(str), fact = 1;
  bool plus = false, minsi = false;
  for (int i = 0; i < len; i++) {
    if (isdigit(str[i])) {
      fact = str[i] - '0';
      while (isdigit(str[++i])) fact = fact * 10 + str[i] - '0';
    }
    if (str[i] == 'a') {
      coeff[++n] = fact;
      fact = 1;
      if (minsi) {
        coeff[n] *= -1;
        minsi = false;
      }
      if (plus)
        plus = false;
      else {
        dir[n] = 1;
        i += 2;
      }
      continue;
    }
    if (str[i] == '+' and (str[i + 1] == '+' and str[i + 2] != '+'))
      plus = true;
    else if (str[i] == '-')
      minsi = true;
  }
  for (int i = 1; i <= n; ++i) p[i - 1] = pair<int, int>(coeff[i], dir[i]);
  sort(p, p + n);
  int sol = 0;
  for (int i = 0; i < n; ++i) {
    sol += p[i].first * (val + !p[i].second);
    ++val;
  }
  printf("%d\n", sol);
  scanf("%%");
  return 0;
}
