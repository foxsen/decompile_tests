#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  int A[100000];
  map<int, int> psums;
  int cSum = 0;
  int totSum = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    totSum += A[i];
  }
  if (totSum % 3) {
    cout << 0 << endl;
    return 0;
  }
  int want = 2 * (totSum / 3);
  long long ans = 0;
  for (int i = 0; i < (N - 1); i++) {
    cSum += A[i];
    if (cSum == want) ans += (long long)psums[totSum / 3];
    psums[cSum]++;
  }
  cout << ans << endl;
  return 0;
}
