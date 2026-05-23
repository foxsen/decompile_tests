#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <numeric>

size_t f(size_t a, size_t b, size_t w) {
  a %= w+w;
  b += w+w+w+w;
  if ((a+b) % 2 == 0) {
    b -= a;
  } else {
    b += a;
  }
  if ((b/w) % 2 == 0) {
    return b%w;
  } else {
    return w - (b%w) - 1;
  }
}

int main() {
  size_t h, w, n;
  scanf("%zu %zu %zu", &h, &w, &n);

  std::vector<std::pair<size_t, size_t>> s(n);
  for (auto& si: s)
    scanf("%zu %zu", &si.first, &si.second);
  std::sort(s.begin(), s.end());

  std::vector<size_t> cur(w);
  std::iota(cur.begin(), cur.end(), 0);
  for (const auto& si: s) {
    size_t a, b;
    std::tie(a, b) = si;

    size_t lf = f(a, b-1, w);
    size_t rg = f(a, b, w);
    std::swap(cur[lf], cur[rg]);
  }

  std::vector<size_t> res(w);
  for (size_t i = 0; i < w; ++i)
    res[cur[f(h, i, w)]] = i+1;

  for (auto ri: res) printf("%zu\n", ri);
}

