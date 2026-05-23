#include <bits/stdc++.h>
using namespace std;
template <typename t>
t getnum() {
  t res = 0;
  char c;
  int sign = 1;
  while ((c = getchar()) == ' ' || c == '\n') {
    c = getchar();
    if (c == ' ' || c == '\n')
      continue;
    else
      break;
  }
  if (c == '+') {
  } else if (c == '-')
    sign = -1;
  else
    res = c - '0';
  while (1) {
    c = getchar();
    if (c >= '0' && c <= '9')
      res = res * 10 + c - '0';
    else
      break;
  }
  return res * sign;
}
inline void getstr(string &str) {
  bool now = true;
  while (now) {
    char k = getchar();
    switch (k) {
      case '\n':
      case '\t':
      case '\v':
      case '\0':
      case ' ':
      case EOF:
        now = false;
        break;
      default:
        str.push_back(k);
        break;
    }
  }
}
int main() {
  char k, bef = '0';
  long long right = -1, streak = 0, ans = 1, now = 0;
  while ((k = getchar()) != EOF && k != '\n') {
    if (bef + k - '0' - '0' == 9) {
      streak++;
      right = now;
    } else {
      if (streak) {
        streak = (streak % 2 ? 1 : streak / 2 + 1);
        ans *= streak;
      }
      streak = 0;
    }
    now++;
    bef = k;
  }
  if (streak) {
    streak = (streak % 2 ? 1 : streak / 2 + 1);
    ans *= streak;
  }
  cout << ans;
  return 0;
}
