#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
int main() {
  int q = 1;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> qu(n, -1), ki(n, -1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < x; j++) {
        int m;
        cin >> m;
        if (ki[m - 1] == -1 && qu[i] == -1) {
          qu[i] = m;
          ki[m - 1] = i;
        }
      }
    }
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
      if (qu[i] == -1) {
        int j = 0;
        while (ki[j] != -1) {
          j++;
        }
        v.push_back({i + 1, j + 1});
      }
    }
    if (v.size()) {
      cout << "IMPROVE" << endl;
      cout << v[0].first << " " << v[0].second << endl;
    } else
      cout << "OPTIMAL" << endl;
  }
}
