#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef pair<string,string> SP;

struct Rule {
  int type;
  string a, b;
};

const int type_permit = 0;
const int type_deny   = 1;

int N, M;
vector<Rule> rules;

bool isMatch(const string &s, const string &t) {
  if(s.size() != t.size()) return false;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '?' || t[i] == '?') continue;
    if(s[i] != t[i]) return false;
  }
  return true;
}


bool isPermit(const string &a, const string &b) {
  for(int i = rules.size()-1; i >= 0; --i) {
    if(isMatch(rules[i].a, a) && isMatch(rules[i].b, b)) {
      return rules[i].type == type_permit;
    }
  }
  return false;
}

int main() {
  while(cin >> N >> M && (N|M)) {
    rules.clear();
    for(int i = 0; i < N; ++i) {
      Rule r;
      string t;
      cin >> t >> r.a >> r.b;
      if(t == "permit") {
        r.type = type_permit;
      } else {
        r.type = type_deny;
      }
      rules.push_back(r);
    }

    vector<vector<string> > v;
    for(int i = 0; i < M; ++i) {
      string a, b, s;
      cin >> a >> b >> s;
      if(isPermit(a,b)) {
        vector<string> u(3);
        u[0] = a;
        u[1] = b;
        u[2] = s;
        v.push_back(u);
      }
    }

    cout << v.size() << endl;
    for(int i = 0; i < v.size(); ++i) {
      for(int j = 0; j < v[i].size(); ++j) {
        if(j) cout << " ";
        cout << v[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}