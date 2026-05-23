#include <bits/stdc++.h>
using namespace std;
int N, y, K;
long long P;
int A[2 * 100005];
int pref[2 * 100005], suf[2 * 100005];
int main() {
  cin >> N >> K >> P;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  pref[0] = A[0];
  suf[N] = A[N];
  for (int i = 1; i < N; ++i) pref[i] = (A[i] | pref[i - 1]);
  for (int i = N - 1; i >= 0; --i) suf[i] = (A[i] | suf[i + 1]);
  long long ormax = -1;
  for (int i = 0; i < N; ++i) {
    long long x = A[i];
    for (int j = 0; j < K; ++j) x = P * x;
    long long orr;
    if (i == 0)
      orr = x | suf[i + 1];
    else
      orr = x | pref[i - 1] | suf[i + 1];
    ormax = max(orr, ormax);
  }
  cout << ormax;
  return 0;
}
