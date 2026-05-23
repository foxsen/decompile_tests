#include <bits/stdc++.h>
using namespace std;
const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;
int n;
bool kmp(string P) {
  P = "#" + P;
  int pi[P.size()], m = P.size() - 1, q = 0;
  pi[0] = pi[1] = 0;
  for (int i = 2; i <= m; ++i) {
    while (q && P[i] != P[q + 1]) q = pi[q];
    if (P[i] == P[q + 1]) ++q;
    pi[i] = q;
  }
  return !pi[m];
}
map<char, char> M;
string rev(string A) {
  reverse((A).begin(), (A).end());
  for (int i = 0; i < (A.size()); ++i) A[i] = M[A[i]];
  return A;
}
void solve() {
  M['W'] = 'E';
  M['E'] = 'W';
  M['S'] = 'N';
  M['N'] = 'S';
  scanf("%d", &n);
  string A, B;
  cin >> A >> B;
  puts(kmp(rev(A) + B) ? "YES" : "NO");
}
int main() {
  int te = 1;
  for (int ti = 0; ti < (te); ++ti) solve();
  return 0;
}
