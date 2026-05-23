#include <bits/stdc++.h>
using namespace std;
const int MAXLEN = 105;
const int MAXV = 32768;
int f[MAXV];
int FindChar(string &st, string charst) {
  int len = st.length();
  int inb = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (st[i] == ')')
      inb++;
    else if (st[i] == '(')
      inb--;
    else if (inb == 0) {
      for (int j = 0; j < charst.length(); j++)
        if (st[i] == charst[j]) return i;
    }
  }
  return -1;
}
int CalcExp(int n, string st) {
  int pmpos = FindChar(st, "+-");
  if (pmpos != -1) {
    int val0 = CalcExp(n, st.substr(0, pmpos));
    int val1 = CalcExp(n, st.substr(pmpos + 1));
    if (st[pmpos] == '+')
      return (val0 + val1) % MAXV;
    else
      return ((val0 - val1) % MAXV + MAXV) % MAXV;
  }
  int mdpos = FindChar(st, "*/");
  if (mdpos != -1) {
    int val0 = CalcExp(n, st.substr(0, mdpos));
    int val1 = CalcExp(n, st.substr(mdpos + 1));
    if (st[mdpos] == '*')
      return val0 * val1 % MAXV;
    else
      return val0 / val1 % MAXV;
  }
  int brpos = st.find('(');
  if (brpos != -1) {
    st = st.substr(brpos + 1);
    st = st.substr(0, st.find_last_of(')'));
    return f[CalcExp(n, st)];
  }
  while (isspace(st[0])) st = st.substr(1);
  while (isspace(st[st.length() - 1])) st = st.substr(0, st.length() - 1);
  if (st[0] == 'n')
    return n;
  else
    return atoi(st.c_str());
}
bool CalcLogic(int n, string st) {
  int oppos;
  st = st.substr(st.find('(') + 1);
  st = st.substr(0, st.find_last_of(')'));
  if ((oppos = st.find("==")) != string::npos ||
      (oppos = st.find(">")) != string::npos ||
      (oppos = st.find("<")) != string::npos) {
    int val0 = CalcExp(n, st.substr(0, oppos));
    int val1 = CalcExp(n, st.substr(oppos + 2));
    if (st[oppos] == '=')
      return val0 == val1;
    else if (st[oppos] == '<')
      return val0 < val1;
    else
      return val0 > val1;
  }
  return true;
}
int CalcF(int n, string st) {
  int pos;
  st = st.substr(st.find('{') + 1);
  st = st.substr(0, st.find('}'));
  while ((pos = st.find(';')) != string::npos) {
    string statement = st.substr(0, pos);
    st = st.substr(pos + 1);
    int posif = statement.find("if");
    int posret = statement.find("return");
    if (posif != string::npos) {
      if (CalcLogic(n, statement.substr(posif + 2, posret - posif - 2)))
        return CalcExp(n, statement.substr(posret + 7));
    } else
      return CalcExp(n, statement.substr(posret + 7));
  }
  return 0;
}
int main() {
  char charst[MAXLEN];
  int tar;
  int ans = -1;
  string st = "";
  scanf("%d", &tar);
  gets(charst);
  while (gets(charst) != NULL) {
    string temst = charst;
    st = st.append(temst);
  }
  for (int i = 0; i < MAXV; i++) {
    f[i] = CalcF(i, st);
    if (f[i] == tar) ans = i;
  }
  printf("%d\n", ans);
  return 0;
}
