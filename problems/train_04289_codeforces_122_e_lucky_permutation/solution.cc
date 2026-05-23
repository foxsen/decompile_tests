#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
vector<int> lucky;
void generate(long long n) {
  if (n > 1000000000LL)
    return;
  else {
    generate(n * 10 + 4);
    generate(n * 10 + 7);
    if (n > 0) lucky.push_back(n);
  }
}
void unrank(vector<int> &perm, int n, long long num) {
  bool used[n];
  memset(used, false, n * sizeof(bool));
  long long fak = 1;
  for (int i = (1); i < (n + 1); ++i) fak *= i;
  for (int i = (0); i < (n); ++i) {
    fak /= n - i;
    int k = num / fak;
    num = num % fak;
    int j = 0;
    while (k >= 0) {
      if (!used[j]) --k;
      j++;
    }
    perm[i] = j - 1;
    used[j - 1] = true;
  }
}
bool isLucky(int n) {
  while (n > 0) {
    int c = n % 10;
    if (c != 7 && c != 4) return false;
    n /= 10;
  }
  return true;
}
int main() {
  int N, M = 0, K;
  scanf("%d %d", &N, &K);
  generate(0);
  long long faculty = 1;
  for (int i = (1); i < (N + 1); ++i) {
    faculty *= (M = i);
    if (faculty >= K) break;
  }
  if (faculty < K) {
    printf("-1\n");
    return 0;
  }
  vector<int> permutation(M);
  unrank(permutation, M, K - 1);
  int res = 0;
  sort((lucky).begin(), (lucky).end());
  int changeIndex = N - M + 1;
  for (int i = (0); i < (int((lucky).size())); ++i)
    if (lucky[i] < changeIndex) ++res;
  for (int i = (changeIndex); i < (N + 1); ++i) {
    int position = i;
    int element = changeIndex + permutation[i - changeIndex];
    if (isLucky(position) && isLucky(element)) ++res;
  }
  printf("%d\n", res);
  return 0;
}
