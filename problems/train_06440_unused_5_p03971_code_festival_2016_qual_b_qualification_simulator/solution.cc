#include <bits/stdc++.h>

int n, a, b, x, y;
std::string s;

int main() {
  std::cin >> n >> a >> b >> s;
  x = 0;
  y = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' && x < (a+b)) {
      std::cout << "Yes" << std::endl;
      x++;
    }
    else if (s[i] == 'b' && x < (a+b) && y < b) {
      std::cout << "Yes" << std::endl;
      x++;
      y++;
    }
    else {
      std::cout << "No" << std::endl;
    }
  }
}