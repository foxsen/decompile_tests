#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
vector<long long int> a(200, 0);
int main() {
  long long int n, m, posx, posy, mx = 0, ans = 0;
  char p;
  cin >> n >> m >> p;
  char M[n][m];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> M[i][j];
    }
  }
  set<char> adj;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (M[i][j] == p) {
        if ((i - 1 >= 0 && j < m) && M[i - 1][j] != p) adj.insert(M[i - 1][j]);
        if ((i < n && j - 1 >= 0) && M[i][j - 1] != p) adj.insert(M[i][j - 1]);
        if ((i < n && j + 1 < m) && M[i][j + 1] != p) adj.insert(M[i][j + 1]);
        if ((i + 1 < n && j < m) && M[i + 1][j] != p) adj.insert(M[i + 1][j]);
      }
    }
  }
  int x = 0;
  if (adj.find('.') != adj.end()) x--;
  cout << adj.size() + x << endl;
}
