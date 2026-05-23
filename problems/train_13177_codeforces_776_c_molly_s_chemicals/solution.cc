#include <bits/stdc++.h>
using namespace std;
long long a = 1;
long long n, k, ans;
long long v[100010];
vector<long long> V;
map<long long, int> M;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> v[i], v[i] += v[i - 1];
  V.push_back(1);
  if (k != 1 && k != -1)
    while (a < 1e15) a *= k, V.push_back(a);
  if (k == -1) V.push_back(-1);
  M[0]++;
  for (int i = 1; i <= n; i++) {
    for (int h = 0; h < V.size(); h++) ans += M[-1 * (V[h] - v[i])];
    M[v[i]]++;
  }
  cout << ans;
}
