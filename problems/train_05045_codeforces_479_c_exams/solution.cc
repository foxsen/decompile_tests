#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  ;
  vector<pair<long long, long long> > arr(n);
  for (long long i = 0; i < (long long)n; i++) {
    long long e1, e2;
    cin >> e1 >> e2;
    arr[i] = {e1, e2};
  }
  sort(arr.begin(), arr.end());
  long long last = 0, i = 0;
  while (i < n) {
    if (arr[i].second >= last)
      last = arr[i].second;
    else
      last = arr[i].first;
    i++;
  }
  cout << last;
  cout << '\n';
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
  return 0;
}
