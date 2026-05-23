#include <bits/stdc++.h>
using namespace std;
int N, K, cntEdge[2010];
long long sumEdge[2010];
int main() {
  scanf("%d%d", &N, &K);
  int i, j;
  for (i = 1; i <= N; i++) sumEdge[i] = cntEdge[i] = 0;
  for (i = 1; i <= N; i++)
    for (j = i + 1; j <= N; j++) {
      int u;
      scanf("%d", &u);
      if (u != -1) {
        sumEdge[i] += u;
        sumEdge[j] += u;
        cntEdge[i]++;
        cntEdge[j]++;
      }
    }
  if (K != 2) {
    long long sumSumEdge = 0;
    for (i = 1; i <= N; i++) sumSumEdge += sumEdge[i];
    cout << sumSumEdge / N << endl;
  } else {
    long long sumWeightedSumEdge = 0;
    for (i = 1; i <= N; i++)
      sumWeightedSumEdge += sumEdge[i] * (cntEdge[i] - 1);
    cout << sumWeightedSumEdge / (N * (N - 1) / 2) << endl;
  }
}
