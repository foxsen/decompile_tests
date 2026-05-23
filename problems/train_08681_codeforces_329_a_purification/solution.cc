#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 210;
int N;
char room[MAXN][MAXN];
vector<pair<int, int> > cells;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%s", room[i]);
  bool done = true;
  cells.clear();
  for (int i = 0; done && i < N; i++) {
    bool good = false;
    for (int j = 0; !good && j < N; j++)
      if (room[i][j] == '.') {
        good = true;
        cells.push_back(make_pair(i + 1, j + 1));
      }
    if (!good) done = false;
  }
  if (done) {
    for (int i = 0; i < N; i++)
      printf("%d %d\n", cells[i].first, cells[i].second);
    return 0;
  }
  done = true;
  cells.clear();
  for (int i = 0; done && i < N; i++) {
    bool good = false;
    for (int j = 0; !good && j < N; j++)
      if (room[j][i] == '.') {
        good = true;
        cells.push_back(make_pair(j + 1, i + 1));
      }
    if (!good) done = false;
  }
  if (done) {
    for (int i = 0; i < N; i++)
      printf("%d %d\n", cells[i].first, cells[i].second);
    return 0;
  }
  printf("-1\n");
  return 0;
}
