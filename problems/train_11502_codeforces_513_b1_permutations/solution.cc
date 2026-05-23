#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long k;
  cin >> n >> k;
  int left = 1, right = n, next = 1, sol[55];
  long long cnt = ((long long)1 << (n - 1));
  while (left <= right) {
    if (k <= cnt / 2)
      sol[left++] = next;
    else {
      sol[right--] = next;
      k -= (cnt / 2);
    }
    next++;
    cnt /= 2;
  }
  for (int i = 1; i <= n; i++) cout << sol[i] << " ";
}
