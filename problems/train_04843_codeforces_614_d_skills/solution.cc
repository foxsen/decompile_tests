#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 9;
vector<pair<int, int>> v;
vector<long long> com(N), tem(N);
long long n, A, cf, cm;
long long maxMin(long long curM, int end) {
  if (end == 0) return A;
  long long lo = tem[0], hi = A - 1, mid;
  while (lo < hi) {
    mid = lo + (hi - lo + 1) / 2;
    int indxOfLast =
        upper_bound(tem.begin(), tem.begin() + end, mid) - tem.begin();
    if (indxOfLast * mid - com[indxOfLast - 1] <= curM) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}
int main() {
  long long m;
  scanf("%lld%lld%lld%lld%lld", &n, &A, &cf, &cm, &m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tem[i] = x;
    v.push_back({x, i});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    com[i] = tem[i] = v[i].first;
    if (i) com[i] += com[i - 1];
  }
  int start = n;
  while (tem[start - 1] == A && start - 1 >= 0) start--;
  if (start == -1) {
    cout << n * cf + A * cm << endl;
    for (int i = 0; i < n; i++) cout << A << ' ';
    return 0;
  }
  long long curM = m;
  int mxIndx = start;
  long long maxMinVal = maxMin(m, start);
  long long mxAns = (n - start) * cf + maxMinVal * cm;
  for (int i = n - 1; i >= 0; i--) {
    curM -= (A - tem[i]);
    if (curM < 0) break;
    long long curMin = maxMin(curM, i);
    long long curAns = curMin * cm + (n - i) * cf;
    if (curAns > mxAns) {
      mxAns = curAns;
      mxIndx = i;
      maxMinVal = curMin;
    }
  }
  long long ans[n];
  for (int i = 0; i < n; i++) {
    if (i >= mxIndx) {
      ans[v[i].second] = A;
    } else {
      if (v[i].first < maxMinVal) {
        ans[v[i].second] = maxMinVal;
      } else {
        ans[v[i].second] = v[i].first;
      }
    }
  }
  cout << mxAns << endl;
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
