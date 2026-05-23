#include <bits/stdc++.h>
struct St {
  int h, h1, h2, nom, type;
};
bool operator<(St a, St b) { return a.h1 - a.h2 > b.h1 - b.h2; }
St st[200000];
int k[100000];
int i, n, n2;
long long s, npart, a, b, c, d, npitca, fa, fb, fc, fd;
int cnt[100001];
long long sum(long long npi_1) {
  long long npi_2 = npitca - npi_1;
  long long npart_1 = npi_1 * npart, npart_2 = npi_2 * npart;
  long long count;
  long long ans = 0;
  int i, nom;
  for (i = 0; i < n; i++) cnt[i] = k[i];
  for (i = 0; i < n2; i++) {
    nom = st[i].nom;
    if (cnt[nom] == 0) continue;
    if (st[i].type == 1) {
      if (npart_1 == 0) continue;
      count = cnt[nom];
      if (count > npart_1) count = npart_1;
      ans = ans + count * st[i].h;
      npart_1 = npart_1 - count;
      cnt[nom] = cnt[nom] - count;
    } else {
      if (npart_2 == 0) continue;
      count = cnt[nom];
      if (count > npart_2) count = npart_2;
      ans = ans + count * st[i].h;
      npart_2 = npart_2 - count;
      cnt[nom] = cnt[nom] - count;
    }
  }
  return ans;
}
using namespace std;
int main() {
  scanf("%d %d", &n, &npart);
  s = 0;
  for (i = 0; i < n; i++) {
    int ha, hb;
    scanf("%d %d %d", &k[i], &ha, &hb);
    st[n2].nom = i;
    st[n2].h = ha;
    st[n2].h1 = ha;
    st[n2].h2 = hb;
    st[n2++].type = 1;
    st[n2].nom = i;
    st[n2].h = hb;
    st[n2].h1 = hb;
    st[n2].h2 = ha;
    st[n2++].type = 2;
    s = s + k[i];
  }
  npitca = s / npart;
  if (npitca * npart < s) npitca++;
  sort(st, st + n2);
  a = 0;
  b = npitca;
  while (a < b) {
    c = a + (b - a) / 3;
    d = b - (b - a) / 3;
    fc = sum(c);
    fd = sum(d);
    if (fc == fd)
      a = c + 1, b = d;
    else if (fc < fd)
      a = c + 1;
    else
      b = d - 1;
  }
  cout << sum(a) << endl;
}
