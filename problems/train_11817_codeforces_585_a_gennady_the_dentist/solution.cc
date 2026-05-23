#include <bits/stdc++.h>
using namespace std;
struct P {
  int v;
  int d;
  int p;
  P(const int v, const int d, const int p) : v(v), d(d), p(p) {}
};
int main() {
  int n;
  scanf("%d", &n);
  vector<P> vec;
  for (int i = 0; i < n; i++) {
    int v, d, p;
    scanf("%d%d%d", &v, &d, &p);
    vec.push_back(P(v, d, p));
  }
  vector<int> nom;
  for (int i = 0; i < n; i++) {
    int t = 0;
    int m = vec[i].p;
    if (m < 0) continue;
    nom.push_back(i);
    int k = vec[i].v;
    for (int j = i + 1; j < n; j++) {
      if (vec[j].p < 0) continue;
      vec[j].p = vec[j].p - k - t;
      if (vec[j].p < 0) t += vec[j].d;
      if (t > 1e7) t = 1e7;
      if (k) k--;
    }
  }
  n = (int)nom.size();
  printf("%d\n", n);
  for (int i = 0; i < n; i++) printf("%d ", nom[i] + 1);
}
