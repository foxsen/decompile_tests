#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int read() {
  int s = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') w = -1;
  }
  for (; isdigit(c); c = getchar()) {
    s = (s << 3) + (s << 1) + (c ^ 48);
  }
  return (w == 1 ? s : -s);
}
queue<int> q;
int main() {
  int t = read();
  while (t--) {
    int a = read(), b = read();
    if (a > b) swap(a, b);
    int n = a + b;
    int cnt = 0;
    if (n % 2 == 1) {
      int c = n / 2, d = n - c;
      if (c == a && d == b) {
        q.push(0);
        cnt++;
        for (int i = 1; i <= n; i++) {
          q.push(i);
          cnt++;
        }
        cout << cnt << endl;
        while (q.size() > 1) {
          cout << q.front() << " ";
          q.pop();
        }
        cout << q.front() << endl;
        q.pop();
      } else {
        int tt = c - a;
        q.push(tt);
        cnt++;
        for (int i = tt + 1; i <= n - tt; i++) {
          q.push(i);
          cnt++;
        }
        cout << cnt << endl;
        while (q.size() > 1) {
          cout << q.front() << " ";
          q.pop();
        }
        cout << q.front() << endl;
        q.pop();
      }
    } else {
      if (a == n / 2) {
        q.push(0);
        cnt++;
        for (int i = 2; i <= n; i += 2) {
          q.push(i);
          cnt++;
        }
        cout << cnt << endl;
        while (q.size() > 1) {
          cout << q.front() << " ";
          q.pop();
        }
        cout << q.front() << endl;
        q.pop();
      } else {
        int c = n / 2;
        int d = c - a;
        q.push(d);
        cnt++;
        for (int i = d + 2; i <= n - d; i += 2) {
          q.push(i);
          cnt++;
        }
        cout << cnt << endl;
        while (q.size() > 1) {
          cout << q.front() << " ";
          q.pop();
        }
        cout << q.front() << endl;
        q.pop();
      }
    }
  }
  return 0;
}
