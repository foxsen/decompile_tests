#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long int ar[N], br[N], l[N], r[N];
int parent[1000];
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> v;
    n = n - 2;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      v.push_back(s);
    }
    if (n == 1) {
      cout << "a" << v[0] << endl;
      continue;
    }
    cout << v[0][0];
    int flag = 0;
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i][1] == v[i + 1][0])
        cout << v[i + 1][0];
      else {
        flag = 1;
        cout << v[i][1];
        cout << v[i + 1][0];
      }
    }
    cout << v[n - 1][1];
    if (flag == 0) cout << "a";
    cout << endl;
  }
  return 0;
}
