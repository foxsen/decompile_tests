#include <bits/stdc++.h>
using namespace std;
int N, M;
char word[200];
int main() {
  cin >> N >> M;
  cin >> word;
  while (M--) {
    int l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;
    for (int i = l - 1; i <= r - 1; ++i)
      if (word[i] == c1) word[i] = c2;
  }
  cout << word;
  return 0;
}
