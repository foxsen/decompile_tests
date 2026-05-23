#include <bits/stdc++.h>
using namespace std;
long long ax, ay, bx, by, cx, cy;
bool valid() {
  return (ax * (by - cy)) + (bx * (cy - ay)) + (cx * (ay - by)) != 0LL;
}
int main() {
  while (scanf("%lld %lld %lld %lld %lld %lld", &ax, &ay, &bx, &by, &cx, &cy) ==
         6) {
    long long ab = ((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by));
    long long bc = ((bx - cx) * (bx - cx)) + ((by - cy) * (by - cy));
    puts(valid() && ab == bc ? "Yes" : "No");
  }
  return 0;
}
