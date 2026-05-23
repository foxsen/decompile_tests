#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, X;
  cin >> N >> X;
  vector<int> C;
  C.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }
  sort(C.begin(), C.end());
  long long res = 0;
  for (int i = 0; i < N; ++i) {
    res += C[i] * X;
    X = max(1LL, X - 1);
  }
  cout << res << endl;
  return 0;
}
