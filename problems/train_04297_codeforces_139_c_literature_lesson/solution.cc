#include <bits/stdc++.h>
using namespace std;
typedef struct {
  char c[15000];
  int ipos, len;
} st;
bool glas(char s) {
  if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') return true;
  return false;
}
int findPos(st* a, int k) {
  if (a->len == -1) a->len = strlen(a->c);
  if (a->ipos == -2) return -1;
  int i, p = 0;
  for (i = a->len - 1; i >= 0; --i) {
    if (glas(a->c[i])) {
      p++;
      if (p == k) {
        a->ipos = i;
        return i;
      }
    }
  }
  a->ipos = -2;
  return -1;
}
int rif(st* a, st* b, int k) {
  int r1 = a->ipos, r2 = b->ipos, i;
  if (a->ipos == -1) r1 = findPos(a, k);
  if (r1 == -1) return -1;
  if (b->ipos == -1) r2 = findPos(b, k);
  if (r2 == -1) return -1;
  if (a->len - a->ipos != b->len - b->ipos) return -1;
  for (i = 0; i < a->len - a->ipos; ++i) {
    if (a->c[i + a->ipos] != b->c[i + b->ipos]) return -1;
  }
  return 1;
}
int main() {
  int i, j, n, k;
  st chet[5];
  cin >> n >> k;
  bool bSmeg = true, bPer = true, bOp = true, bAll = true;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < 4; ++j) {
      cin >> chet[j].c;
      chet[j].ipos = -1;
      chet[j].len = -1;
    }
    int y1 = rif((st*)&chet[0], (st*)&chet[1], k);
    int y2 = rif((st*)&chet[2], (st*)&chet[3], k);
    if (y1 != 1 || y2 != 1) {
      bSmeg = false;
      bAll = false;
    }
    y1 = rif((st*)&chet[0], (st*)&chet[2], k);
    y2 = rif((st*)&chet[1], (st*)&chet[3], k);
    if (y1 != 1 || y2 != 1) {
      bPer = false;
      bAll = false;
    }
    y1 = rif((st*)&chet[0], (st*)&chet[3], k);
    y2 = rif((st*)&chet[1], (st*)&chet[2], k);
    if (y1 != 1 || y2 != 1) {
      bOp = false;
      bAll = false;
    }
  }
  if (bAll) {
    cout << "aaaa";
    return 0;
  }
  if (bSmeg) {
    cout << "aabb";
    return 0;
  }
  if (bPer) {
    cout << "abab";
    return 0;
  }
  if (bOp) {
    cout << "abba";
    return 0;
  }
  cout << "NO";
  return 0;
}
