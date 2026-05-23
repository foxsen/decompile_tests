#include <bits/stdc++.h>
using namespace std;
int ans = 1;
vector<int> son[200010];
int start[200010];
int eend[200010];
int place[200010];
void dfs(int num) {
  place[ans] = num;
  start[num] = ans++;
  for (int i = 0; i < son[num].size(); i++) {
    dfs(son[num][i]);
  }
  eend[num] = ans;
}
int main() {
  int num_soldier, num_operation;
  int i;
  int temp;
  int start_place, num_place;
  while (scanf("%d %d", &num_soldier, &num_operation) != EOF) {
    for (i = 2; i <= num_soldier; i++) {
      scanf("%d", &temp);
      son[temp].push_back(i);
    }
    dfs(1);
    while (num_operation--) {
      scanf("%d %d", &start_place, &num_place);
      if (num_place <= eend[start_place] - start[start_place]) {
        printf("%d\n", place[start[start_place] + num_place - 1]);
      } else {
        printf("-1\n");
      }
    }
  }
}
