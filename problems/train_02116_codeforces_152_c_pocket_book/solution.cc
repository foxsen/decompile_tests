#include <bits/stdc++.h>
int prime[1000000 + 5], in;
bool isp[1000000 + 5];
using namespace std;
int d4[] = {-1, 0, 1, 0};
int y4[] = {0, -1, 0, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dy[] = {1, -1, 1, -1, 0, 0, -1, 1};
int dxh[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dyh[] = {2, 2, -2, -2, 1, -1, 1, -1};
int mat[1005][1005], val[1005][1005];
void reset() {
  for (int i = 0; i < 1005; i++) {
    memset(mat[i], 0, sizeof(mat[i]));
    memset(val[i], 0, sizeof(val[i]));
  }
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<string> v;
    for (int i = 0; i < n; i++) {
      string sr;
      cin >> sr;
      v.push_back(sr);
    }
    long long ans = 1;
    for (int i = 0; i < m; i++) {
      set<char> s;
      for (int j = 0; j < n; j++) {
        s.insert(v[j][i]);
      }
      ans *= s.size();
      ans %= 1000000007;
    }
    cout << ans << endl;
  }
  return 0;
}
