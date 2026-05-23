#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;

vector<string> split(string &str, char delim){
  stringstream ss(str);
  string tmp;
  vector<string> res;
  while(getline(ss, tmp, delim)) res.push_back(tmp);
  return res;
}

int main() {
  string s;
  while(getline(cin, s) && s != "END OF INPUT"){
    vector<string> ws = split(s, ' ');
    REP(i, ws.size()) cout <<ws[i].length();
    cout <<endl;
  }
  return 0;
}