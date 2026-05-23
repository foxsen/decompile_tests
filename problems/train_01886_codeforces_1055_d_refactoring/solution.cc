#include <bits/stdc++.h>
using namespace std;
string cur, res, w[3005], k[3005];
int stt[3005], ed[3005], f[3005];
char tmp[3005];
void build(string s) {
  for (int i = 1; i < (int)s.length(); i++) {
    f[i] = f[i - 1];
    while (s[f[i]] != s[i]) {
      if (!f[i]) break;
      f[i] = f[f[i] - 1];
    }
    if (s[f[i]] == s[i]) f[i]++;
  }
}
int kmp(string s, string patt) {
  int src[s.length()];
  int res = -1;
  for (int i = 0; i < (int)s.length(); i++) {
    if (!i) {
      src[i] = s[i] == patt[i];
      if (src[i] == patt.length()) {
        res = i;
        break;
      }
      continue;
    }
    src[i] = src[i - 1];
    while (s[i] != patt[src[i]]) {
      if (!src[i]) break;
      src[i] = f[src[i] - 1];
    }
    if (s[i] == patt[src[i]]) src[i]++;
    if (src[i] == patt.length()) {
      res = i;
      break;
    }
  }
  return res;
}
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", &tmp);
    w[i] = tmp;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%s", &tmp);
    k[i] = tmp;
  }
  for (int i = 1; i <= n; i++) {
    string s, t;
    s = w[i];
    t = k[i];
    int fi = -1, se = -1;
    for (int j = 0; j < (int)s.length(); j++) {
      if (s[j] != t[j]) {
        se = j;
        if (!(~fi)) fi = j;
      }
    }
    if (!(~fi)) {
      stt[i] = -1;
      ed[i] = -1;
      continue;
    }
    stt[i] = fi;
    ed[i] = se;
    if (!cur.length()) {
      cur = s.substr(fi, se - fi + 1);
      res = t.substr(fi, se - fi + 1);
    }
    if ((cur != s.substr(fi, se - fi + 1)) ||
        (res != t.substr(fi, se - fi + 1))) {
      printf("NO");
      return 0;
    }
  }
  while (1) {
    int h = -1;
    for (int i = 1; i <= n; i++) {
      if (!(~stt[i])) continue;
      if (!stt[i]) {
        h = 0;
        break;
      }
      if (!(~h)) h = w[i][stt[i] - 1] - '0';
      if (h != w[i][stt[i] - 1] - '0') {
        h = 0;
        break;
      }
    }
    if (!h) break;
    for (int i = 1; i <= n; i++) {
      if (!(~stt[i])) continue;
      stt[i]--;
    }
  }
  while (1) {
    int h = -1;
    for (int i = 1; i <= n; i++) {
      if (!(~ed[i])) continue;
      if (ed[i] == w[i].size() - 1) {
        h = 0;
        break;
      }
      if (!(~h)) h = w[i][ed[i] + 1] - '0';
      if (h != w[i][ed[i] + 1] - '0') {
        h = 0;
        break;
      }
    }
    if (!h) break;
    for (int i = 1; i <= n; i++) {
      if (!(~ed[i])) continue;
      ed[i]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (stt[i] != -1) {
      cur = w[i].substr(stt[i], ed[i] - stt[i] + 1);
      res = k[i].substr(stt[i], ed[i] - stt[i] + 1);
      break;
    }
  }
  build(cur);
  for (int i = 1; i <= n; i++) {
    int k = kmp(w[i], cur);
    if (((stt[i] == -1) && (k >= 0)) || ((stt[i] >= 0) && (k == -1))) {
      printf("NO");
      return 0;
    }
    if (k != ed[i]) {
      printf("NO");
      return 0;
    }
  }
  printf("YES\n%s\n%s", cur.c_str(), res.c_str());
  return 0;
}
