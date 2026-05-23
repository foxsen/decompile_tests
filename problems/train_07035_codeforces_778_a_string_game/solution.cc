#include <bits/stdc++.h>
using namespace std;
const long long maxN = 9999999;
char t[maxN], p[maxN];
long long an[maxN];
int len1, len2;
bool book[maxN];
bool check(int x) {
  for (int i = 1; i <= x; i++) {
    book[an[i] - 1] = 1;
  }
  int index = 0, count = 0;
  for (int i = 0; i <= len2; i++) {
    for (; index < len1; index++) {
      if (!book[index] && p[i] == t[index]) {
        index++;
        count++;
        break;
      }
    }
  }
  return count == len2;
}
int main() {
  cin >> t;
  cin >> p;
  len1 = strlen(t);
  len2 = strlen(p);
  for (int i = 1; i <= len1; i++) {
    cin >> an[i];
  }
  int l = 0, r = len1, ans = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    memset(book, 0, maxN);
    if (check(mid)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << l - 1;
}
