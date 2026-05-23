#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-10;
int main() {
  int n, s;
  cin >> n >> s;
  priority_queue<pair<int, int> > que;
  queue<pair<int, int> > que2;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    que.push(pair<int, int>(num, i + 1));
  }
  if (s % 2) {
    cout << "No" << endl;
  } else {
    vector<pair<int, int> > res;
    while (!que.empty()) {
      pair<int, int> p = que.top();
      que.pop();
      int rest = p.first;
      int id = p.second;
      while (rest && !que.empty()) {
        pair<int, int> p2 = que.top();
        que.pop();
        if (p2.first > 0) {
          p2.first--;
          rest--;
          res.push_back(pair<int, int>(id, p2.second));
          if (p2.first > 0) que2.push(p2);
        }
      }
      if (rest) break;
      while (!que2.empty()) {
        que.push(que2.front());
        que2.pop();
      }
    }
    if ((int)res.size() == s / 2) {
      cout << "Yes" << endl;
      cout << s / 2 << endl;
      for (int i = 0; i < s / 2; i++)
        cout << res[i].first << " " << res[i].second << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
