#include <bits/stdc++.h>
using namespace std;
int const N = 200000;
long double const eps = 1e-10;
int n, L;
long double an, fr, v;
set<pair<long double, int> > st;
void sc(long double &x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
struct S {
  int l, r, d;
  long double os, cs;
  void sc() {
    scanf("%d%d", &l, &r);
    ::sc(os);
    d = r - l;
    cs = 0.0;
  }
} sg[N];
void adfr() {
  if (v <= eps) return;
  long double d = min(fr, 2.0 * v);
  an -= d * 0.5;
  v -= d * 0.5;
  fr -= d;
}
void kl() {
  while (!st.empty() && v > eps) {
    int j = st.begin()->second;
    long double k = (1.0 - sg[j].cs) * sg[j].d / (sg[j].cs + sg[j].os) - v;
    long double ns = (sg[j].d - sg[j].os * k) / (sg[j].d + k);
    if (ns < sg[j].cs)
      ns = 2.0l;
    else
      ns = min(2.0l, ns);
    an -= sg[j].d / (sg[j].cs + sg[j].os);
    an += sg[j].d / (ns + sg[j].os);
    v -= (1.0l - sg[j].cs) * sg[j].d / (sg[j].cs + sg[j].os);
    v += (1.0l - ns) * sg[j].d / (ns + sg[j].os);
    sg[j].cs = ns;
    if (sg[j].cs + eps >= 2.0l) st.erase(st.begin());
  }
}
int main() {
  scanf("%d%d", &n, &L);
  an = L;
  for (int i = 0; i < (int)(n); ++i) sg[i].sc();
  int lst = L;
  for (int i = n - 1; i >= 0; --i) {
    fr += lst - sg[i].r;
    lst = sg[i].l;
    long double t = sg[i].d / sg[i].os;
    an -= sg[i].d;
    an += t;
    v += t;
    st.insert(make_pair(sg[i].os, i));
    adfr();
    kl();
  }
  printf("%.20lf\n", (double)an);
}
