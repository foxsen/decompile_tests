#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int a = 0; a < t; a++) {
    int n;
    scanf("%d", &n);
    string attack, prepend;
    cin >> attack;
    while (!attack.empty() and attack.back() == attack.front()) {
      prepend += attack.back();
      attack.pop_back();
    }
    if (attack.empty()) {
      printf("%d\n", (n + 2) / 3);
      continue;
    }
    attack = prepend + attack;
    int answer = 0, streak = 1;
    for (int b = 1; b < n; b++) {
      if (attack[b] == attack[b - 1]) {
        streak++;
      } else {
        streak = 1;
      }
      if (streak % 3 == 0) {
        answer++;
      }
    }
    printf("%d\n", answer);
  }
}
