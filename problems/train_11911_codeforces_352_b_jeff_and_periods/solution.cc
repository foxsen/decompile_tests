#include <bits/stdc++.h>
using namespace std;
int n;
int a[1 << 17];
vector<int> place[1 << 17];
vector<pair<int, int> > answer;
void read(void) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    place[a[i]].push_back(i);
  }
}
void solve(void) {
  for (int i = 1; i <= 100000; i++) {
    if (place[i].size() == 0) {
      continue;
    }
    if (place[i].size() == 1) {
      int ans1 = i;
      int ans2 = 0;
      answer.push_back(make_pair(ans1, ans2));
    } else {
      bool bad = false;
      int diff = place[i][1] - place[i][0];
      for (int j = 2; j < (int)(place[i].size()); j++) {
        int now_diff = place[i][j] - place[i][j - 1];
        if (now_diff != diff) {
          bad = true;
          break;
        }
      }
      if (!bad) {
        answer.push_back(make_pair(i, diff));
      }
    }
  }
}
void print(void) {
  cout << (int)(answer.size()) << endl;
  for (int i = 0; i < (int)(answer.size()); i++) {
    cout << answer[i].first << " " << answer[i].second << endl;
  }
}
int main() {
  read();
  solve();
  print();
  return 0;
}
