#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
void open() {
  ((void)0);
  ((void)0);
  ((void)0);
}
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const long double ERR = 1e-10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int main(int argc, char *argv[]) {
  open();
  int N;
  scanf("%d", &N);
  if (N % 2)
    return !printf("0\n");
  else
    return !printf("%d\n", 1 << (N / 2));
  return 0;
}
