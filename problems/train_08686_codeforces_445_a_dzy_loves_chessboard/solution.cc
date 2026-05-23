#include <bits/stdc++.h>
typedef struct {
  long int x;
  long int y;
} Struct;
using namespace std;
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  long int n, m, i, j;
  cin >> n >> m;
  Struct s;
  vector<Struct> V;
  char A[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> A[i][j];
      if (A[i][j] == '.') {
        s.x = i;
        s.y = j;
        V.push_back(s);
      }
    }
  }
  for (i = 0; i < V.size(); i++) {
    if ((V[i].x + V[i].y) % 2 == 0)
      A[V[i].x][V[i].y] = 'B';
    else
      A[V[i].x][V[i].y] = 'W';
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) cout << A[i][j];
    cout << endl;
  }
  return 0;
}
