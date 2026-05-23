#include <bits/stdc++.h>
int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<bool> look_right(n, false);
  for (size_t i = 0; i < n; i++) {
    char t;
    std::cin >> t;
    if (t == 'R') look_right.at(i) = true;
  }
  int min_moves = 0;
  std::vector<std::vector<int>> moves;
  for (;;) {
    moves.emplace_back();
    for (size_t i = 0; i < n - 1; i++) {
      if (look_right.at(i) && !look_right.at(i + 1)) {
        min_moves++;
        moves.back().push_back(i);
        look_right.at(i) = false;
        look_right.at(i + 1) = true;
        i++;
      }
    }
    if (moves.back().size() == 0) {
      moves.pop_back();
      break;
    }
  }
  if (min_moves < k || moves.size() > k)
    std::cout << -1 << std::endl;
  else {
    int nmoves = moves.size();
    auto itb = moves.cbegin();
    auto itl = itb->cbegin();
    while (nmoves < k) {
      nmoves++;
      std::cout << "1 " << *itl + 1 << '\n';
      itl++;
      if (itl == itb->cend()) {
        nmoves--;
        itb++;
        itl = itb->cbegin();
      }
    }
    for (; itb != moves.cend(); itb++, itl = itb->cbegin()) {
      std::cout << std::distance(itl, itb->cend()) << ' ';
      for (; itl != itb->cend(); itl++) std::cout << *itl + 1 << ' ';
      std::cout << std::endl;
    }
  }
  return 0;
}
