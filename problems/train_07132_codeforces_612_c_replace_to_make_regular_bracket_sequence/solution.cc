#include <bits/stdc++.h>
using namespace std;
char ch[1000000 + 10];
stack<int> s;
int main() {
  int i;
  while (~scanf("%s", ch)) {
    int l = strlen(ch);
    int flag = 1;
    int ans = 0;
    while (!s.empty()) s.pop();
    for (i = 0; i < l; i++) {
      if (ch[i] == '[' || ch[i] == '<' || ch[i] == '(' || ch[i] == '{')
        s.push(ch[i]);
      if (s.empty()) {
        flag = 0;
        break;
      }
      if (ch[i] == ']') {
        if (s.top() != '[') ans++;
        s.pop();
      } else if (ch[i] == '}') {
        if (s.top() != '{') ans++;
        s.pop();
      } else if (ch[i] == '>') {
        if (s.top() != '<') ans++;
        s.pop();
      } else if (ch[i] == ')') {
        if (s.top() != '(') ans++;
        s.pop();
      }
    }
    if (!s.empty() || !flag)
      printf("Impossible\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
