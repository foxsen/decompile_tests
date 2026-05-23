#include <bits/stdc++.h>
using namespace std;
const int Maxn = 10e5 + 100;
int n, a[Maxn];
vector<int> baz;
vector<pair<int, int> > prnt;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n + 1; i++) {
    if (a[i] > a[i - 1]) {
      for (int j = 0; j < a[i] - a[i - 1]; j++) {
        baz.push_back(i);
      }
    }
    if (a[i] < a[i - 1]) {
      for (int j = 0; j < a[i - 1] - a[i]; j++) {
        prnt.push_back(make_pair(baz[baz.size() - 1], i - 1));
        baz.pop_back();
      }
    }
  }
  cout << prnt.size() << endl;
  for (int i = 0; i < (int)prnt.size(); i++) {
    cout << prnt[i].first << " " << prnt[i].second << endl;
  }
}
