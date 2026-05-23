#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> dic;
string In;
char num[256];

int ind[1000];
int p;

void make() {
  num['a'] = num['b'] = num['c'] = '2';
  num['d'] = num['e'] = num['f'] = '3';
  num['g'] = num['h'] = num['i'] = '4';
  num['j'] = num['k'] = num['l'] = '5';
  num['m'] = num['n'] = num['o'] = '6';
  num['p'] = num['q'] = num['r'] = num['s'] = '7';
  num['t'] = num['u'] = num['v'] = '8';
  num['w'] = num['x'] = num['y'] = num['z'] = '9';
}

bool solve(int pos) {
  if(pos == In.size()) {
    for(int i = 0; i < p; ++i) {
      if(i != 0) cout << " ";
      cout << dic[ind[i]];
    }
    cout << "." << endl;
    return true;
  }
  for(int i = 0; i < dic.size(); ++i) {
    bool flag = true;
    for(int j = 0; j < dic[i].size(); ++j) {
      if(pos+j >= In.size() || num[dic[i][j]] != In[pos+j]) {
	flag = false;
	break;
      }
    }
    if(flag) {
      ind[p++] = i;
      solve(pos+dic[i].size());
      --p;
    }
  }
  return false;
}

int main() {
  make();
  int N;
  while(cin >> N && N) {
    dic.clear();
    for(int i = 0; i < N; ++i) {
      string str;
      cin >> str;
      dic.push_back(str);
    }
    cin >> In;
    p = 0;
    solve(0);
    cout << "--" << endl;
  }
}