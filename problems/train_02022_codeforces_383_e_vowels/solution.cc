#include <bits/stdc++.h>
using namespace std;
const int MAX = 10010;
const int N = 24;
int inv = (1 << N) - 1;
int F[(1 << N) + 10];
int ara[MAX];
int howManyZeroPairs(int n, int ara[]) {
  memset(F, 0, sizeof(F));
  for (int i = 0; i < n; i++) F[ara[i]]++;
  ;
  for (int i = 0; i < N; ++i)
    for (int mask = 0; mask < (1 << N); ++mask) {
      if (mask & (1 << i)) F[mask] += F[mask ^ (1 << i)];
    }
  int ans = 0;
  for (int i = 0; i < (1 << N); i++)
    ans ^= ((n - F[i ^ inv]) * (n - F[i ^ inv]));
  return ans;
}
char str[5];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    ara[i] = ara[i] ^ (1 << (str[0] - 'a'));
    if (!(ara[i] & (1 << (str[1] - 'a'))))
      ara[i] = ara[i] ^ (1 << (str[1] - 'a'));
    if (!(ara[i] & (1 << (str[2] - 'a'))))
      ara[i] = ara[i] ^ (1 << (str[2] - 'a'));
  }
  cout << howManyZeroPairs(n, ara) << endl;
  return 0;
}
