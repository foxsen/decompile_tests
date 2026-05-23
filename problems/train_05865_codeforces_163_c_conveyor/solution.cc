#include <bits/stdc++.h>
using namespace std;
int ar[100010];
vector<pair<long double, int> > v;
long double ans[100010];
int main(int argc, char** argv) {
  long long n, l, vk, va;
  cin >> n >> l >> vk >> va;
  for (int i = 0; i < n; ++i) cin >> ar[i];
  long double x = va * l / ((long double)(va + vk));
  long double t;
  for (int i = 0; i < n; ++i) {
    v.push_back(make_pair((long double)ar[i], -1));
    t = (long double)ar[i] - x + 0.00000000000001L;
    if (t < 0) t += 2 * l;
    v.push_back(make_pair(t, 1));
  }
  sort(v.begin(), v.end());
  int s = 0;
  for (int p = 0;
       p < v.size() && v[p].first - v[0].first < x - 2 * 0.00000000000001L;
       ++p) {
    if (v[p].second == -1) ++s;
  }
  ans[s] += v[0].first;
  s += v[0].second;
  for (int i = 1; i < (int)v.size(); ++i) {
    ans[s] += v[i].first - v[i - 1].first;
    s += v[i].second;
  }
  ans[s] += ((long double)2 * l) - v[v.size() - 1].first;
  for (int i = 0; i < n + 1; ++i)
    printf("%.13f\n", (double)(ans[i] / ((long double)2 * l)));
  return 0;
}
