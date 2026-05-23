#include <bits/stdc++.h>
using namespace std;
vector<long long> cand;
long long solve(long long goal) {
  int indx = 0;
  int minim = 0, maxim = ((int)(cand).size()) - 1;
  while (minim <= maxim) {
    int mid = (minim + maxim) / 2;
    if (cand[mid] <= goal) {
      minim = mid + 1;
      indx = max(indx, mid);
    } else {
      maxim = mid - 1;
    }
  }
  long long ans = abs(cand[indx++] - goal);
  if (indx < ((int)(cand).size())) ans = min(ans, cand[indx] - goal);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  int N, M, Q;
  cin >> N >> M >> Q;
  long long a_sum = 0, s = 1;
  for (int i = (0); i < (N); i++) {
    int x;
    cin >> x;
    a_sum += s * x;
    s = -s;
  }
  vector<long long> b(M);
  for (int i = (0); i < (M); i++) {
    cin >> b[i];
  }
  long long cur = 0;
  s = 1;
  for (int i = (0); i < (N); i++) {
    cur += s * b[i];
    s = -s;
  }
  s = (N % 2) == 1 ? 1 : -1;
  cand.push_back(cur);
  for (int i = (N); i < (M); i++) {
    cur -= b[i - N];
    cur = -cur;
    cur += b[i] * s;
    cand.push_back(cur);
  }
  sort(cand.begin(), cand.end());
  cout << solve(a_sum) << "\n";
  for (int q = (0); q < (Q); q++) {
    int l, r, x;
    cin >> l >> r >> x;
    int amnt = r - l + 1;
    if (amnt % 2 == 1) {
      if (r % 2 == 0)
        a_sum -= x;
      else
        a_sum += x;
    }
    long long ans = solve(a_sum);
    cout << ans << "\n";
  }
  return 0;
}
