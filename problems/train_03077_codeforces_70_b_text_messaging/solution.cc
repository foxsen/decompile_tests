#include <bits/stdc++.h>
std::vector<int> v;
int main() {
  static char str[10000 + 1], t[10000 + 1];
  char *p;
  int n;
  scanf("%d\n%[^\n]", &n, str);
  for (char *ptr = strtok(str, ".?!"); ptr; ptr = strtok(NULL, ".?!")) {
    sscanf(ptr, "%[^.?!]", t);
    p = t;
    while (p[0] == ' ') ++p;
    v.push_back((int)strlen(p) + 1);
  }
  int result = 1, sum = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    if (v[i] > n) {
      puts("Impossible");
      return 0;
    }
    if (sum == 0) {
      sum = v[i];
    } else if (sum + v[i] + 1 > n) {
      ++result;
      sum = v[i];
    } else {
      sum += v[i] + 1;
    }
  }
  printf("%d\n", result);
  return 0;
}
