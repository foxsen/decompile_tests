#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char in[105];
char a[105][105];
map<string, string> mp, rev;
string tostr(int x) {
  string tmp;
  while (x) {
    tmp += (x - 1) % 26 + 'a';
    x = (x - 1) / 26;
  }
  reverse(tmp.begin(), tmp.end());
  return tmp;
}
bool judgename(string s) {
  if (!(isalpha(s[0]) || s[0] == '_' || s[0] == '$')) return false;
  int len = s.size();
  for (int i = 1; i < len; i++)
    if (!(isalpha(s[i]) || isdigit(s[i]) || s[i] == '_' || s[i] == '$'))
      return false;
  return true;
}
bool judgename1(string s) {
  if (!(isalpha(s[0]) || s[0] == '_' || s[0] == '$')) return false;
  return true;
}
bool judgedigit(string s) {
  int len = s.size();
  for (int i = 0; i < len; i++)
    if (!isdigit(s[i])) return false;
  return true;
}
bool judgedigit1(string s) {
  if (!isdigit(s[0])) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, lenmax;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i]);
    string tmp = a[i];
    mp[tmp] = tmp;
    rev[tmp] = tmp;
    lenmax = max(lenmax, (int)tmp.size());
  }
  strcpy(a[++n], " ");
  mp[" "] = " ";
  rev[" "] = " ";
  scanf("%d", &m);
  fgets(in, N, stdin);
  stringstream s;
  while (m--) {
    fgets(in, N, stdin);
    char *r = in;
    while (*r) {
      if (*r == '#') {
        *r = 0;
        break;
      }
      r++;
    }
    r = in;
    while (*r != 0) {
      char *p = in + strlen(in);
      int q = 0;
      for (int i = 1; i <= n; i++) {
        char *tp = strstr(r, a[i]);
        if (tp != 0)
          if (tp < p || (tp == p && strlen(a[i]) > strlen(a[q])))
            if (!(judgedigit1(a[i]) || judgename1(a[i])) ||
                (!judgedigit(a[i]) && judgedigit1(a[i]) &&
                 (tp == r || !(isalpha(*(tp - 1)) || *(tp - 1) == '_' ||
                               *(tp - 1) == '$' || isdigit(*(tp - 1))))) ||
                (judgedigit(a[i]) &&
                 (tp == r || !(isalpha(*(tp - 1)) || *(tp - 1) == '_' ||
                               *(tp - 1) == '$' || isdigit(*(tp - 1)))) &&
                 !isdigit(tp[strlen(a[i])])) ||
                (!judgename(a[i]) && judgename1(a[i]) &&
                 (tp == r || (!(isalpha(*(r)) || *(r) == '$' || *(r) == '_') &&
                              !(isalpha(*(tp - 1)) || *(tp - 1) == '$' ||
                                *(tp - 1) == '_')))) ||
                (judgename(a[i]) &&
                 (!(isalpha(tp[strlen(a[i])]) || isdigit(tp[strlen(a[i])]) ||
                    tp[strlen(a[i])] == '$' || tp[strlen(a[i])] == '_') &&
                  (tp == r || (!(isalpha(*(tp - 1)) || isdigit(*(tp - 1)) ||
                                 *(tp - 1) == '$' || *(tp - 1) == '_')))))) {
              p = tp;
              q = i;
            }
      }
      if (isdigit(*r)) {
        while (r < p && isdigit(*r)) {
          s << *r;
          r++;
        }
        s << ' ';
      }
      while (r < p) {
        s << *r;
        r++;
      }
      s << ' ';
      if (q == 0) break;
      char *tp = a[q];
      while (*tp) {
        s << *tp;
        tp++;
        r++;
      }
      s << ' ';
    }
  }
  string tmp;
  int k = 1, flag = 0;
  string all, last[20000];
  int ttt = 1;
  while (s >> tmp) {
    if (isdigit(tmp[0])) {
      int w = last[ttt - 1].size() - 1, ntmp;
      for (int i = 1; i < ttt; i++) {
        if (mp.count(last[i] + tmp)) goto prrt;
      }
      if (ttt != 1 && (isalpha(last[ttt - 1][w]) || isdigit(last[ttt - 1][w]) ||
                       last[ttt - 1][w] == '$' || last[ttt - 1][w] == '_')) {
        if (rev.count(last[ttt - 1]) &&
            !(judgename(last[ttt - 1]) || judgedigit(last[ttt - 1])))
          goto nxttt;
      prrt:
        cout << ' ';
        ttt = 1;
        last[1] = "";
        goto nnnxt;
      }
    nxttt:
      ntmp = tmp.size();
      for (int i = 1; i < ttt; i++) {
        if (last[i].size() + ntmp > lenmax * 2) continue;
        string s1 = last[i], s2 = tmp;
        while (s2 != "") {
          s1 += s2[0];
          s2 = s2.substr(1, s2.size() - 1);
          if (mp.count(s1)) goto ppprt;
        }
      }
      goto nnnxt;
    ppprt:
      cout << ' ';
      ttt = 1;
      last[1] = "";
    nnnxt:
      cout << tmp;
      for (int i = 1; i < ttt; i++) last[i] += tmp;
      last[ttt++] = tmp;
      continue;
    }
    if (mp[tmp] == "") {
      while (rev.count(tostr(k))) k++;
      mp[tmp] = tostr(k);
      k++;
    }
    int w = 0;
    if (ttt != 1 &&
        (((isalpha(last[ttt - 1][w]) || last[ttt - 1][w] == '$' ||
           last[ttt - 1][w] == '_') &&
          (isalpha(mp[tmp][0]) || isdigit(mp[tmp][0]) || mp[tmp][0] == '$' ||
           mp[tmp][0] == '_')) ||
         mp.count(last[ttt - 1] + mp[tmp]) || mp.count(last[1] + mp[tmp]))) {
      for (int i = 0; i < last[ttt - 1].size(); i++) {
        char ch = last[ttt - 1][i];
        if (!(isdigit(ch) || isalpha(ch) || ch == '$' || ch == '_')) goto nnexx;
      }
      cout << ' ';
      last[1] = "";
      ttt = 1;
    } else
      while (1) {
      nnexx:
        int ntmp = mp[tmp].size();
        for (int i = 1; i < ttt; i++) {
          if (last[i].size() + ntmp > lenmax * 2) continue;
          string s1 = last[i], s2 = mp[tmp];
          while (s2 != "") {
            s1 += s2[0];
            s2 = s2.substr(1, s2.size() - 1);
            if (mp.count(s1)) goto prt;
          }
        }
        break;
      prt:
        cout << ' ';
        ttt = 1;
        last[1] = "";
        break;
      }
  nexx:
    cout << mp[tmp];
    for (int i = 1; i < ttt; i++) last[i] += mp[tmp];
    last[ttt++] = mp[tmp];
  }
  cout << endl;
  return 0;
}
