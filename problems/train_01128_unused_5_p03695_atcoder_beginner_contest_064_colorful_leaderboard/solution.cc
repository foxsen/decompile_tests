#include <bits/stdc++.h>

using namespace std;

int main() {
  int a;
  std::cin >> a;
  std::bitset<8> ls{};
  int u = 0;
  while (std::cin >> a) {
    if (a < 3200) {
      ls.set(a / 400);
    } else {
      u++;
    }
  }
  std::cout << std::max(static_cast<int>(ls.count()), 1) << " "
            << ls.count() + u << std::endl;
  return 0;
}
