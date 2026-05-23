#include <bits/stdc++.h>
using namespace std;
long long N, M;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  if (N > M) swap(N, M);
  long long Ans = 0;
  if (N == 1) {
    Ans = (M / 6) * 6 + ((M % 6 == 4) ? 2 : (M % 6 == 5) ? 4 : 0);
  } else if (N == 2) {
    Ans = (M == 2) ? 0 : (M == 3) ? 4 : (M == 7) ? 12 : M * 2;
  } else {
    long long Ans2, Ans3;
    Ans2 = N / 2 * ((M == 2) ? 0 : (M == 3) ? 4 : (M == 7) ? 12 : M * 2);
    if (N % 2 == 1)
      Ans2 += (M / 6) * 6 + ((M % 6 == 4) ? 2 : (M % 6 == 5) ? 4 : 0);
    Ans3 = N / 3 * 3 * M;
    if (M % 2 != 0) Ans3--;
    if (N % 3 == 1)
      Ans3 += (M / 6) * 6 + ((M % 6 == 4) ? 2 : (M % 6 == 5) ? 4 : 0);
    if (N % 3 == 2)
      Ans3 += ((M == 2) ? 0 : (M == 3) ? 4 : (M == 7) ? 12 : M * 2);
    Ans = max(Ans2, Ans3);
  }
  cout << Ans << '\n';
  return 0;
}
