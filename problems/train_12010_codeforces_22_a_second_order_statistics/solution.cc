#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int num, j = 0, times = 1;
  cin >> num;
  int arr[num];
  for (int i = 0; i < num; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + num);
  while (arr[j] == arr[j + 1] && j < num - 1) {
    times++;
    j++;
  }
  if (times == num)
    cout << "NO\n";
  else
    cout << arr[j + 1];
  return 0;
}
