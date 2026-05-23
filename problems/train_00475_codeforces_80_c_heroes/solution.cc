#include <bits/stdc++.h>
using namespace std;
char nm[8][15] = {"",       "Anka",  "Chapay", "Snowy", "Hexadecimal",
                  "Dracul", "Troll", "Cleo"};
int m[10][10] = {{0}};
int n, a, b, c, i, k1, k2, k3;
int m1, m2, m3, md, d, p1, p2, p3, pp1, pp2;
int aa[20000][4] = {{0}}, mm;
void gen(int k1, int k2, int k3, bool f = 0) {
  p1 = a / k1;
  p2 = b / k2;
  p3 = c / k3;
  pp1 = max(p1, max(p3, p2));
  pp2 = min(p1, min(p3, p2));
  if (pp1 - pp2 < md || (f && pp1 - pp2 == md)) {
    md = pp1 - pp2;
    if (f) {
      mm++;
      aa[mm][1] = k1;
      aa[mm][2] = k2;
      aa[mm][3] = k3;
    }
  }
}
int main() {
  char s1[15] = {0}, s2[15] = {0}, s3[15] = {0};
  cin >> n;
  int t, j;
  for (i = 1; i <= n; i++) {
    cin >> s1 >> s2 >> s3;
    for (j = 1; j <= 7; j++)
      if (strcmp(s1, nm[j]) == 0) break;
    for (t = 1; t <= 7; t++)
      if (strcmp(s3, nm[t]) == 0) break;
    m[j][t] = 1;
  }
  cin >> a >> b >> c;
  md = 1000000000;
  for (j = 0; j <= 4; j++) {
    for (t = 0; j + t <= 4; t++) {
      k1 = 1 + j;
      k2 = 1 + t;
      k3 = 1 + 4 - t - j;
      gen(k1, k2, k3);
      gen(k1, k3, k2);
      gen(k2, k1, k3);
      gen(k2, k3, k1);
      gen(k3, k2, k1);
      gen(k3, k1, k2);
    }
  }
  for (j = 0; j <= 4; j++) {
    for (t = 0; j + t <= 4; t++) {
      k1 = 1 + j;
      k2 = 1 + t;
      k3 = 1 + 4 - t - j;
      gen(k1, k2, k3, 1);
      gen(k1, k3, k2, 1);
      gen(k2, k1, k3, 1);
      gen(k2, k3, k1, 1);
      gen(k3, k2, k1, 1);
      gen(k3, k1, k2, 1);
    }
  }
  int mm1 = 0;
  for (int ii = 1; ii <= mm; ii++) {
    m1 = aa[ii][1];
    m2 = aa[ii][2];
    m3 = aa[ii][3];
    int bb[8] = {0};
    for (i = 1; i <= m1; i++) bb[i] = 1;
    for (i = m1 + 1; i <= m2 + m1; i++) bb[i] = 2;
    for (i = m1 + m2 + 1; i <= 7; i++) bb[i] = 3;
    int k[4];
    do {
      k[3] = k[1] = k[2] = 0;
      for (i = 1; i <= 7; i++)
        for (j = 1; j <= 7; j++)
          if (bb[i] == bb[j]) k[bb[i]] += m[i][j];
      mm1 = max(mm1, k[3] + k[1] + k[2]);
    } while (next_permutation(bb + 1, bb + 8));
  }
  cout << md << ' ' << mm1;
  return 0;
}
