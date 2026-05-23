#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...) 1145141919810
#define CHECK(...) (__VA_ARGS__)
#endif

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  const int BIT = 10;

  int n;
  reader >> n;

  std::vector<std::vector<int>> vec(BIT, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    reader >> vec[0][i];
  }
  auto update = [&](int level, int l) -> void {
    CHECK(level > 0);
    int r = std::min(n, l + (1 << level));  // [l, r)
    int mid = std::min(n, l + (1 << (level - 1)));
    const auto& prev = vec[level - 1];
    auto& cur = vec[level];
    for (int i = l, j = mid, k = l, offset = 0; k < r; ++k) {
      if (i == mid || (j < r && prev[i] >= prev[j] - offset)) {
        cur[k] = prev[j++] - offset;
      } else {
        cur[k] = prev[i++];
        ++offset;
      }
    }
  };
  for (int level = 1; level < BIT; ++level) {
    for (int i = 0; i < n; i += (1 << level)) {
      update(level, i);
    }
  }
  int q;
  reader >> q;
  while (q--) {
    int op, i;
    reader >> op >> i; --i;
    if (op == 1) {
      int x;
      reader >> x;
      vec[0][i] = x;
      for (int level = 1; level < BIT; ++level) {
        if (i >> (level - 1) & 1)
          i -= 1 << (level - 1);
        update(level, i);
      }
    } else {
      int v = vec[0][i];
      ++i;
      while (i < n) {
        int level = std::min(BIT - 1, __builtin_ctz(i));
        v += std::upper_bound(vec[level].begin() + i, vec[level].begin() + std::min(n, i + (1 << level)), v)
          - vec[level].begin() - i;
        i += 1 << level;
      }
      printf("%d\n", n - v);
    }
  }
}

