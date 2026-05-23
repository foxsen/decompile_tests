#include <bits/stdc++.h>
const int inf = 0xfffffff;
const long long INF = 1ll << 61;
using namespace std;
string s, cc;
string ans;
int aa, bb;
void init() {}
bool input() {
  while (cin >> s) {
    cin >> cc;
    int mark = 0;
    aa = 0;
    bb = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '|') {
        mark = 1;
        continue;
      }
      if (!mark)
        aa++;
      else
        bb++;
    }
    return false;
  }
  return true;
}
void cal() {
  ans = "";
  int tmp = cc.length();
  if (aa + tmp != bb && aa != tmp + bb && (aa + tmp + bb) & 1) {
    ans = "";
    return;
  }
  int tt = (aa + tmp + bb) / 2;
  if (aa > tt || bb > tt) {
    return;
  }
  int mark;
  for (int i = 0; i < s.length(); i++) {
    mark = i;
    if (s[i] == '|') break;
    ans += s[i];
  }
  int flag = -1;
  for (int i = 0; i < tt - aa && i < cc.length(); i++) {
    flag = i;
    ans += cc[i];
  }
  ans += '|';
  for (int i = mark + 1; i < s.length(); i++) ans += s[i];
  for (int i = flag + 1; i < cc.length(); i++) ans += cc[i];
}
void output() {
  if (!ans.length())
    puts("Impossible");
  else
    cout << ans << endl;
}
int main() {
  while (true) {
    init();
    if (input()) return 0;
    cal();
    output();
  }
}
