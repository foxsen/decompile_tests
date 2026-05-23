#include <bits/stdc++.h>
using namespace std;
int cnt[2];
int solve(string &str) {
  int ans = 1;
  int c = 0, p = 0;
  if (str[0] == 'C')
    cnt[1]++;
  else
    cnt[2]++;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] == str[i - 1]) {
      if (str[i] == 'C') {
        if (cnt[1] == 5) {
          ans++;
          cnt[1] = 1;
        } else {
          cnt[1]++;
        }
      } else {
        if (cnt[2] == 5) {
          ans++;
          cnt[2] = 1;
        } else {
          cnt[2]++;
        }
      }
    } else {
      if (str[i] == 'C') {
        cnt[1] = 1;
        ans++;
        cnt[2] = 0;
      } else {
        cnt[2] = 1;
        ans++;
        cnt[1] = 0;
      }
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  string str;
  cin >> str;
  int ans = solve(str);
  printf("%d\n", ans);
  return 0;
}
