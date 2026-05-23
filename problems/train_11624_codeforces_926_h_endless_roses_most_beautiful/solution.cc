#include <bits/stdc++.h>
using namespace std;
class Global {
 public:
  int n, i, k, ot = -1;
  vector<int> v, w, r, o;
  char ch;
  void pref(vector<int>& v) {
    int x;
    for (i = x = 0; i < v.size(); ++i) {
      x += v[i];
      v[i] = x;
    }
  }
  void start() {
    cin >> n >> k;
    v.resize(n);
    for (i = 0; i < n; ++i) {
      cin >> v[i];
    }
    for (i = 0; i < n; ++i) {
      cin >> ch;
      if (ch == 'O') o.push_back(v[i]);
      if (ch == 'W') w.push_back(v[i]);
      if (ch == 'R') r.push_back(v[i]);
    }
    sort(o.begin(), o.end(), greater<int>());
    sort(w.begin(), w.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());
    pref(o);
    pref(w);
    pref(r);
    if (r.size() + o.size() >= k) {
      if (o.size() > 0 && r.size() > 0)
        for (i = o.size(); i + r.size() >= k; --i) {
          if (i == 0) {
            break;
          } else {
            if (i < k) ot = max(ot, o[i - 1] + r[k - i - 1]);
          }
        }
    }
    if (w.size() + o.size() >= k) {
      if (o.size() > 0 && w.size() > 0)
        for (i = o.size(); i + w.size() >= k; --i) {
          if (i == 0) {
            break;
          } else {
            if (i < k) ot = max(ot, o[i - 1] + w[k - i - 1]);
          }
        }
    }
    cout << ot;
  }
};
int main() {
  int amount = 1;
  vector<Global> v(1);
  for (int i = 1; i <= amount; ++i) {
    v.clear();
    v.resize(1);
    v[0].start();
  }
}
