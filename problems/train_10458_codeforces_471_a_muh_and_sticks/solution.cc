#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[9] = {0};
  for (int i = 0; i < 6; i++) {
    int help;
    cin >> help;
    arr[--help]++;
  }
  bool flag = false;
  int help = 0;
  for (int i = 0; i < 9; i++) {
    if (arr[i] >= 4) {
      flag = true;
      arr[i] -= 4;
    }
  }
  if (flag) {
    for (int i = 0; i < 9; i++)
      if (arr[i] == 2) {
        cout << "Elephant";
        return 0;
      }
    cout << "Bear";
  } else
    cout << "Alien";
  return 0;
}
