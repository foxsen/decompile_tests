#include <bits/stdc++.h>
using namespace std;
bool vis[100];
void init() {
  memset(vis, true, sizeof(vis));
  vis['B' - 'A'] = false;
  vis['C' - 'A'] = false;
  vis['D' - 'A'] = false;
  vis['E' - 'A'] = false;
  vis['F' - 'A'] = false;
  vis['G' - 'A'] = false;
  vis['J' - 'A'] = false;
  vis['K' - 'A'] = false;
  vis['L' - 'A'] = false;
  vis['N' - 'A'] = false;
  vis['P' - 'A'] = false;
  vis['Q' - 'A'] = false;
  vis['R' - 'A'] = false;
  vis['S' - 'A'] = false;
  vis['Z' - 'A'] = false;
}
int main() {
  init();
  char s[100000 + 10];
  while (~scanf("%s", s)) {
    bool flag = false;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      if (!vis[s[i] - 'A']) {
        flag = true;
        break;
      }
    }
    if (flag)
      puts("NO");
    else {
      for (int i = 0; i < len / 2; i++) {
        if (s[len - 1 - i] != s[i]) {
          flag = true;
          break;
        }
      }
      if (flag)
        puts("NO");
      else
        puts("YES");
    }
  }
  return 0;
}
