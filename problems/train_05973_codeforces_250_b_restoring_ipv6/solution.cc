#include <bits/stdc++.h>
using namespace std;
int N;
char s[1000];
int chartoint(char c) {
  if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  return c - '0';
}
int stringtoint(char *s) {
  int len = strlen(s);
  int sum = 0;
  for (int i = 0; i < len; i++) sum = sum * 16 + chartoint(s[i]);
  return sum;
}
vector<int> split(char *s) {
  vector<int> ans;
  int len = strlen(s);
  for (int i = 0; i < len; ++i)
    if (s[i] == ':') s[i] = 0;
  for (int i = 0; i < len; ++i)
    if (s[i]) {
      ans.push_back(stringtoint(s + i));
      i += strlen(s + i);
    }
  return ans;
}
void solve(char *s) {
  std::vector<int> ip(8, 0), left, right;
  int len = strlen(s), i;
  for (i = 0; i < len - 1; ++i)
    if (s[i] == ':' && s[i + 1] == ':') {
      s[i] = 0;
      break;
    }
  if (i != len - 1) {
    left = split(s);
    right = split(s + i + 2);
  } else {
    left = split(s);
  }
  for (i = 0; i < left.size(); ++i) ip[i] = left[i];
  for (i = 0; i < right.size(); ++i) ip[8 - right.size() + i] = right[i];
  for (i = 0; i < 8; ++i) {
    if (i) putchar(':');
    printf("%04x", ip[i]);
  }
  puts("");
}
int main(int argc, char const *argv[]) {
  scanf("%d", &N);
  getchar();
  for (int i = 0; i < N; ++i) {
    gets(s);
    solve(s);
  }
  return 0;
}
