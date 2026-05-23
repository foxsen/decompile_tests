#include <bits/stdc++.h>
using namespace std;
const int N = 1000, C = 8;
int arr[N], n, mid;
int dp[N][1 << C];
bool visit[N][1 << C];
int solve(int startIdx, int canNotPickMask) {
  if (canNotPickMask == (1 << C) - 1) return 0;
  if (startIdx >= n) return -N;
  int &ans = dp[startIdx][canNotPickMask];
  if (visit[startIdx][canNotPickMask]) return ans;
  visit[startIdx][canNotPickMask] = true;
  ans = solve(startIdx + 1, canNotPickMask);
  if (((canNotPickMask >> arr[startIdx]) & 1) == 0) {
    int nextIndex = startIdx, remainNum = mid;
    while (remainNum > 0 && nextIndex < n) {
      if (arr[nextIndex] == arr[startIdx]) remainNum--;
      nextIndex++;
    }
    if (remainNum == 0) {
      ans = max(ans,
                mid + solve(nextIndex, canNotPickMask | (1 << arr[startIdx])));
      remainNum = 1;
      while (remainNum > 0 && nextIndex < n) {
        if (arr[nextIndex] == arr[startIdx]) remainNum--;
        nextIndex++;
      }
      if (remainNum == 0)
        ans = max(
            ans,
            mid + 1 + solve(nextIndex, canNotPickMask | (1 << arr[startIdx])));
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;
    s.insert(arr[i]);
  }
  int low = 1, high = n / C, ans = s.size(), temp;
  while (low <= high) {
    mid = (low + high) / 2;
    memset(visit, false, sizeof visit);
    temp = solve(0, 0);
    if (temp <= 0)
      high = mid - 1;
    else {
      ans = max(ans, temp);
      low = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
