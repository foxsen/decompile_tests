#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
vector<int> g[N];
int color[N], n;
size_t k, l = 1;
inline int no_solution() {
  cout << "NO";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr),
      cin >> n >> k;
  for (int a, i = 0; i < n; i++) cin >> a, g[a].push_back(i);
  for (int i = 1; i < N; i++)
    if (g[i].size() <= k)
      for (auto j : g[i]) color[j] = l, l %= k, l++;
    else
      return no_solution();
  cout << "YES" << '\n' << color[0];
  for (int i = 1; i < n; i++) cout << ' ' << color[i];
}
