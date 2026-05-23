#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 5];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int coun = 0;
  for (int i = 1; i < n - 1; i++) {
    if (a[i] < a[i - 1] && a[i] < a[i + 1])
      coun++;
    else if (a[i] > a[i - 1] && a[i] > a[i + 1])
      coun++;
  }
  printf("%d\n", coun);
}
