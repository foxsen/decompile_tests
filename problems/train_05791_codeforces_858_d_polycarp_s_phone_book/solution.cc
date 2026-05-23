#include <bits/stdc++.h>
using namespace std;
long long int mod1 = 1000000007;
long long int binpow(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int test;
  test = 1;
  for (long long int ftest = 0; ftest < test; ftest++) {
    long long int n;
    cin >> n;
    string A[n];
    long long int i, j, k;
    for (i = 0; i < n; i++) cin >> A[i];
    std::map<string, long long int> make_pair;
    for (i = 0; i < n; i++) {
      set<string> S;
      for (j = 0; j < 9; j++) {
        string B;
        for (k = j; k < 9; k++) {
          B.push_back(A[i][k]);
          long long int x = S.size();
          S.insert(B);
          long long int y = S.size();
          if (y == x) {
          } else {
            make_pair[B]++;
          }
        }
      }
    }
    for (i = 0; i < n; i++) {
      string X = "12345678910";
      for (j = 0; j < 9; j++) {
        string B;
        for (k = j; k < 9; k++) {
          B.push_back(A[i][k]);
          if (make_pair[B] == 1) {
            if ((long long int)(B.size()) < (long long int)(X.size())) X = B;
          }
        }
      }
      cout << X << '\n';
    }
  }
}
