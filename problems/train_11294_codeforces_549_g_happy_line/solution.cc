#include <bits/stdc++.h>
using namespace std;
using namespace std;
vector<pair<int, int> > a;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    pair<int, int> b;
    cin >> b.first;
    b.first += i;
    b.second = i;
    a.push_back(b);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < (n); ++i) {
    a[i].first -= i;
  }
  for (int i = 0; i < (n - 1); ++i) {
    if (a[i].first > a[i + 1].first) {
      cout << ":(";
      return 0;
    }
  }
  for (int i = 0; i < (n); ++i) {
    cout << a[i].first << " ";
  }
}
