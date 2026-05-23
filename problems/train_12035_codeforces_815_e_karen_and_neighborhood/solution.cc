#include <bits/stdc++.h>
using namespace std;
map<long long, long long> onLeft, onRight;
pair<long long, long long> onMiddle;
bool possible(long long n, long long k, long long limit) {
  onLeft.clear();
  onRight.clear();
  onLeft[0LL] = onRight[0LL] = 0LL;
  onMiddle = make_pair(2LL, n - 1LL);
  long long maxInterval, leftLen, middleLen, rightLen, center;
  pair<long long, long long> now;
  while (k) {
    leftLen = onLeft.rbegin()->first;
    middleLen = onMiddle.second - onMiddle.first + 1LL;
    rightLen = onRight.rbegin()->first;
    maxInterval = max(leftLen, max(middleLen, rightLen));
    if (((leftLen + 1LL) >> 1LL) == ((maxInterval + 1LL) >> 1LL)) {
      now = make_pair(onLeft.rbegin()->first, onLeft.rbegin()->second);
      if (k <= now.second) return 1;
      k -= now.second;
      onLeft[(now.first - 1LL) >> 1LL] += now.second;
      onLeft[now.first >> 1LL] += now.second;
      onLeft.erase(now.first);
    } else if (((middleLen + 1LL) >> 1LL) == ((maxInterval + 1LL) >> 1LL)) {
      center = (onMiddle.first + onMiddle.second) >> 1LL;
      if (k == 1) return center <= limit;
      now = onMiddle;
      onMiddle = make_pair(0LL, -132LL);
      k--;
      if (center - 1LL <= limit)
        onLeft[center - now.first]++;
      else
        onMiddle = make_pair(now.first, center - 1);
      if (center >= limit)
        onRight[now.second - center]++;
      else
        onMiddle = make_pair(center + 1LL, now.second);
    } else {
      now = make_pair(onRight.rbegin()->first, onRight.rbegin()->second);
      if (k <= now.second) return 0;
      k -= now.second;
      onRight[(now.first - 1LL) >> 1LL] += now.second;
      onRight[now.first >> 1LL] += now.second;
      onRight.erase(now.first);
    }
  }
  return 0;
}
long long solve(long long n, long long k) {
  long long left = 2LL, right = n - 1LL, middle;
  while (left + 1 < right) {
    middle = (left + right) >> 1LL;
    if (possible(n, k, middle))
      right = middle;
    else
      left = middle;
  }
  return right - (possible(n, k, right - 1LL) ? 1LL : 0LL);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  cout << (k == 1LL ? 1LL : (k == 2LL ? n : solve(n, k - 2LL))) << '\n';
  return 0;
}
