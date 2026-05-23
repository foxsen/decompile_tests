#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3050;
const long long Mod = 152076289;
int p[MAXN];
int cnt;
int temp[MAXN];
void Merge(int low, int mid, int high) {
  int i = low;
  int j = mid + 1;
  int x = low;
  while (i <= mid && j <= high) {
    if (p[i] > p[j]) {
      cnt += mid - i + 1;
      temp[x++] = p[j++];
    } else {
      temp[x++] = p[i++];
    }
  }
  while (i <= mid) temp[x++] = p[i++];
  while (j <= high) temp[x++] = p[j++];
  for (int k = low; k <= high; k++) p[k] = temp[k];
}
void mergesort(int low, int high) {
  if (low < high) {
    int mid = (low + high) >> 1;
    mergesort(low, mid);
    mergesort(mid + 1, high);
    Merge(low, mid, high);
  }
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }
  mergesort(0, n - 1);
  double ans;
  if (cnt & 1)
    ans = cnt * 2 - 1;
  else
    ans = cnt * 2;
  printf("%.6f\n", ans);
  return 0;
}
