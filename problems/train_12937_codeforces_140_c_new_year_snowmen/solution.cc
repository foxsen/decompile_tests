#include <bits/stdc++.h>
using namespace std;
map<int, int> ID;
int V[110000], C[110000];
int e, v;
set<pair<int, int> > S;
int Res[110000][3], er;
pair<int, int> A[3];
int main() {
  set<pair<int, int> >::iterator it;
  int i, x, t, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &t);
    if (ID.count(t) == 0) ID[t] = e++;
    x = ID[t], V[x] = t, C[x]++;
  }
  for (i = 0; i < e; i++) S.insert(make_pair(C[i], V[i]));
  while (S.size() >= 3) {
    for (i = 0; i < 3; i++) it = S.end(), it--, A[i] = (*it), S.erase(it);
    for (i = 0; i < 3; i++) {
      Res[er][i] = A[i].second, A[i].first--;
      if (A[i].first) S.insert(A[i]);
    }
    er++;
  }
  printf("%d\n", er);
  for (i = 0; i < er; i++) {
    sort(Res[i], Res[i] + 3);
    printf("%d %d %d\n", Res[i][2], Res[i][1], Res[i][0]);
  }
  return 0;
}
