#include <bits/stdc++.h>
using namespace std;
int arr[101];
int Step[1001][2];
int main() {
  int N, k;
  cin >> N >> k;
  int MAX = 0, MIN = 10001;
  for (int i = 1; i <= N; ++i) cin >> arr[i];
  if (N == 1) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  int count = 0, h;
  while (count <= k) {
    count++;
    int mn = 10001, mx = 0, pos_mn, pos_mx;
    for (int i = 1; i <= N; ++i) {
      if (arr[i] > mx) {
        mx = arr[i];
        pos_mx = i;
      }
      if (arr[i] < mn) {
        mn = arr[i];
        pos_mn = i;
      }
    }
    h = mx - mn;
    if (arr[pos_mn] + 1 > arr[pos_mx] - 1)
      break;
    else {
      Step[count][0] = pos_mx;
      Step[count][1] = pos_mn;
      arr[pos_mn]++;
      arr[pos_mx]--;
    }
  }
  cout << h << " " << count - 1 << endl;
  for (int i = 1; i < count; ++i)
    cout << Step[i][0] << " " << Step[i][1] << endl;
  return 0;
}
