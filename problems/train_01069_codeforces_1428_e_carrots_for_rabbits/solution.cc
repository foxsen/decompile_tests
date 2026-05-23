#include <bits/stdc++.h>
struct Split {
  int totSz;
  int pcs;
};
using LL = long long;
LL cost(Split s) {
  int q = s.totSz / s.pcs;
  int r = s.totSz % s.pcs;
  return 1LL * q * q * (s.pcs - r) + 1LL * (q + 1) * (q + 1) * r;
}
LL valNext(Split s) {
  LL pc = cost(s);
  ++s.pcs;
  assert(pc - cost(s) >= 0);
  return pc - cost(s);
}
int nPieces(int initLen, LL val) {
  int L = 1;
  int R = initLen;
  while (L < R) {
    int M = (L + R) / 2;
    if (valNext(Split{initLen, M}) < val)
      R = M;
    else
      L = M + 1;
  }
  return L;
}
int main() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  LL k;
  cin >> n >> k;
  vector<int> a = vector<int>(n);
  int max_ai = 0;
  for (int& ai : a) {
    cin >> ai;
    max_ai = max(max_ai, ai);
  }
  LL L = 1;
  LL R = 1LL * max_ai * max_ai;
  while (L < R) {
    LL M = (L + R + 1) / 2;
    LL pieceTot = 0LL;
    for (int& ai : a) pieceTot += nPieces(ai, M);
    if (pieceTot < k)
      R = M - 1;
    else
      L = M;
  }
  LL pieceTot = 0LL;
  LL sqTot = 0LL;
  for (int& ai : a) {
    int ci = nPieces(ai, L);
    pieceTot += ci;
    sqTot += cost(Split{ai, ci});
  }
  assert(pieceTot >= k);
  sqTot += L * (pieceTot - k);
  cout << sqTot << '\n';
  return 0;
}
