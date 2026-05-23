#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> R;
vector<int> P;
vector<int> B;
long long maxgap(const vector<int> &q) {
  int res = 0;
  for (int i = 0; i + 1 < (int)q.size(); ++i) {
    res = max(res, q[i + 1] - q[i]);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    char c;
    cin >> x >> c;
    if (c == 'R')
      R.push_back(x);
    else if (c == 'P')
      P.push_back(x);
    else
      B.push_back(x);
  }
  sort(R.begin(), R.end());
  sort(P.begin(), P.end());
  sort(B.begin(), B.end());
  int ir = 0;
  int ib = 0;
  long long wynik = 0;
  for (int ip = 0; ip + 1 < (int)P.size(); ++ip) {
    while (ir < (int)R.size() && R[ir] < P[ip]) ir++;
    while (ib < (int)B.size() && B[ib] < P[ip]) ib++;
    vector<int> pomr;
    pomr.push_back(P[ip]);
    while (ir < (int)R.size() && R[ir] <= P[ip + 1]) {
      pomr.push_back(R[ir]);
      ir++;
    }
    pomr.push_back(P[ip + 1]);
    vector<int> pomb;
    pomb.push_back(P[ip]);
    while (ib < (int)B.size() && B[ib] <= P[ip + 1]) {
      pomb.push_back(B[ib]);
      ib++;
    }
    pomb.push_back(P[ip + 1]);
    long long dis = P[ip + 1] - P[ip];
    long long res = 3 * dis - maxgap(pomr) - maxgap(pomb);
    res = min(res, 2 * dis);
    wynik += res;
  }
  if (!P.empty()) {
    if (!R.empty()) {
      if (R[0] < P[0]) wynik += P[0] - R[0];
      if (R.back() > P.back()) wynik += R.back() - P.back();
    }
    if (!B.empty()) {
      if (B[0] < P[0]) wynik += P[0] - B[0];
      if (B.back() > P.back()) wynik += B.back() - P.back();
    }
  } else {
    wynik = 0;
    if (!R.empty()) wynik += R.back() - R[0];
    if (!B.empty()) wynik += B.back() - B[0];
  }
  cout << wynik << endl;
  return 0;
}
