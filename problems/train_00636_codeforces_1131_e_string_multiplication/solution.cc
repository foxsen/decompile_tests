#include <bits/stdc++.h>
int32_t get_answer_direct(std::string& str, char ch) {
  int32_t answer = 0;
  int32_t begin = 0;
  for (int32_t i = 1; i < str.size(); i++)
    if (str[i] != str[begin]) {
      if (str[i - 1] == ch) answer = std::max(answer, i - begin);
      begin = i;
    }
  if (str[str.size() - 1] == ch)
    answer = std::max(answer, (int32_t)str.size() - begin);
  return answer;
}
int32_t get_answer(int32_t n, std::string* strings, char ch) {
  if (n == 1) {
    return get_answer_direct(strings[0], ch);
  } else {
    bool all_ch = true;
    for (int32_t i = 0; i < strings[n - 1].size(); i++)
      if (strings[n - 1][i] != ch) {
        all_ch = false;
        break;
      }
    if (all_ch) {
      int32_t answer_prev = get_answer(n - 1, strings, ch);
      return answer_prev + (answer_prev + 1) * strings[n - 1].size();
    } else {
      bool* char_exists = new bool[26];
      for (int32_t i = 0; i < 26; i++) char_exists[i] = false;
      for (int32_t i = 0; i < n - 1; i++)
        for (int32_t j = 0; j < strings[i].size(); j++)
          char_exists[strings[i][j] - 'a'] = true;
      int32_t answer = 0;
      for (int32_t i = 0; i < 26; i++) {
        if (!char_exists[i]) continue;
        std::string str_cur =
            strings[n - 1] + std::string(1, (char)('a' + i)) + strings[n - 1];
        answer = std::max(answer, get_answer_direct(str_cur, ch));
      }
      return answer;
    }
  }
}
int main() {
  int32_t n;
  std::cin >> n;
  std::string* strings = new std::string[n];
  for (int32_t i = 0; i < n; i++) std::cin >> strings[i];
  int32_t answer = 1;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    answer = std::max(answer, get_answer(n, strings, ch));
  }
  std::cout << answer;
  return 0;
}
