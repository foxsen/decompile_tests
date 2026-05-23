#include <bits/stdc++.h>
using namespace std;
string ss;
int num[200005];
int len, t, pos;
int head;
void trans(string s) {
  pos = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '.')
      head = i - 1;
    else
      num[pos++] = s[i] - '0';
  }
  len--;
}
int dfs(int pos) {
  if (pos > len) return -1e9;
  if (num[pos] == 4) return dfs(pos + 1) + 1;
  if (num[pos] > 4) return 1;
  return -1e9;
}
int solve() {
  for (int i = head + 1; i < pos; i++) {
    if (num[i] >= 5) return i - 1;
    if (num[i] < 4) continue;
    if (num[i] == 4) {
      int s = dfs(i + 1);
      if (s > 0) {
        if (s + 1 <= t)
          return i - 1;
        else {
          return i + (s + 1 - t) - 1;
        }
      } else {
        while (num[i] == 4) i++;
      }
    }
  }
  return -1;
}
int main() {
  cin >> len >> t;
  cin >> ss;
  trans(ss);
  int ans = solve();
  if (ans == -1) {
    cout << ss << endl;
    return 0;
  }
  {
    int tmp = ans;
    while (tmp > 0 && ++num[tmp] >= 10) {
      num[tmp] = 0;
      tmp--;
    }
    if (tmp == 0) num[tmp]++;
    for (int i = 0; i <= ans; i++) {
      printf("%d", num[i]);
      if (i == head && i != ans) printf(".");
    }
  }
  puts("");
}
