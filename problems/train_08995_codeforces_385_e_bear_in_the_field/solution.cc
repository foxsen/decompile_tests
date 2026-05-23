#include <bits/stdc++.h>
using namespace std;
long long step[6][6] = {{2, 1, 1, 1, 0, 0}, {1, 2, 1, 1, 0, 0},
                        {1, 0, 1, 0, 0, 0}, {0, 1, 0, 1, 0, 0},
                        {1, 1, 1, 1, 1, 0}, {2, 2, 2, 2, 1, 1}};
long long n;
void makeIdentity(long long** m) {
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j) m[i][i] = i == j ? 1 : 0;
}
long long mod(long long x) { return (x + n) % n; }
void mult(long long** m1, long long** m2, long long** m) {
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j) {
      m[i][j] = 0;
      for (int k = 0; k < 6; ++k)
        m[i][j] = mod(m[i][j] + mod(m1[i][k] * m2[k][j]));
    }
}
void copyM(long long** m1, long long** m2) {
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j) m1[i][j] = m2[i][j];
}
void createM(long long*** m) {
  *m = new long long*[6];
  for (int i = 0; i < 6; ++i) (*m)[i] = new long long[6];
}
void pow(long long** m, long long e) {
  if (e == 0)
    makeIdentity(m);
  else if (e == 1)
    return;
  else if (e % 2 == 1) {
    long long** cm1;
    createM(&cm1);
    copyM(cm1, m);
    long long** cm2;
    createM(&cm2);
    copyM(cm2, m);
    pow(cm2, e - 1);
    mult(cm1, cm2, m);
  } else {
    long long** cm;
    createM(&cm);
    copyM(cm, m);
    mult(cm, cm, m);
    pow(m, e / 2);
  }
}
int main() {
  long long v[6];
  v[5] = 1;
  v[4] = 0;
  long long t;
  cin >> n >> v[0] >> v[1] >> v[2] >> v[3] >> t;
  v[0]--;
  v[1]--;
  v[2] = mod(v[2]);
  v[3] = mod(v[3]);
  long long** m;
  createM(&m);
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j) m[i][j] = step[i][j];
  pow(m, t);
  long long resx = 0, resy = 0;
  for (int i = 0; i < 6; ++i) {
    resx = mod(resx + mod(v[i] * m[i][0]));
    resy = mod(resy + mod(v[i] * m[i][1]));
  }
  cout << resx + 1 << " " << resy + 1 << "\n";
  return 0;
}
