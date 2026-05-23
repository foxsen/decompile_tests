#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
  int n, m;
  std::cin >> n;
  long a[200001], b[200001];
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];

  std::cin >> m;
  for (int i = 0; i < m; ++i)
    std::cin >> b[i];

  std::cout << std::includes(a, a + n, b, b + m) << std::endl;
}

