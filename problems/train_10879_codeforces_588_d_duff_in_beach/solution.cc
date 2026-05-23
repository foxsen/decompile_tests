#include <bits/stdc++.h>
using namespace std;
long long N, K, L;
int A[1000010];
int B[1000010];
long long howMany;
long long dp[1000010];
long long pref[1000010];
long long totalAns;
void f1() {
  for (int i = 1; i <= N; i++) {
    pref[i] = pref[i - 1] + 1;
  }
  totalAns += (pref[N] * (howMany % 1000000007)) % 1000000007;
  totalAns %= 1000000007;
  for (int i = 2; i <= min(K, howMany); i++) {
    for (int j = 1; j <= N; j++) {
      int temp = upper_bound(B + 1, B + 1 + N, B[j]) - B;
      dp[j] = pref[temp - 1];
    }
    for (int j = 1; j <= N; j++) {
      pref[j] = pref[j - 1] + dp[j];
      pref[j] %= 1000000007;
    }
    totalAns += (pref[N] * ((howMany - i + 1) % 1000000007)) % 1000000007;
    totalAns %= 1000000007;
  }
}
void f2() {
  for (int i = 1; i <= N; i++) {
    pref[i] = pref[i - 1] + 1;
  }
  totalAns += L % N;
  totalAns %= 1000000007;
  for (int i = 2; i <= min(K, howMany + 1); i++) {
    for (int j = 1; j <= L % N; j++) {
      int temp = upper_bound(B + 1, B + 1 + N, A[j]) - B;
      totalAns += pref[temp - 1];
      totalAns %= 1000000007;
    }
    for (int j = 1; j <= N; j++) {
      int temp = upper_bound(B + 1, B + 1 + N, B[j]) - B;
      dp[j] = pref[temp - 1];
    }
    for (int j = 1; j <= N; j++) {
      pref[j] = pref[j - 1] + dp[j];
      pref[j] %= 1000000007;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> N >> L >> K;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    B[i] = A[i];
  }
  sort(B + 1, B + 1 + N);
  howMany = L / N;
  if (howMany) {
    f1();
  }
  if (L % N) {
    f2();
  }
  cout << totalAns << endl;
  return 0;
}
