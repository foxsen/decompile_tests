#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x7fffffff;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1000000 + 10;
int num[10];
bool judge(int hh, string now) {
  for (int i = 0; i < now.size(); i++) {
    hh *= 10;
    hh += (now[i] - '0');
    hh %= 7;
  }
  if (hh == 0)
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int len = s.size();
  memset(num, 0, sizeof(num));
  for (int i = 0; i < len; i++) num[s[i] - '0']++;
  num[1]--, num[6]--, num[8]--, num[9]--;
  int MOD = 0;
  for (int i = 1; i <= 9; i++) {
    if (num[i]) {
      for (int j = 0; j < num[i]; j++) {
        cout << i;
        MOD *= 10;
        MOD += i;
        MOD %= 7;
      }
    }
  }
  string ans;
  ans += "1689";
  if (judge(MOD, ans)) {
    cout << ans;
  } else {
    while (next_permutation(ans.begin(), ans.end())) {
      if (judge(MOD, ans)) {
        cout << ans;
        break;
      }
    }
  }
  for (int j = 0; j < num[0]; j++) cout << "0";
  cout << endl;
  return 0;
}
