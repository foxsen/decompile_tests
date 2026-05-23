#include <bits/stdc++.h>
using namespace std;
set<int> a;
map<int, int> b;
set<int>::iterator k1, k2;
int n, x, k = 0;
int main() {
  scanf("%d", &n);
  scanf("%d", &x);
  a.insert(x);
  b[x] = 1;
  for (int i = 1; i < n; ++i) {
    scanf("%d", &x);
    k1 = a.lower_bound(x);
    if (k1 == a.end())
      k1--, printf("%d ", *k1);
    else if (k1 == a.begin()) {
      printf("%d ", *k1);
    } else {
      k2 = k1;
      k1--;
      if (b[*k2] < b[*k1])
        printf("%d ", *k1);
      else
        printf("%d ", *k2);
    }
    a.insert(x);
    b[x] = i + 1;
  }
  return 0;
}
