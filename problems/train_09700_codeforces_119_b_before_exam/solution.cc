#include <bits/stdc++.h>
using namespace std;
int n, k, q;
int a[111];
bool checked[111];
double curMin = 999.99;
double curMax = -99.99;
int infoCount = 0;
void evaluate() {
  int lim = n / k;
  int tmp[111];
  for (int i = 0; i < lim; i++) scanf("%d", &tmp[i]);
  if (checked[tmp[0]]) return;
  infoCount++;
  double curSum = 0.0;
  for (int i = 0; i < lim; i++) {
    curSum += a[tmp[i]];
    checked[tmp[i]] = true;
  }
  curSum /= (double)lim;
  curMin = min(curMin, curSum);
  curMax = max(curMax, curSum);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) evaluate();
  if (infoCount == k) {
    printf("%.9f\n%.9f\n", curMin, curMax);
    return 0;
  }
  vector<int> bank;
  for (int i = 1; i <= n; i++)
    if (!checked[i]) bank.push_back(a[i]);
  sort(bank.begin(), bank.end());
  double minSum = 0;
  double maxSum = 0;
  int lim = n / k;
  for (int i = 0; i < lim; i++) {
    minSum += (double)bank[i];
    maxSum += (double)bank[bank.size() - 1 - i];
  }
  minSum /= (double)lim;
  maxSum /= (double)lim;
  curMin = min(curMin, minSum);
  curMax = max(curMax, maxSum);
  printf("%.9f\n%.9f\n", curMin, curMax);
  return 0;
}
