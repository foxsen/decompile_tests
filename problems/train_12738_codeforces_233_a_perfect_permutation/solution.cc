#include <bits/stdc++.h>
using namespace std;
int p[111], n;
int main() {
  cin >> n;
  if (n == 1 || n % 2 == 1) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 2; i <= n; i++) swap(p[i - 1], p[i]), i++;
  for (int i = 1; i <= n; i++) cout << p[i] << " ";
  cin.get(), cin.get();
  return 0;
}
