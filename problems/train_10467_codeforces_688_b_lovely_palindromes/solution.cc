#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
int n;
char str[N];
void dfs(int Now, int n) {
  if (Now >= n) return;
  printf("%c", str[Now]);
  dfs(Now + 1, n);
  printf("%c", str[Now]);
}
int main() {
  int ii;
  scanf("%s", str);
  dfs(0, strlen(str));
  return 0;
}
