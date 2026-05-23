#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int a, n, q, i, x, y, dis, p, c;
  cin >> n >> q;
  a = n * n;
  if (a % 2 == 1) a++;
  a /= 2;
  while (q--) {
    cin >> x >> y;
    if ((x + y) % 2 == 0) {
      if (n % 2 == 0) {
        p = 0;
        dis = n / 2;
        p = dis * (x - 1);
        if (x % 2 == 0) {
          dis = y / 2;
          p += dis;
        } else {
          dis = (y + 1) / 2;
          p += dis;
        }
      } else {
        p = 0;
        dis = (n + 1) / 2;
        if (x % 2 == 0) {
          c = x / 2;
          p += (c * dis);
          c = (x / 2) - 1;
          p += (c * (dis - 1));
          dis = y / 2;
          p += dis;
        } else {
          c = x / 2;
          p += (c * dis);
          p += (c * (dis - 1));
          dis = (y + 1) / 2;
          p += dis;
        }
      }
      cout << p << endl;
    } else {
      if (n % 2 == 0) {
        p = 0;
        dis = n / 2;
        p = dis * (x - 1);
        if (x % 2 == 0) {
          dis = (y + 1) / 2;
          p += dis;
        } else {
          dis = y / 2;
          p += dis;
        }
      } else {
        p = 0;
        dis = (n - 1) / 2;
        if (x % 2 == 0) {
          c = x / 2;
          p += (c * dis);
          c = (x / 2) - 1;
          p += (c * (dis + 1));
          dis = (y + 1) / 2;
          p += dis;
        } else {
          c = x / 2;
          p += (c * dis);
          p += (c * (dis + 1));
          dis = y / 2;
          p += dis;
        }
      }
      cout << p + a << endl;
    }
  }
  return 0;
}
