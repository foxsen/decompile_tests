#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string toString(int n){
  ostringstream os;
  os << n;
  return os.str();
}

int main(){
  int Q;
  string N;

  cin >> Q;
  while(Q--){
    cin >> N;  
    int i;
    for(i = 0 ; N.size() != 1 ; i++){
      int ans = -1;
      for(int j = 1 ; j < N.size() ; j++){
	string a = N.substr(0, j);
	string b = N.substr(j);
	ans = max(ans, atoi(a.c_str()) * atoi(b.c_str()));
      }
      N = toString(ans);
    }
    cout << i << endl;
  }
  return 0;
}  