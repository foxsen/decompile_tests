#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<string> vv(N);
  for (int i = 0; i < N; i++) cin >> vv[i];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (vv[i][j] == '#') {
        for (int k = 0; k < N; k++) {
          if (vv[k][j] == '#' && vv[k] != vv[i]) {
            cout << "No";
            return 0;
          }
        }
      }
    }
  }
  cout << "Yes";
}
