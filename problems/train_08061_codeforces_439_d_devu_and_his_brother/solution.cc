#include <bits/stdc++.h>
using namespace std;
long long a[100000], b[100000];
int main() {
  long long nolla = 0;
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  long long ala = 0, yla = 1000000000;
  while (ala <= yla) {
    long long k = (ala + yla) / 2;
    long long va = 0, vk = 0, vy = 0;
    for (int i = 0; i < n; i++) {
      va += max(nolla, k - 1 - a[i]);
      vk += max(nolla, k - a[i]);
      vy += max(nolla, k + 1 - a[i]);
    }
    for (int i = 0; i < m; i++) {
      va += max(nolla, b[i] - (k - 1));
      vk += max(nolla, b[i] - (k));
      vy += max(nolla, b[i] - (k + 1));
    }
    if (vk <= vy && vk <= va) {
      cout << vk << endl;
      return 0;
    }
    if (vk > vy) ala = k + 1;
    if (vk > va) yla = k - 1;
  }
  return 0;
}
