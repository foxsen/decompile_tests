#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  vector<string> v = {string("+------------------------+"),
                      string("|O.O.O.#.#.#.#.#.#.#.#.|D|)"),
                      string("|O.O.O.#.#.#.#.#.#.#.#.|.|"),
                      string("|O.......................|"),
                      string("|O.O.#.#.#.#.#.#.#.#.#.|.|)"),
                      string("+------------------------+")};
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      if (v[i][j] == 'O') v[i][j] = '#';
    }
  }
  int cur = 1;
  int size_cur = 1;
  for (int i = 0; i < n; ++i) {
    v[size_cur][cur] = 'O';
    ++size_cur;
    if (size_cur > 4) {
      cur += 2;
      size_cur = 1;
    }
    if (size_cur == 3 && cur != 1) size_cur += 1;
  }
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << endl;
  }
}
