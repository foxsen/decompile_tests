#include <bits/stdc++.h>
using namespace std;
const int MAXN = 111111;
const int SZ = 400;
struct Part {
  int Max;
  int cnt;
  int* a;
  Part() {
    a = new int[SZ];
    Max = -1;
    cnt = 0;
  }
  Part(const Part& p) {
    a = p.a;
    Max = p.Max;
    cnt = p.cnt;
  }
  void calcMax() { Max = *max_element(a, a + cnt); }
  void insert(int wh, int data) {
    for (int i = cnt; i >= wh; i--) a[i] = a[i - 1];
    a[wh] = data;
    ++cnt;
  }
};
vector<Part> p;
int allCnt;
int a[MAXN];
int c[MAXN];
int n;
int getPosition(int a) {
  int L = 0;
  for (int i = 0; i < (int)p.size(); i++) {
    if (p[i].Max > a) {
      for (int j = 0; j < p[i].cnt; j++) {
        if (p[i].a[j] > a) return L + j;
      }
    }
    L += p[i].cnt;
  }
  return allCnt;
}
void addToPosition(int pos, int a) {
  ++allCnt;
  int L = 0;
  for (int i = 0; i < (int)p.size(); i++) {
    if (L + p[i].cnt >= pos || i == (int)p.size() - 1) {
      p[i].insert(pos - L, a);
      if (p[i].cnt == SZ - 2) {
        p.insert(p.begin() + i + 1, Part());
        for (int j = 0; j < SZ / 2; j++) {
          p[i + 1].a[j] = p[i].a[p[i].cnt - (SZ / 2) + j];
        }
        p[i].cnt -= SZ / 2;
        p[i + 1].cnt = SZ / 2;
        p[i + 1].calcMax();
      }
      p[i].calcMax();
      break;
    }
    L += p[i].cnt;
  }
}
int order[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &c[i]);
    --a[i];
    order[a[i]] = i;
  }
  allCnt = 0;
  p.push_back(Part());
  for (int i = 0; i < n; ++i) {
    int pos = getPosition(a[i]);
    pos = min(pos, c[i]);
    addToPosition(pos, a[i]);
  }
  vector<int> res;
  for (int i = 0; i < (int)p.size(); i++)
    for (int j = 0; j < p[i].cnt; j++) {
      res.push_back(order[p[i].a[j]]);
    }
  reverse(res.begin(), res.end());
  for (int i = 0; i < (int)res.size(); ++i)
    printf("%d%c", res[i] + 1, (i == (int)res.size() - 1) ? '\n' : ' ');
  return 0;
}
