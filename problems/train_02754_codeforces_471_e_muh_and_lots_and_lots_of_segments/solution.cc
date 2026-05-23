#include <bits/stdc++.h>
using namespace std;
struct event {
  int x, type, y, righty;
};
struct P {
  int right, dsu, number;
};
int xbegin[1000000], compcount, fen[1000000], xend[1000000], ybegin[1000000],
    yend[1000000], realx[1000000], realy[1000000], parent[1000000];
event events[1000000];
long long ans[1000000], best;
pair<int, int> xx[1000000], yy[1000000];
map<int, P> lefts;
set<int> s;
int v, n;
void event_vertical(int x, int yl, int yr) {
  v++;
  events[v].x = x;
  events[v].type = 2;
  events[v].y = yl;
  events[v].righty = yr;
}
void event_horizantal_begin(int x, int y, int xx) {
  v++;
  events[v].x = x;
  events[v].type = 1;
  events[v].y = y;
  events[v].righty = xx;
}
void event_horizantal_end(int x, int y) {
  v++;
  events[v].x = x;
  events[v].type = 3;
  events[v].y = y;
  events[v].righty = 0;
}
bool CMP(const event& i, const event& j) {
  return (i.x < j.x || (i.x == j.x && i.type < j.type));
}
void compressX() {
  for (int i = 1; i <= n; i++) xx[i] = make_pair(xbegin[i], i);
  for (int i = 1; i <= n; i++) xx[i + n] = make_pair(xend[i], i + n);
  sort(xx + 1, xx + 2 * n + 1);
  int v = 1;
  xx[0] = make_pair(xx[1].first - 1, 0);
  for (int i = 1; i <= 2 * n; i++) {
    if (xx[i].first != xx[i - 1].first) v++;
    realx[v] = xx[i].first;
    int t = xx[i].second;
    if (t > n)
      xend[t - n] = v;
    else
      xbegin[t] = v;
  }
}
void compressY() {
  for (int i = 1; i <= n; i++) yy[i] = make_pair(ybegin[i], i);
  for (int i = 1; i <= n; i++) yy[i + n] = make_pair(yend[i], i + n);
  sort(yy + 1, yy + 2 * n + 1);
  int v = 1;
  yy[0] = make_pair(yy[1].first - 1, 0);
  for (int i = 1; i <= 2 * n; i++) {
    if (yy[i].first != yy[i - 1].first) v++;
    realy[v] = yy[i].first;
    int t = yy[i].second;
    if (t > n)
      yend[t - n] = v;
    else
      ybegin[t] = v;
  }
}
void init() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> xbegin[i] >> ybegin[i] >> xend[i] >> yend[i];
  compressX();
  compressY();
}
void make_events() {
  v = 0;
  for (int i = 1; i <= n; i++) {
    if (xbegin[i] == xend[i])
      event_vertical(xbegin[i], ybegin[i], yend[i]);
    else {
      event_horizantal_begin(xbegin[i], ybegin[i], xend[i]);
      event_horizantal_end(xend[i], ybegin[i]);
    }
  }
  sort(events + 1, events + v + 1, CMP);
}
int findsum(int x) {
  int s = 0;
  while (x >= 1) {
    s += fen[x];
    x = (x & (x - 1));
  }
  return s;
}
void md(int x, int y) {
  while (x <= 400010) {
    fen[x] += y;
    x = (x | (x - 1)) + 1;
  }
}
int findset(int x) {
  if (parent[x] == 0) return x;
  parent[x] = findset(parent[x]);
  return parent[x];
}
void divide(int y, int l) {
  set<int>::iterator it2 = s.upper_bound(y);
  it2--;
  P cnt = lefts[l];
  if (y > l) {
    int r = *it2;
    int nsize = findsum(r) - findsum(l - 1);
    lefts[l].right = r;
    lefts[l].number = nsize;
  } else
    lefts.erase(l);
  if (y < cnt.right) {
    it2++;
    int nl = *it2;
    int nsize = findsum(cnt.right) - findsum(nl - 1);
    lefts[nl].right = cnt.right;
    lefts[nl].dsu = cnt.dsu;
    lefts[nl].number = nsize;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  init();
  make_events();
  compcount = 0;
  best = 0;
  s.insert(0);
  s.insert(2000000);
  lefts[2000000] = {2000000, 0, 0};
  lefts[0] = {0, 0, 0};
  for (int i = 1; i <= v; i++) {
    if (events[i].type == 1) {
      int y = events[i].y;
      compcount++;
      ans[compcount] = realx[events[i].righty] - realx[events[i].x];
      map<int, P>::iterator it1 = lefts.upper_bound(y);
      it1--;
      int l = it1->first;
      if (l <= y && y <= lefts[l].right) divide(y, l);
      s.insert(y);
      lefts[y].right = y;
      lefts[y].dsu = compcount;
      lefts[y].number = 1;
      md(y, 1);
    }
    if (events[i].type == 3) {
      int y = events[i].y;
      s.erase(y);
      map<int, P>::iterator it = lefts.upper_bound(y);
      it--;
      md(y, -1);
      int l = it->first;
      if (lefts[l].right == l)
        lefts.erase(l);
      else if (lefts[l].right == y) {
        set<int>::iterator it = s.lower_bound(y);
        it--;
        lefts[l].right = *it;
        lefts[l].number--;
      } else if (l == y) {
        set<int>::iterator it = s.lower_bound(y);
        P cnt = lefts[l];
        lefts.erase(l);
        lefts[*it] = cnt;
        lefts[*it].number--;
      } else
        lefts[l].number--;
    }
    if (events[i].type == 2) {
      int yl = events[i].y;
      int yr = events[i].righty;
      if (realy[yr] - realy[yl] > best) best = realy[yr] - realy[yl];
      if (findsum(yr) - findsum(yl - 1) == 0) continue;
      int nDSU = 0;
      int nl = 0;
      int nr = 0;
      int dif = 1;
      map<int, P>::iterator it = lefts.lower_bound(yl);
      it--;
      int l = it->first;
      P cnt = lefts[l];
      if (cnt.right >= yl && l <= yl) {
        nl = l;
        nr = cnt.right;
        nDSU = findset(cnt.dsu);
        lefts.erase(l);
      }
      while (true) {
        map<int, P>::iterator it1 = lefts.lower_bound(yl);
        int l = it1->first;
        if (l > yr) break;
        if (lefts[l].right > yr) break;
        if (nl == 0) nl = l;
        P cnt = lefts[l];
        nr = cnt.right;
        if (nDSU == 0)
          nDSU = findset(cnt.dsu);
        else if (nDSU != findset(cnt.dsu)) {
          ans[nDSU] += ans[findset(cnt.dsu)];
          parent[findset(cnt.dsu)] = nDSU;
          dif++;
        }
        lefts.erase(l);
      }
      it = lefts.upper_bound(yr);
      it--;
      l = it->first;
      cnt = lefts[l];
      if (cnt.right >= yr && l <= yr) {
        if (nl == 0) nl = l;
        nr = cnt.right;
        if (nDSU == 0)
          nDSU = findset(cnt.dsu);
        else if (nDSU != findset(cnt.dsu)) {
          ans[nDSU] += ans[findset(cnt.dsu)];
          parent[findset(cnt.dsu)] = nDSU;
          dif++;
        }
        lefts.erase(l);
      }
      if (nDSU != 0) {
        lefts[nl].right = nr;
        lefts[nl].dsu = nDSU;
        lefts[nl].number = findsum(nr) - findsum(nl - 1);
        ans[nDSU] += realy[yr] - realy[yl] -
                     (findsum(yr) - findsum(yl - 1) - 1) + dif - 1;
      }
    }
  }
  for (int i = 1; i <= compcount; i++)
    if (ans[i] > best) best = ans[i];
  cout << best << endl;
  return 0;
}
