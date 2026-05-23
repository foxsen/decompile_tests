#include <bits/stdc++.h>
using namespace std;
vector<int> a;
map<int, int> m;
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int val;
      scanf("%d", &val);
      m[-val]++;
    }
  for (auto it = m.begin(); it != m.end(); it++) {
    int cnt = it->second;
    if (cnt == 0) continue;
    int val = -(it->first);
    int divCnt = 0;
    for (int i = 0; i < a.size(); i++)
      if (a[i] % val == 0) divCnt++;
    int num = 1;
    while (2 * divCnt * num + num * num < cnt) num++;
    for (int i = 0; i < a.size(); i++) {
      int g = gcd(a[i], val);
      m[-g] -= 2 * num;
    }
    for (int i = 0; i < num; i++) {
      a.push_back(val);
    }
  }
  for (int val : a) printf("%d ", val);
  printf("\n");
}
