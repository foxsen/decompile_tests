#include <bits/stdc++.h>
int main() {
  std::string s;
  std::cin >> s;
  std::list<int> stones = {1};
  auto last_node = stones.begin();
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'r') {
      last_node++;
    }
    last_node = stones.insert(last_node, i + 2);
  }
  for (auto it = stones.begin(); it != stones.end(); it++) {
    printf("%d\n", *it);
  }
}
