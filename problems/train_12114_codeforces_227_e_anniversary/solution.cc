#include <bits/stdc++.h>
using namespace std;
int Mod;
void add_self(int& x, int y) {
  if ((x += y) >= Mod) x -= Mod;
}
int mul(int x, int y) { return (long long)x * y % Mod; }
vector<vector<int> > Zero(int n, int m) {
  return vector<vector<int> >(n, vector<int>(m, 0));
}
vector<vector<int> > Ident(int n) {
  vector<vector<int> > Res = Zero(n, n);
  for (int i = 0; i < n; i++) Res[i][i] = 1;
  return Res;
}
vector<vector<int> > Multy(const vector<vector<int> >& A,
                           const vector<vector<int> >& B) {
  assert(A[0].size() == B.size());
  vector<vector<int> > Res = Zero(A.size(), B[0].size());
  for (int i = 0; i < Res.size(); i++)
    for (int j = 0; j < Res[0].size(); j++)
      for (int k = 0; k < B.size(); k++)
        add_self(Res[i][j], mul(A[i][k], B[k][j]));
  return Res;
}
vector<vector<int> > Power(const vector<vector<int> >& A, long long k) {
  if (!k) return Ident(A.size());
  if (k & 1) return Multy(A, Power(A, k - 1));
  return Power(Multy(A, A), k >> 1);
}
int Fib(long long n) {
  vector<vector<int> > Base = Zero(1, 2);
  Base[0][0] = Base[0][1] = 1;
  vector<vector<int> > Trans = Zero(2, 2);
  Trans[0][1] = Trans[1][0] = Trans[1][1] = 1;
  vector<vector<int> > Res = Multy(Base, Power(Trans, n - 1));
  return Res[0][0];
}
int main() {
  long long L, R, k;
  cin >> Mod >> L >> R >> k;
  long long Ans = 1;
  for (long long x = 1;; x = R / (R / (x + 1))) {
    long long y = R / x;
    long long Cnt = R / y - (L - 1) / y;
    if (Cnt >= k) Ans = max(Ans, y);
    if (x == R) break;
  }
  cout << Fib(Ans) << endl;
}
