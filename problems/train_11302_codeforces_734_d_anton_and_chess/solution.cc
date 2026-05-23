#include <bits/stdc++.h>
using namespace std;
char p[500005];
long long int px[500005], py[500005];
int main() {
  long long int x, y;
  int n;
  scanf("%d", &n);
  scanf("%lld %lld", &x, &y);
  for (int i = 0; i < n; i++) cin >> p[i] >> px[i] >> py[i];
  int flag = 0;
  char pp;
  pp = 'X';
  long long int dist, md = 2000000000000;
  for (int i = 0; i < n; i++) {
    if (py[i] > y && px[i] == x) {
      dist = py[i] - y;
      if (dist < md) {
        md = dist;
        pp = p[i];
      }
    }
  }
  if (pp == 'Q' || pp == 'R') {
    printf("YES\n");
    exit(0);
  }
  pp = 'X';
  md = 20000000000000;
  for (int i = 0; i < n; i++) {
    if (py[i] == y && px[i] > x) {
      dist = px[i] - x;
      if (dist < md) {
        md = dist;
        pp = p[i];
      }
    }
  }
  if (pp == 'Q' || pp == 'R') {
    printf("YES\n");
    exit(0);
  }
  pp = 'X';
  md = 20000000000000;
  for (int i = 0; i < n; i++) {
    if (py[i] == y && px[i] < x) {
      dist = x - px[i];
      if (dist < md) {
        md = dist;
        pp = p[i];
      }
    }
  }
  if (pp == 'Q' || pp == 'R') {
    printf("YES\n");
    exit(0);
  }
  pp = 'X';
  md = 20000000000000;
  for (int i = 0; i < n; i++) {
    if (px[i] == x && py[i] < y) {
      dist = y - py[i];
      if (dist < md) {
        md = dist;
        pp = p[i];
      }
    }
  }
  if (pp == 'Q' || pp == 'R') {
    printf("YES\n");
    exit(0);
  }
  pp = 'X';
  md = 20000000000000;
  for (int i = 0; i < n; i++) {
    if (py[i] > y && px[i] > x && (py[i] - y) == (px[i] - x)) {
      dist = (px[i] - x);
      if (dist < md) {
        md = dist;
        pp = p[i];
      }
    }
  }
  if (pp == 'B' || pp == 'Q') {
    printf("YES\n");
    exit(0);
  }
  pp = 'X';
  md = 20000000000000;
  for (int i = 0; i < n; i++) {
    if (py[i] < y && px[i] < x && (py[i] - y) == (px[i] - x)) {
      dist = (x - px[i]);
      if (dist < md) {
        md = dist;
        pp = p[i];
      }
    }
  }
  if (pp == 'B' || pp == 'Q') {
    printf("YES\n");
    exit(0);
  }
  pp = 'X';
  md = 20000000000000;
  for (int i = 0; i < n; i++) {
    if (py[i] < y && px[i] > x && (py[i] - y) == -1 * (px[i] - x)) {
      dist = (px[i] - x);
      if (dist < md) {
        md = dist;
        pp = p[i];
      }
    }
  }
  if (pp == 'B' || pp == 'Q') {
    printf("YES\n");
    exit(0);
  }
  pp = 'X';
  md = 20000000000000;
  for (int i = 0; i < n; i++) {
    if (py[i] > y && px[i] < x && (py[i] - y) == -1 * (px[i] - x)) {
      dist = (py[i] - y);
      if (dist < md) {
        md = dist;
        pp = p[i];
      }
    }
  }
  if (pp == 'B' || pp == 'Q') {
    printf("YES\n");
    exit(0);
  }
  printf("NO\n");
  return 0;
}
