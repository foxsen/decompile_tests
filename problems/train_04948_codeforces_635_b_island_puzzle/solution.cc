#include <bits/stdc++.h>
using namespace std;
map<int, int> a;
int b[200005];
int main() {
  int n, x;
  scanf("%d", &n);
  int j = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x > 0) a[x] = j++;
  }
  int flag = 1, temp, k = 0;
  scanf("%d", &x);
  temp = (a[x] + 1) % j;
  for (int i = 1; i < n; i++) {
    scanf("%d", &x);
    if (x > 0) {
      if (temp != a[x]) flag = 0;
      temp = (a[x] + 1) % j;
      b[k++] = x;
    }
  }
  if (!flag) {
    for (int i = 0; i < k; i++) {
      if (a[b[i]] != i)
        break;
      else if (i == k - 1 && a[b[i]] == i)
        flag = 1;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
