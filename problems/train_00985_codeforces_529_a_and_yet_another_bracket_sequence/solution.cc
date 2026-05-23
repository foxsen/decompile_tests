#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000047;
char s[maxn];
int n;
vector<int> utried() {
  vector<int> lepsich(n);
  vector<int> por;
  int otv = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      por.push_back(i);
      lepsich[i] = 0;
      otv++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == ')') {
      por.push_back(i);
      lepsich[i] = otv;
    }
  }
  for (int sl = 1; sl < n; sl *= 2) {
    vector<int> npor(n), off(n, 0);
    for (int i = 0; i < n; i++) {
      int ind = (por[i] - sl + n) % n;
      npor[lepsich[ind] + off[lepsich[ind]]] = ind;
      off[lepsich[ind]]++;
    }
    por = npor;
    vector<int> nlepsich(n);
    nlepsich[por[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (lepsich[por[i]] == lepsich[por[i - 1]] &&
          lepsich[(por[i] + sl) % n] == lepsich[(por[i - 1] + sl) % n]) {
        nlepsich[por[i]] = nlepsich[por[i - 1]];
      } else
        nlepsich[por[i]] = i;
    }
    lepsich = nlepsich;
  }
  return por;
}
int main() {
  scanf("%s", s);
  for (n = 0; s[n] != 0; n++)
    ;
  vector<int> depth(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '(')
      depth[i] = depth[i - 1] + 1;
    else
      depth[i] = depth[i - 1] - 1;
  }
  vector<int> minpred(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    minpred[i] = min(depth[i], minpred[i - 1]);
  }
  vector<int> minpo(n + 1, 1023456789);
  for (int i = n - 1; i >= 0; i--) {
    minpo[i] = min(depth[i + 1], minpo[i + 1]);
  }
  vector<bool> can_be(n, 0);
  for (int i = 0; i < n; i++) {
    if (depth[n] < 0) {
      can_be[i] = (minpo[i] - depth[i] >= depth[n] && minpred[i] >= depth[i]);
    } else {
      can_be[i] = (minpo[i] >= depth[i] && minpred[i] + depth[n] >= depth[i]);
    }
  }
  vector<int> por = utried();
  int st = -1;
  for (int i = 0; i < n; i++) {
    if (can_be[por[i]]) {
      st = por[i];
      break;
    }
  }
  if (depth[n] < 0) {
    for (int i = 0; i < (0 - depth[n]); i++) {
      printf("(");
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%c", s[(i + st) % n]);
  }
  if (depth[n] > 0) {
    for (int i = 0; i < depth[n]; i++) printf(")");
  }
  printf("\n");
  return 0;
}
