#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> songs(n);
  vector<int> len(n);
  for (int idx = 0; idx < n; idx++) {
    int a, b;
    cin >> a >> b;
    songs[idx].first = b;
    songs[idx].second = a;
    len[idx] = a;
  }
  sort(songs.begin(), songs.end());
  long long curSum = 0;
  long long maxPleasure = LLONG_MIN;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int idx = n - 1; idx >= 0; idx--) {
    if (q.size() < k) {
      curSum += songs[idx].second;
      q.push(songs[idx].second);
      maxPleasure = max(curSum * songs[idx].first, maxPleasure);
    } else if (q.size() >= k) {
      maxPleasure =
          max((curSum + songs[idx].second - q.top()) * songs[idx].first,
              maxPleasure);
      if (songs[idx].second > q.top()) {
        curSum -= q.top();
        q.pop();
        q.push(songs[idx].second);
        curSum += songs[idx].second;
      }
    }
  }
  cout << maxPleasure << endl;
}
