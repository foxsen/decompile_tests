#include <bits/stdc++.h>
using namespace std;
 
typedef long long lli;
 
const lli mod = 1000000007LL;
 
string s;
int p;
 
pair<lli,lli> exp();
pair<lli,lli> term();
pair<lli,lli> fact();
 
pair<lli,lli> exp() {
  pair<lli,lli> x = term();
  lli all = (x.first + x.second) % mod;
  lli f = x.second;
  while(s[p] == '|') {
    ++p;
    x = term();
    all = (all * (x.first+x.second)) % mod;
    f = (f * x.second) % mod;
  }
  return make_pair(((all - f) % mod + mod) % mod, f);
}
 
pair<lli,lli> term() {
  pair<lli,lli> x = fact();
  lli all = (x.first + x.second) % mod;
  lli f = x.first;
  while(s[p] == '&') {
    ++p;
    x = fact();
    all = (all * (x.first+x.second)) % mod;
    f = (f * x.first) % mod;
  }
  return make_pair(f, ((all - f) % mod + mod) % mod);
}

pair<lli,lli> fact() {
  if(s[p] == '(') {
    ++p;
    pair<lli,lli> x = exp();
    ++p;
    return x;
  } else if(s[p] == '~') {
    int cnt = 0;
    while(s[p] == '~') {
      ++cnt;
      ++p;
    }
    pair<lli,lli> x = fact();
    if(cnt & 1) swap(x.first, x.second);
    return x;
  } else if(s[p] == 'x') {
    ++p;
    while(isdigit(s[p])) ++p;
    return make_pair(1LL, 1LL);
  } else {
    //assert(false);
  }
}

string erase(string s) {
  int n = s.size();
  vector<int> use(n, 1);
  stack<pair<int,vector<int> > > pos;
  for(int i = 0; i < n; ++i) {
    if(s[i] == '(') {
      vector<int> v(3,0);
      pos.push(make_pair(i, v));
    } else if(s[i] == ')') {
      int k = pos.top().first;
      vector<int> v = pos.top().second;
      pos.pop();
      if(v[0] == 0 && v[1] == 0 && v[2] == 0) {
        use[i] = use[k] = 0;
      }
    } else {
      if(!pos.empty()) {
        pos.top().second[0] += s[i] == '|';
        pos.top().second[1] += s[i] == '&';
        pos.top().second[2] += s[i] == '~';
      }
    }
  }
  string t;
  for(int i = 0; i < n; ++i) {
    if(use[i]) t += s[i];
  }
  return t;
}
 
int main() {
  cin >> s;
  s = erase(s);
  s += "$";
  p = 0;
  cout << exp().first << endl;
  return 0;
}