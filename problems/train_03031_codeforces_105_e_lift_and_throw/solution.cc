#include <bits/stdc++.h>
using namespace std;
struct person {
  int acc, pos;
  bool thr, moved;
};
struct property {
  int mrange, trange, ipos;
} P[3];
struct state {
  person P[3];
  int to_int() {
    int res(0);
    for (int i = 0; i < 3; ++i) {
      if (P[i].pos >= 64) throw logic_error("@L21");
      res = (res << 1) | P[i].thr;
      res = (res << 1) | P[i].moved;
      res = (res << 2) | P[i].acc;
      res = (res << 6) | P[i].pos;
    }
    return res;
  }
  person &operator[](int p) { return P[p]; }
  int check(int p) {
    int isfree[3];
    for (int i = 0; i < 3; ++i) isfree[i] = true;
    for (int i = 0; i < 3; ++i)
      if (P[i].acc) isfree[P[i].acc - 1] = false;
    for (int i = 0; i < 3; ++i)
      if (isfree[i] && P[i].pos == p) return false;
    return true;
  }
};
unordered_set<int> S;
int res;
void dfs(state s) {
  int hval = s.to_int();
  if (S.find(hval) != S.end()) return;
  S.insert(hval);
  for (int i = 0; i < 3; ++i) res = max(res, s[i].pos);
  bool isfree[3] = {true, true, true};
  for (int i = 0; i < 3; ++i)
    if (s[i].acc) isfree[s[i].acc - 1] = false;
  for (int i = 0; i < 3; ++i) {
    if (!isfree[i]) continue;
    if (!s[i].moved && !s[i].acc) {
      s[i].moved = true;
      for (int d = 1; d <= P[i].mrange; ++d) {
        if (!s.check(s[i].pos + d)) continue;
        s[i].pos += d;
        dfs(s);
        s[i].pos -= d;
      }
      for (int d = 1; d <= P[i].mrange; ++d) {
        if (s[i].pos - d < 0) break;
        if (!s.check(s[i].pos - d)) continue;
        s[i].pos -= d;
        dfs(s);
        s[i].pos += d;
      }
      s[i].moved = false;
    }
    if (!s[i].thr && !s[i].acc) {
      for (int j = 0, pbak; j < 3; ++j)
        if (j != i && isfree[j] && abs(s[j].pos - s[i].pos) == 1) {
          s[i].acc = j + 1;
          dfs(s);
          s[i].acc = 0;
        }
    }
    if (!s[i].thr && s[i].acc) {
      int z = s[i].acc - 1;
      s[i].acc = 0;
      s[i].thr = true;
      for (int d = 1, pbak; d <= P[i].trange; ++d) {
        if (!s.check(s[i].pos + d)) continue;
        pbak = s[z].pos;
        s[z].pos = s[i].pos + d;
        dfs(s);
        s[z].pos = pbak;
      }
      s[i].acc = z + 1;
      s[i].thr = false;
    }
  }
}
int main() {
  for (int i = 0; i < 3; ++i)
    scanf("%d%d%d", &P[i].ipos, &P[i].mrange, &P[i].trange);
  sort(P, P + 3,
       [](const property &a, const property &b) { return a.ipos < b.ipos; });
  state si;
  for (int i = 0; i < 3; ++i) {
    si[i].thr = si[i].moved = false;
    si[i].acc = 0;
    si[i].pos = P[i].ipos;
  }
  dfs(si);
  printf("%d\n", res);
  fprintf(stderr, "%d\n", S.size());
  return 0;
}
