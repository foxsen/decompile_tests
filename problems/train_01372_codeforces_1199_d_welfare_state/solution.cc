#include <bits/stdc++.h>
using namespace std;
int arr[200005];
int proc[200005];
set<int> payoff;
pair<int, pair<int, int> > queries[200005];
int main() {
  memset(proc, -1, sizeof(proc));
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int type, p, x;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d %d", &p, &x);
      pair<int, pair<int, int> > pp = make_pair(1, make_pair(p, x));
      queries[i] = pp;
    } else {
      scanf("%d", &x);
      pair<int, pair<int, int> > pp = make_pair(2, make_pair(x, 0));
      queries[i] = pp;
    }
  }
  for (int i = q; i >= 1; --i) {
    pair<int, pair<int, int> > pp = queries[i];
    int typ = pp.first;
    if (typ == 2) {
      payoff.insert(-(pp.second.first));
    } else {
      int p = pp.second.first;
      int x = pp.second.second;
      if (proc[p] != -1) {
        continue;
      } else {
        proc[p] = x;
        int xxx = *(payoff.begin());
        xxx = xxx * (-1);
        if (proc[p] < xxx) proc[p] = xxx;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (proc[i] == -1) {
      proc[i] = arr[i];
      int xxx = *(payoff.begin());
      xxx = xxx * (-1);
      if (proc[i] < xxx) proc[i] = xxx;
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", proc[i]);
  }
  printf("\n");
  return 0;
}
