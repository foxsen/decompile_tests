#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int a, b;
vector<int> ansa, ansb;
void solve() {
  int cnt = 0;
  int k = 0;
  while (cnt + k + 1 <= a + b) {
    k++;
    cnt += k;
  }
  ansa.clear();
  ansb.clear();
  for (int i = k; i >= 1; i--) {
    if (i <= a) {
      a -= i;
      ansa.push_back(i);
    } else {
      ansb.push_back(i);
    }
  }
  printf("%d\n", ansa.size());
  for (size_t i = 0; i < ansa.size(); i++) {
    printf("%d ", ansa[i]);
  }
  printf("\n");
  printf("%d\n", ansb.size());
  for (size_t i = 0; i < ansb.size(); i++) {
    printf("%d ", ansb[i]);
  }
  printf("\n");
}
int main() {
  while (scanf("%d %d", &a, &b) == 2) {
    solve();
  }
}
