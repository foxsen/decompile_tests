#include <bits/stdc++.h>
using namespace std;
const string errtype = "errtype";
struct op;
map<string, op> types;
struct op {
  string id;
  int S, A;
  bool valid;
  op(string ID = "void", int star_cnt = 0, int amp_cnt = 0, bool ok = true)
      : id(ID), S(star_cnt), A(amp_cnt), valid(ok) {}
  op(string str, string ID) {
    S = A = 0;
    id = ID;
    int i = 0, j = (int)str.size() - 1;
    for (; i < str.size(); ++i) {
      if (str[i] == '&')
        ++A;
      else
        break;
    }
    for (; j >= 0; --j) {
      if (str[j] == '*')
        ++S;
      else
        break;
    }
    const string base_id = str.substr(i, j - i + 1);
    if (types.count(base_id)) {
      const op base_type = types[base_id];
      if (base_type.valid) {
        S += base_type.S;
        A += base_type.A;
        if (A > S)
          valid = false;
        else
          valid = true;
      } else
        valid = false;
    } else
      valid = false;
    int mn = min(S, A);
    S -= mn, A -= mn;
  }
  string toStr() const {
    if (valid == false) return errtype;
    string ans;
    for (int _n(S), s(0); s < _n; s++) ans = ans + "*";
    ans = "void" + ans;
    for (int _n(A), a(0); a < _n; a++) ans = "&" + ans;
    return ans;
  }
  bool operator<(const op& Op) {
    if (id < Op.id) return true;
    if (id == Op.id && S < Op.S) return true;
    if (id == Op.id && S == Op.S && A < Op.A) return true;
    if (id == Op.id && S == Op.S && A == Op.A) return true;
    if (id == Op.id && S == Op.S && A == Op.A && valid < Op.valid) return true;
    return false;
  }
};
op get_op(string str) {
  int A = 0, S = 0;
  int i = 0, j = (int)str.size() - 1;
  for (; i < str.size(); ++i) {
    if (str[i] == '&')
      ++A;
    else
      break;
  }
  for (; j >= 0; --j) {
    if (str[j] == '*')
      ++S;
    else
      break;
  }
  const string base_id = str.substr(i, j - i + 1);
  return op(str, base_id);
}
int main() {
  types["void"] = op();
  const string _typedef = "typedef";
  int N;
  cin >> N;
  for (int _n(N), iter(0); iter < _n; iter++) {
    string _operator;
    cin >> _operator;
    if (_operator == _typedef) {
      string op1, id;
      cin >> op1 >> id;
      types[id] = op(op1, id);
    } else {
      string id;
      cin >> id;
      cout << get_op(id).toStr() << endl;
    }
  }
  return 0;
}
