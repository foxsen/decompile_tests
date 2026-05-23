#include <bits/stdc++.h>
using namespace std;
const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int LEN = int(1e5) + 100;
char s[LEN];
bool can_win[LEN], can_loose[LEN];
int _next[LEN][26];
void dfs(int v) {
  bool exists = false;
  for (int i = 0; i < 26; ++i) {
    if (_next[v][i] != -1) {
      exists = true;
      dfs(_next[v][i]);
    }
  }
  if (!exists) {
    can_loose[v] = true;
  } else {
    for (int i = 0; i < 26; ++i) {
      if (_next[v][i] != -1) {
        can_loose[v] |= !can_loose[_next[v][i]];
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (_next[v][i] != -1) {
      can_win[v] |= !can_win[_next[v][i]];
    }
  }
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < 26; ++i) {
    _next[0][i] = -1;
  }
  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s), cur = 0;
    for (int j = 0; j < len; ++j) {
      int c = s[j] - 'a';
      if (_next[cur][c] == -1) {
        _next[cur][c] = ++ptr;
        for (int z = 0; z < 26; ++z) {
          _next[ptr][z] = -1;
        }
      }
      cur = _next[cur][c];
    }
  }
  dfs(0);
  if (k == 1) {
    if (can_win[0]) {
      puts("First");
    } else {
      puts("Second");
    }
    return 0;
  }
  if (!can_win[0]) {
    puts("Second");
    return 0;
  }
  if (can_loose[0] && can_win[0]) {
    puts("First");
    return 0;
  }
  if (k % 2 == 0) {
    puts("Second");
    return 0;
  }
  puts("First");
  return 0;
}
