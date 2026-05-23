#include <bits/stdc++.h>
using namespace std;
int n, v[3000000], cs, cd, rez, st, crt, rsp = 8000000, i, aux, a;
int main() {
  cin >> n >> st;
  for (i = 1; i <= n; i++) {
    cin >> aux;
    v[aux + 1500000]++;
  }
  cs = -1000000;
  cd = -1000000;
  rez += v[cd + 1500000];
  while (rez < n - 1) {
    cd++;
    rez += v[cd + 1500000];
  }
  while (cd <= 1000000) {
    a = 0;
    if (rez >= n - 1) {
      if (cs <= st && cd <= st)
        a = st - cs;
      else if (cs >= st && cd >= st)
        a = cd - st;
      else
        a = cd - cs + min(cd - st, st - cs);
      rsp = min(rsp, a);
      if (cs == cd) {
        cd++;
        rez += v[cd + 1500000];
      } else {
        cs++;
        rez -= v[cs - 1 + 1500000];
      }
    } else {
      cd++;
      rez += v[cd + 1500000];
    }
  }
  cout << rsp;
  return 0;
}
