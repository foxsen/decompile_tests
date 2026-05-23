#include <bits/stdc++.h>
using namespace std;
int n;
int perm[110];
bool viz[110];
int v[110];
int cmmdc(int a, int b) {
  if (b == 0) return a;
  return cmmdc(b, a % b);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> perm[i];
    v[perm[i]]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (v[i] != 1) {
      cout << -1 << "\n";
      return;
    }
  }
  vector<int> cycles;
  for (int i = 1; i <= n; ++i) {
    if (!viz[i]) {
      viz[i] = true;
      int cnt = 1;
      for (int j = perm[i]; j != i; j = perm[j]) {
        viz[j] = true;
        ++cnt;
      }
      cycles.push_back(cnt);
    }
  }
  long long cmmmc = 1;
  for (auto el : cycles) {
    if (el % 2 == 0) el /= 2;
    cmmmc = cmmmc * el / cmmdc(el, cmmmc);
  }
  cout << cmmmc << "\n";
}
void reset() {
  for (int i = 1; i <= n; ++i) {
    v[i] = viz[i] = 0;
  }
}
int main() {
  int k = 1;
  for (; k <= 1; ++k) {
    reset();
    solve();
  }
}
