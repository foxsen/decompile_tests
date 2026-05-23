#include <bits/stdc++.h>
using namespace std;
int c[210];
int pre[210][210];
int precnt[210];
int cnt[210] = {0};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n); i++) {
    scanf("%d", c + i);
    c[i] %= 3;
  }
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (n); j++) pre[i][j] = 0;
  for (int i = 0; i < (n); i++) {
    scanf("%d", precnt + i);
    int t;
    for (int j = 0; j < (precnt[i]); j++) {
      scanf("%d", &t);
      pre[i][t - 1] = 1;
    }
  }
  int mintime = 1000100;
  for (int p = 0; p < (3); p++) {
    int pos = p, time = 0, done = 0;
    for (int i = 0; i < (n); i++) cnt[i] = 0;
    while (done < n) {
      queue<int> Q;
      for (int i = 0; i < (n); i++)
        if (precnt[i] == cnt[i] && c[i] == pos) Q.push(i);
      while (!Q.empty()) {
        int part = Q.front();
        Q.pop();
        done++;
        time++;
        cnt[part]++;
        for (int i = 0; i < (n); i++)
          if (pre[i][part] == 1) {
            cnt[i]++;
            if (cnt[i] == precnt[i] && c[i] == pos) Q.push(i);
          }
      }
      pos = (pos + 1) % 3;
      time++;
    }
    time--;
    if (time < mintime) mintime = time;
  }
  printf("%d\n", mintime);
  return 0;
}
