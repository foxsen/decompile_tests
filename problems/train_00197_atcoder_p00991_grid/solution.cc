#include<iostream>
#include<cmath>
 
using namespace std;
 
#define rep(i, n) for (int i = 0; i < int(n); ++i)
 
const int MOD = 100000007;
 
long long nck[1111][1111];
 
int main() {
  rep (i, 1111) nck[i][0] = 1;
  rep (i, 1110) rep (j, 1110) {
    nck[i + 1][j + 1] = (nck[i][j] + nck[i][j + 1]) % MOD;
  }
  int r, c, a1, a2, b1, b2, t = 1;
  cin >> r >> c >> a1 >> a2 >> b1 >> b2;
  if (r == abs(a1 - b1) * 2) t *= 2;
  if (c == abs(a2 - b2) * 2) t *= 2;
  int aa = min(abs(a1 - b1), r - abs(a1 - b1));
  int bb = min(abs(a2 - b2), c - abs(a2 - b2));
  cout << nck[aa + bb][aa] * t % MOD << endl;
  return 0;
}