#include <bits/stdc++.h>
std::vector<int> left;
std::map<int, int> right;
std::pair<int, int> bracket(std::string seq) {
  std::vector<char> stk;
  for (char i : seq) {
    if (i == ')') {
      if (!stk.empty() && stk.back() == '(') {
        stk.pop_back();
      } else {
        stk.push_back(')');
      }
    }
    if (i == '(') {
      stk.push_back('(');
    }
  }
  int left = 0, right = 0;
  for (char i : stk) {
    if (i == '(') {
      left++;
    } else {
      right++;
    }
  }
  return std::make_pair(left, right);
}
int main() {
  int empty = 0;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::string seq;
    std::cin >> seq;
    auto mseq = bracket(seq);
    if (mseq.first == 0 && mseq.second != 0) {
      right[mseq.second]++;
    }
    if (mseq.first != 0 && mseq.second == 0) {
      left.push_back(mseq.first);
    }
    if (mseq.first == 0 && mseq.second == 0) {
      empty++;
    }
  }
  long long ans = 0;
  for (int i : left) {
    ans += right[i];
  }
  ans += (long long)empty * empty;
  std::cout << ans << std::endl;
  return 0;
}
