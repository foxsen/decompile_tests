#include <bits/stdc++.h>
using namespace std;
int N[105] = {0};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  vector<int> vec;
  cin >> n >> m;
  while (n--) {
    int le, ri;
    cin >> le >> ri;
    for (int i = le; i <= ri; i++) {
      N[i]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (N[i] == 0) {
      vec.push_back(i);
    }
  }
  cout << vec.size() << '\n';
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i);
    if (i < vec.size() - 1)
      cout << " ";
    else
      cout << '\n';
  }
  return 0;
}
