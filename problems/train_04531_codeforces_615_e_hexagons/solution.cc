#include <bits/stdc++.h>
using namespace std;
const int dx[6] = {-1, -2, -1, 1, 2, 1}, dy[6] = {-2, 0, 2, 2, 0, -2};
int main() {
  long long n;
  cin >> n;
  long long k = max(0LL, (long long)sqrt(n / 3.0) - 1);
  while (!(3 * k * (k + 1) >= n)) k++;
  long long ind = 3 * k * (k + 1) - n;
  long long nowx = 2 * k, nowy = 0;
  for (int i = 0; i < 6; i++)
    if (ind < k) {
      nowx += ind * dx[i];
      nowy += ind * dy[i];
      break;
    } else {
      nowx += k * dx[i];
      nowy += k * dy[i];
      ind -= k;
    }
  cout << nowx << ' ' << nowy << endl;
  return 0;
}
