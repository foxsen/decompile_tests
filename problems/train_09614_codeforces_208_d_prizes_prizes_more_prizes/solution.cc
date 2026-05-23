#include <bits/stdc++.h>
using namespace std;
long long a[55], b[55], visited[55];
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < 5; i++) cin >> b[i];
  long long choco = 0;
  for (int i = 0; i < n; i++) {
    choco += a[i];
    for (int j = 4; j >= 0; j--) {
      long long temp = choco / b[j];
      visited[j] += temp;
      choco -= 1ll * temp * b[j];
    }
  }
  for (int i = 0; i < 5; i++) cout << visited[i] << " ";
  cout << endl;
  cout << choco << endl;
  return 0;
}
