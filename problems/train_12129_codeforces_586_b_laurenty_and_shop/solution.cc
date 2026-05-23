#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 50 + 10;
int a1[MAX_N], a2[MAX_N], b[MAX_N];
int dp1[MAX_N], dp2[MAX_N], sum[MAX_N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) cin >> a1[i];
  for (int i = 0; i < n - 1; i++) cin >> a2[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      dp1[i] += a1[j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n - 1; j++) {
      dp2[i] += a2[j];
    }
  }
  int ans = 0;
  int mini = INT_MAX, minI = -1;
  for (int i = 0; i < n; i++) {
    sum[i] = b[i] + dp1[i] + dp2[i];
    if (sum[i] < mini) {
      mini = sum[i];
      minI = i;
    }
  }
  ans += sum[minI];
  sum[minI] = INT_MAX;
  mini = INT_MAX, minI = -1;
  for (int i = 0; i < n; i++) {
    if (sum[i] < mini) {
      mini = sum[i];
      minI = i;
    }
  }
  ans += sum[minI];
  cout << ans << endl;
  return 0;
}
