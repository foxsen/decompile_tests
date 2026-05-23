#include <bits/stdc++.h>
using namespace std;
long long a[5];
char c[5];
int main() {
  for (int i = 0; i < 4; i++) cin >> a[i];
  for (int i = 0; i < 3; i++) cin >> c[i];
  long long ans = 2e18, b1, b2, b3, b4, b5, b6, d1, d2, d3, e1, e2, e3, r1, r2,
            r3, q1, q2, q3, w1, w2, w3, t1, t2, t3;
  if (c[0] == '+')
    b1 = a[0] + a[1];
  else
    b1 = a[0] * a[1];
  if (c[0] == '+')
    b2 = a[0] + a[2];
  else
    b2 = a[0] * a[2];
  if (c[0] == '+')
    b3 = a[0] + a[3];
  else
    b3 = a[0] * a[3];
  if (c[0] == '+')
    b4 = a[1] + a[2];
  else
    b4 = a[2] * a[1];
  if (c[0] == '+')
    b5 = a[3] + a[1];
  else
    b5 = a[3] * a[1];
  if (c[0] == '+')
    b6 = a[2] + a[3];
  else
    b6 = a[2] * a[3];
  if (c[1] == '+')
    d1 = b1 + a[2];
  else
    d1 = b1 * a[2];
  if (c[1] == '+')
    d2 = b1 + a[3];
  else
    d2 = b1 * a[3];
  if (c[1] == '+')
    d3 = a[3] + a[2];
  else
    d3 = a[3] * a[2];
  if (c[2] == '+')
    ans = min(ans, d1 + a[3]);
  else
    ans = min(ans, d1 * a[3]);
  if (c[2] == '+')
    ans = min(ans, d2 + a[2]);
  else
    ans = min(ans, d2 * a[2]);
  if (c[2] == '+')
    ans = min(ans, d3 + b1);
  else
    ans = min(ans, d3 * b1);
  if (c[1] == '+')
    q1 = b2 + a[1];
  else
    q1 = b2 * a[1];
  if (c[1] == '+')
    q2 = b2 + a[3];
  else
    q2 = b2 * a[3];
  if (c[1] == '+')
    q3 = a[1] + a[3];
  else
    q3 = a[1] * a[3];
  if (c[2] == '+')
    ans = min(ans, q1 + a[3]);
  else
    ans = min(ans, q1 * a[3]);
  if (c[2] == '+')
    ans = min(ans, q2 + a[1]);
  else
    ans = min(ans, q2 * a[1]);
  if (c[2] == '+')
    ans = min(ans, q3 + b2);
  else
    ans = min(ans, q3 * b2);
  if (c[1] == '+')
    w1 = b3 + a[2];
  else
    w1 = b3 * a[2];
  if (c[1] == '+')
    w2 = b3 + a[1];
  else
    w2 = b3 * a[1];
  if (c[1] == '+')
    w3 = a[1] + a[2];
  else
    w3 = a[1] * a[2];
  if (c[2] == '+')
    ans = min(ans, w1 + a[1]);
  else
    ans = min(ans, w1 * a[1]);
  if (c[2] == '+')
    ans = min(ans, w2 + a[2]);
  else
    ans = min(ans, w2 * a[2]);
  if (c[2] == '+')
    ans = min(ans, w3 + b3);
  else
    ans = min(ans, w3 * b3);
  if (c[1] == '+')
    e1 = b4 + a[0];
  else
    e1 = b4 * a[0];
  if (c[1] == '+')
    e2 = b4 + a[3];
  else
    e2 = b4 * a[3];
  if (c[1] == '+')
    e3 = a[3] + a[0];
  else
    e3 = a[3] * a[0];
  if (c[2] == '+')
    ans = min(ans, e1 + a[3]);
  else
    ans = min(ans, e1 * a[3]);
  if (c[2] == '+')
    ans = min(ans, e2 + a[0]);
  else
    ans = min(ans, e2 * a[0]);
  if (c[2] == '+')
    ans = min(ans, e3 + b4);
  else
    ans = min(ans, e3 * b4);
  if (c[1] == '+')
    r1 = b5 + a[2];
  else
    r1 = b5 * a[2];
  if (c[1] == '+')
    r2 = b5 + a[0];
  else
    r2 = b5 * a[0];
  if (c[1] == '+')
    r3 = a[0] + a[2];
  else
    r3 = a[0] * a[2];
  if (c[2] == '+')
    ans = min(ans, r1 + a[0]);
  else
    ans = min(ans, r1 * a[0]);
  if (c[2] == '+')
    ans = min(ans, r2 + a[2]);
  else
    ans = min(ans, r2 * a[2]);
  if (c[2] == '+')
    ans = min(ans, r3 + b5);
  else
    ans = min(ans, r3 * b5);
  if (c[1] == '+')
    t1 = b6 + a[1];
  else
    t1 = b6 * a[1];
  if (c[1] == '+')
    t2 = b6 + a[0];
  else
    t2 = b6 * a[0];
  if (c[1] == '+')
    t3 = a[1] + a[0];
  else
    t3 = a[1] * a[0];
  if (c[2] == '+')
    ans = min(ans, t1 + a[0]);
  else
    ans = min(ans, t1 * a[0]);
  if (c[2] == '+')
    ans = min(ans, t2 + a[1]);
  else
    ans = min(ans, t2 * a[1]);
  if (c[2] == '+')
    ans = min(ans, t3 + b6);
  else
    ans = min(ans, t3 * b6);
  cout << ans;
}
