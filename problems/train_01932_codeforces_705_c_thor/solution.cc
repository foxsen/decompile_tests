#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, q, unread = 0, clearupto = 0, t = 1, i, j, k;
  cin >> n >> q;
  vector<vector<int> > app(n + 1);
  vector<int> time(q + 1);
  vector<int>::iterator it;
  int x, y;
  while (q--) {
    cin >> x >> y;
    if (x == 1) {
      app[y].push_back(t);
      time[t++] = y;
      unread++;
    } else if (x == 2) {
      it = app[y].begin();
      while (it != app[y].end()) {
        if (*it <= clearupto)
          ;
        else {
          time[*it] = 0;
          unread--;
        }
        it++;
      }
      app[y].clear();
    } else {
      for (j = clearupto + 1; j <= y; j++) {
        if (time[j] != 0) unread--;
      }
      if (y > clearupto) clearupto = y;
    }
    cout << unread << "\n";
  }
  return 0;
}
