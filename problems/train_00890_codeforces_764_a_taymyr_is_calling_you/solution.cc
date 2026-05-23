#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, z, c = 0;
  ;
  vector<int> v;
  cin >> n >> m >> z;
  for (int i = 1; (i * n) <= z; i++) v.push_back(i * n);
  for (int i = 1; (i * m) <= z; i++) {
    if (binary_search(v.begin(), v.end(), i * m)) c++;
  }
  cout << c << endl;
  return 0;
}
