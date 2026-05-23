#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.in");
ofstream fout("output.out");
stack<bool> S;
pair<string, bool> P[1000005];
string str;
int pind;
void add(string str) {
  if (str[0] == '/') {
    str = str.substr(1);
    P[++pind] = make_pair(str, 0);
  } else if (str[str.size() - 1] == '/') {
    str.resize(str.size() - 1);
    P[++pind] = make_pair(str, 1), P[++pind] = make_pair(str, 0);
  } else {
    P[++pind] = make_pair(str, 1);
  }
}
void parcala() {
  int i;
  string temp;
  for (i = 0; i < str.size(); i++) {
    if (str[i] == '>')
      add(temp), temp = "";
    else if (str[i] != '<')
      temp += str[i];
  }
}
void solve() {
  cin >> str;
  parcala();
  int i, j, g, M, res, n, t;
  string Q[205], q, temp;
  cin >> M;
  getline(cin, q);
  for (i = 1; i <= M; i++) {
    getline(cin, q);
    fill(Q, Q + 202, "");
    n = 0;
    for (j = 0; j <= q.size(); j++) {
      if (q[j] == ' ' || j == q.size())
        Q[++n] = temp, temp = "";
      else
        temp += q[j];
    }
    g = 1, res = 0;
    for (j = 1; j <= pind; j++)
      if (P[j].second == 1) {
        if (g <= n && P[j].first == Q[g])
          S.push(1), g++;
        else
          S.push(0);
        if (g == n + 1 && P[j].first == Q[n]) res++;
      } else {
        t = S.top(), S.pop();
        if (t) g--;
      }
    cout << res << endl;
  }
}
int main() { solve(); }
