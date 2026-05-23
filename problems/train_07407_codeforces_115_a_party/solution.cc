#include <bits/stdc++.h>
using namespace std;
int p[2001];
int findrand(int i) {
  int j = 1;
  while (p[i] != i) {
    i = p[i];
    j++;
  }
  return j;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    int a;
    cin >> a;
    if (a == -1)
      p[i] = i;
    else
      p[i] = a;
  }
  int max = 0;
  for (int i = 1; i <= n; i++) {
    int b = findrand(i);
    if (b > max) max = b;
  }
  cout << max << endl;
  return 0;
}
