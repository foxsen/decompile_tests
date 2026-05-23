#include <bits/stdc++.h>
using namespace std;
long long int a[200001], inds1[200001], inds2[200001];
int main() {
  long long int n, i, p, max1 = -1;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  inds1[n - 1] = n - 1;
  inds2[0] = 0;
  for (i = n - 2; i >= 0; i--) {
    if (a[i] <= a[inds1[i + 1]])
      inds1[i] = i;
    else
      inds1[i] = inds1[i + 1];
  }
  for (i = 1; i < n; i++) {
    if (a[i] < a[inds2[i - 1]])
      inds2[i] = i;
    else
      inds2[i] = inds2[i - 1];
  }
  max1 = a[inds1[0]] * n + inds1[0];
  if (a[inds1[0]] == a[n - 1])
    max1 = max(max1, a[inds1[0]] * n);
  else
    max1 = max(max1, a[inds1[0]] * n + inds1[0] + 1);
  for (i = 1; i < n - 1; i++) {
    if (a[i] == a[inds1[0]]) continue;
    if (a[inds2[i - 1]] < a[inds1[i + 1]])
      max1 = max(max1, a[inds2[i]] * n + n - (i - inds2[i]));
    else {
      max1 = max(max1, a[inds1[i + 1]] * n + (inds1[i + 1] - i));
    }
  }
  cout << max1;
  cout << endl;
  return 0;
}
