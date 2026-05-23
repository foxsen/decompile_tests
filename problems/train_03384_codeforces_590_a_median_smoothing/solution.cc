#include <bits/stdc++.h>
using namespace std;
int v[2000000];
int acc[2000000];
int n;
int solve(int a, int b) {
  if (v[a] == v[b]) {
    for (int i = a; i < b + 1; i++) v[i] = v[a];
    return (b - a) / 2;
  }
  int sz = (b - a + 1);
  for (int i = a; i < a + sz / 2; i++) v[i] = v[a];
  for (int i = a + sz / 2; i < b + 1; i++) v[i] = v[b];
  return sz / 2 - 1;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  acc[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] == v[i + 1])
      acc[i] = 1 + acc[i + 1];
    else
      acc[i] = 1;
  }
  int i = 0;
  int ret = 0;
  while (i < n) {
    int j = i;
    if (acc[i] > 1) {
      i += acc[i];
      continue;
    }
    while (acc[j] == 1) j++;
    j--;
    ret = max(ret, solve(max(0, i - 1), min(n - 1, j + 1)));
    i = j + 1;
  }
  cout << ret << endl;
  for (int i = 0; i < n; i++) printf("%d ", v[i]);
  printf("\n");
  return 0;
}
