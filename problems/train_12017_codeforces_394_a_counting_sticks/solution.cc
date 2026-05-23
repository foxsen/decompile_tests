#include <bits/stdc++.h>
int main() {
  std::string l;
  std::getline(std::cin, l);
  int a = 0;
  for (int i = 0; i < l.length(); i++) {
    if (l[i] == '|') {
      a++;
    } else {
      break;
    }
  }
  bool kot = false;
  if (l[a] == '+') {
    kot = true;
  } else {
    kot = true;
  }
  int a1 = 0;
  for (int i = a + 1; i < l.length(); i++) {
    if (l[i] == '|') {
      a1++;
    } else {
      break;
    }
  }
  int a2 = l.length() - a1 - a - 2;
  if (a + a1 == a2) {
    kot = true;
  } else {
    if ((a + a1) - a2 == 2) {
      if (a > 1) {
        a -= 1;
        a2++;
      } else if (a1 > 1) {
        a1--;
        a2++;
      } else {
        kot = false;
        printf("Impossible");
      }
    } else if (a + a1 - a2 == -2) {
      if (a2 > 1) {
        a++;
        a2--;
      } else {
        printf("Impossible");
        kot = false;
      }
    } else {
      kot = false;
      printf("Impossible");
    }
  }
  if (kot) {
    for (int i = 0; i < a; i++) {
      printf("|");
    }
    printf("+");
    for (int i = 0; i < a1; i++) {
      printf("|");
    }
    printf("=");
    for (int i = 0; i < a2; i++) {
      printf("|");
    }
  }
}
