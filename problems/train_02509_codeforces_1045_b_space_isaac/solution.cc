#include <bits/stdc++.h>
using std::abs;
using std::array;
using std::cerr;
using std::cin;
using std::cout;
using std::generate;
using std::get;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
using std::pair;
using std::queue;
using std::reverse;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::tuple;
using std::unique;
using std::vector;
template <typename T>
T input() {
  T res;
  cin >> res;
  {};
  return res;
}
template <typename IT>
void input_seq(IT b, IT e) {
  std::generate(b, e,
                input<typename std::remove_reference<decltype(*b)>::type>);
}
int main() {
  std::iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int64_t n = input<int64_t>();
  int64_t m = 2 * input<int64_t>();
  vector<int64_t> a(n);
  for (int64_t& elem : a) elem = 2 * input<int64_t>();
  vector<int64_t> parts;
  for (int64_t i = 0; i < n; ++i) {
    int64_t x = a[i];
    int64_t y = (i == 0 ? a.back() - m : a[i - 1]);
    parts.push_back((x - y) / 2);
    parts.push_back((x - y) / 2);
  }
  int64_t orig_sz = int64_t((parts).size());
  for (int64_t i = 0; i < 2 * orig_sz; ++i) parts.push_back(parts[i]);
  vector<int64_t> mana(3 * orig_sz);
  int64_t L = -1, R = -1;
  for (int64_t i = 1; i < 3 * orig_sz; ++i) {
    if (i <= R) mana[i] = min(R - i + 1, mana[R + L - i + 1]);
    while (i + mana[i] < int64_t((parts).size()) and i - 1 - mana[i] >= 0 and
           parts[i + mana[i]] == parts[i - 1 - mana[i]])
      ++mana[i];
    if (i + mana[i] - 1 > R) {
      R = i + mana[i] - 1;
      L = i - mana[i];
    }
  }
  vector<int64_t> bad;
  int64_t curval = a.back();
  for (int64_t i = orig_sz; i < 2 * orig_sz; curval += parts[i++])
    if (2 * mana[i] >= orig_sz) {
      bad.push_back((2 * curval) % m);
    }
  sort(bad.begin(), bad.end());
  bad.resize(std::unique(bad.begin(), bad.end()) - bad.begin());
  cout << int64_t((bad).size()) << "\n";
  for (int64_t x : bad) cout << x / 2 << " ";
  cout << "\n";
  return 0;
}
