#include <string>
#include <iostream>
using namespace std;

/*
  <expr>   ::= <term> [ ('+'|'-') <term> ]*
  <term>   ::= <factor> [ ('*'|'/') <factor> ]*
  <factor> ::= <number> | '(' <expr> ')'
  <number> :== 1?????\????????°???
*/

int expr(string& s, int& i);
int term(string& s, int& i);
int factor(string& s, int& i);
int number(string& s, int& i);

int expr(string& s, int& i) {
  int val = term(s, i);
  while (s[i] == '+' || s[i] == '-') {
    char op = s[i];
    i++;
    int val2 = term(s, i);
    if (op == '+')
      val += val2;
    else
      val -= val2;
  }
  return val;
}

int term(string& s, int& i) {
  int val = factor(s, i);
  while (s[i] == '*' || s[i] == '/') {
    char op = s[i];
    i++;
    int val2 = factor(s, i);
    if (op == '*')
      val *= val2;
    else
      val /= val2;
  }
  return val;
}

int factor(string& s, int& i) {
  int val;
  if (s[i] != '(') {
    val = number(s, i);
  } else {
    i++;
    val = expr(s, i);
    i++;
  }
  return val;
}

int number(string& s, int& i) {
  int val = 0;
  while(isdigit(s[i])) {
    val = val*10 + (s[i] - '0');
    i++;
  }
  return val;
}

int main() {
  int n;
  cin >> n;
  for (int j=0; j<n; j++) {
    int i = 0;
    string str;
    cin >> str;
    cout << expr(str, i) << endl;
  }
}