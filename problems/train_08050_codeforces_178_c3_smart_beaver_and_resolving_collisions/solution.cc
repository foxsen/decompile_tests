#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 20;
const double PI = M_PI;
const double EPS = 1e-15;
const int MaxH = 200005;
int H, M, N;
int row[MaxH];
int col[MaxH];
int size[MaxH];
vector<set<int> > second;
map<int, pair<int, int> > pos;
set<int>::iterator k;
int main() {
  scanf("%d%d%d", &H, &M, &N);
  for (int i = 0; i < H; i++) row[i] = -1;
  set<int> a;
  for (int i = 0; i < H; i++)
    if (row[i] == -1) {
      a.clear();
      int __row = second.size(), __col = 0;
      for (int j = i; row[j] == -1; j = (j + M) % H, __col++) {
        row[j] = __row;
        col[j] = __col;
        a.insert(__col);
      }
      size[__row] = __col;
      second.push_back(a);
    }
  long long answer = 0;
  for (int i = 0; i < N; i++) {
    int id, spot;
    char operation;
    scanf("\n%c", &operation);
    if (operation == '+') {
      scanf("%d%d", &id, &spot);
      set<int>& a = second[row[spot]];
      k = a.lower_bound(col[spot]);
      if (k == a.end()) k = a.begin();
      if (*k >= col[spot])
        answer = answer + *k - col[spot];
      else
        answer = answer + *k - col[spot] + size[row[spot]];
      pos[id] = pair<int, int>(row[spot], *k);
      a.erase(*k);
    } else {
      scanf("%d", &id);
      pair<int, int> u = pos[id];
      second[u.first].insert(u.second);
    }
  }
  printf("%I64d\n", answer);
  return 0;
}
