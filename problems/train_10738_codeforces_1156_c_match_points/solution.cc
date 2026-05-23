#include <bits/stdc++.h>
using namespace std;
int N, Z, X[200000];
bool check(int C) {
  int offset = N - C;
  for (int i = 0; i < C; i++)
    if (X[offset + i] - X[i] < Z) return false;
  return true;
}
int main() {
  cin >> N >> Z;
  for (int i = 0; i < N; i++) cin >> X[i];
  sort(X, X + N);
  int ng = N / 2 + 1, ok = 0;
  while (ng - ok > 1) {
    int mid = (ng + ok) / 2;
    (check(mid) ? ok : ng) = mid;
  }
  cout << ok << endl;
  return 0;
}
