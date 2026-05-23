#include <bits/stdc++.h>
using namespace std;
int T, N;
int C[200001], F[200001];
vector<int> vt[200001];
int main(void) {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
      int x, f;
      scanf("%d %d", &x, &f);
      C[x]++;
      if (f) F[x]++;
    }
    for (int i = 1; i <= N; i++)
      if (C[i]) vt[C[i]].push_back(F[i]), C[i] = F[i] = 0;
    priority_queue<int, vector<int>, less<int>> PQ;
    int res1 = 0, res2 = 0;
    for (int i = N; i >= 1; i--) {
      for (auto x : vt[i]) PQ.push(x);
      if (!PQ.empty()) {
        res1 += i;
        res2 += min(PQ.top(), i);
        PQ.pop();
      }
    }
    printf("%d %d\n", res1, res2);
    for (int i = 1; i <= N; i++) vt[i].clear();
  }
  return 0;
}
