#include <bits/stdc++.h>
using namespace std;
void normalize(string& str) {
  int f = 0;
  int l = (int)str.size() - 1;
  int cnt;
  while (f < l) {
    cnt = 0;
    cnt = (str[f] == '?') + (str[l] == '?');
    if (cnt == 1) {
      char ch = str[f];
      if (ch == '?') ch = str[l];
      str[f] = str[l] = ch;
    }
    ++f;
    --l;
  }
}
bool isPalin(string& str) {
  int f = 0;
  int l = (int)str.size() - 1;
  while (f < l) {
    if (str[f] != str[l]) return false;
    ++f;
    --l;
  }
  return true;
}
string solve(string& str, int K) {
  if (!isPalin(str)) return "IMPOSSIBLE";
  int qc = 0;
  for (int i = (int)(0); i < (int)((int)str.size()); ++i)
    if (str[i] == '?') ++qc;
  qc = qc / 2 + (qc % 2);
  set<char> S;
  for (int i = (int)(0); i < (int)(K); ++i) S.insert('a' + i);
  for (int i = (int)(0); i < (int)((int)str.size()); ++i)
    if (str[i] != '?') {
      if (S.find(str[i]) != S.end()) S.erase(str[i]);
    }
  if ((int)S.size() > qc) return "IMPOSSIBLE";
  int cnt_a = qc - (int)S.size();
  string pal;
  for (int i = (int)(0); i < (int)(cnt_a); ++i) pal += 'a';
  for (typeof(S.begin()) it = S.begin(); it != S.end(); ++it) pal += (*it);
  int x = 0;
  int f = 0;
  int l = (int)str.size() - 1;
  while (f < l) {
    if (str[f] == '?') {
      str[f] = str[l] = pal[x];
      x++;
    }
    ++f;
    --l;
  }
  for (int i = (int)(0); i < (int)((int)str.size()); ++i)
    if (str[i] == '?') str[i] = pal[x++];
  return str;
}
int main() {
  int K;
  string str;
  cin >> K;
  cin >> str;
  normalize(str);
  string res = solve(str, K);
  cout << res << endl;
}
