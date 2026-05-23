#include <bits/stdc++.h>
using namespace std;
int i, k, m, n = 1, b, mas[100000], s[5005];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> b;
    s[b]++;
    m = max(m, b);
  }
  for (i = 1; i <= m; i++)
    if (s[i]) {
      mas[k++] = i;
      s[i]--;
    }
  for (i = m - 1; i >= 0; i--)
    if (s[i]) {
      mas[k++] = i;
      s[i]--;
    }
  cout << k << endl;
  for (i = 0; i < k; i++) cout << mas[i] << " ";
  return 0;
}
