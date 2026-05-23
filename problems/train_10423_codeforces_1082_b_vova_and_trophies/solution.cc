#include <bits/stdc++.h>
using namespace std;
int n, ans;
vector<int> cub;
vector<int> seg;
vector<pair<int, int> > b;
void in() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  string s;
  cin >> s;
  for (auto c : s) {
    cub.push_back(c == 'G');
  }
}
void solution() {
  int st = -1, fn = -1;
  int ind = 0;
  for (; ind < n; ++ind) {
    if (!cub[ind]) {
      if (st != -1) {
        seg.push_back(fn - st + 1);
        b.push_back({st, fn});
      }
      st = fn = -1;
    } else {
      if (st == -1) {
        st = fn = ind;
      } else {
        ++fn;
      }
    }
  }
  if (st != -1) {
    seg.push_back(fn - st + 1);
    b.push_back({st, fn});
  }
  if (seg.size() == 0) {
    return;
  }
  if (seg.size() == 1) {
    ans = seg[0];
    return;
  }
  if (seg.size() == 2) {
    if (b[1].first == b[0].second + 2) {
      ans = seg[0] + seg[1];
    } else {
      ans = max(seg[0], seg[1]) + 1;
    }
  }
  if (seg.size() > 2) {
    for (int i = 0; i < seg.size() - 1; ++i) {
      if (b[i + 1].first == b[i].second + 2) {
        ans = max(ans, seg[i] + seg[i + 1] + 1);
      } else {
        ans = max(ans, seg[i] + 1);
        ans = max(ans, seg[i + 1] + 1);
      }
    }
  }
}
void out() { cout << ans << "\n"; }
int main() {
  in();
  solution();
  out();
  return 0;
}
