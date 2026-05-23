#include <bits/stdc++.h>
using namespace std;
int a[200005], ans[200005];
queue<int> q;
const int sb = 1e5;
int main() {
  int n;
  cin >> n;
  q.push(-1000000);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 0) q.push(i);
  }
  q.push(1000000);
  int x = q.front();
  q.pop();
  int y = q.front();
  for (int i = 1; i <= n; i++) {
    if (i <= y) {
      ans[i] = min(i - x, y - i);
    } else {
      x = y;
      q.pop();
      y = q.front();
      ans[i] = min(i - x, y - i);
    }
    cout << ans[i] << " ";
  }
}
