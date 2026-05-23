#include <bits/stdc++.h>
int main() {
  int n, p, q;
  std::cin >> n;
  bool arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = false;
  }
  std::cin >> p;
  int buffer;
  for (int i = 0; i < p; i++) {
    std::cin >> buffer;
    arr[buffer - 1] = true;
  }
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> buffer;
    arr[buffer - 1] = true;
  }
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (arr[i] == false) {
      flag = false;
      break;
    }
  }
  if (flag) {
    std::cout << "I become the guy.";
  } else {
    std::cout << "Oh, my keyboard!";
  }
  return 0;
}
