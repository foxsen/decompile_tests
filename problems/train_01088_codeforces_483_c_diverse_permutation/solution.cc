#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const int N = 100100;
int n, k;
bool used[N];
int main() {
  cin >> n >> k;
  int last = 1 + k;
  for (int i = 1; i < k; i++) {
    if (used[i]) continue;
    printf("%d ", i);
    used[i] = true;
    if (used[last - i + 1]) continue;
    printf("%d ", last - i + 1);
    used[last - i + 1] = true;
  }
  for (int i = 1; i <= n; i++)
    if (!used[i]) printf("%d ", i);
}
