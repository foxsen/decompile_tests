#include <bits/stdc++.h>
using namespace std;
void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  FastIO();
  long long int m;
  cin >> m;
  long long int h[2], a[2], x[2], y[2];
  for (int i = 0; i < (int)2; i++) {
    cin >> h[i] >> a[i] >> x[i] >> y[i];
  }
  long long int steps1 = 0;
  for (int i = (int)1; i <= (int)m; i++) {
    h[0] = (x[0] * h[0] + y[0]) % m;
    if (h[0] == a[0]) {
      steps1 = i;
      break;
    }
  }
  if (!steps1) {
    cout << "-1" << '\n';
    return 0;
  }
  long long int steps2 = 0;
  for (int i = (int)1; i <= (int)m; i++) {
    h[0] = (x[0] * h[0] + y[0]) % m;
    if (h[0] == a[0]) {
      steps2 = i;
      break;
    }
  }
  long long int steps3 = 0;
  for (int i = (int)1; i <= (int)m; i++) {
    h[1] = (x[1] * h[1] + y[1]) % m;
    if (h[1] == a[1]) {
      steps3 = i;
      break;
    }
  }
  if (!steps3) {
    cout << "-1" << '\n';
    return 0;
  }
  long long int steps4 = 0;
  for (int i = (int)1; i <= (int)m; i++) {
    h[1] = (x[1] * h[1] + y[1]) % m;
    if (h[1] == a[1]) {
      steps4 = i;
      break;
    }
  }
  long long int ans = 1e18;
  if (steps2 && steps4) {
    for (int i = 0; i < (int)1e7; i++) {
      if ((steps1 + i * steps2 - steps3) % steps4 == 0 &&
          (steps1 + i * steps2 - steps3) >= 0) {
        ans = min(ans, steps1 + i * steps2);
        break;
      }
    }
  } else if (steps2) {
    for (int i = 0; i < (int)1e7; i++) {
      if ((steps1 + i * steps2 == steps3)) {
        ans = min(ans, steps1 + i * steps2);
        break;
      }
    }
  } else if (steps4) {
    for (int i = 0; i < (int)1e7; i++) {
      if ((steps3 + i * steps4 == steps1)) {
        ans = min(ans, steps3 + i * steps4);
        break;
      }
    }
  } else {
    ans = min(ans, steps1 * (steps1 == steps3));
  }
  if (ans == 1e18) ans = -1;
  cout << ans << '\n';
  return 0;
}
