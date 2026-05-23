#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
int N;
string S;


string::iterator CountSeqStr(string::iterator start, string *s, int *n){
  *s = *start;
  *n = 0;
  string tmp;
  for(;tmp = *start, tmp == *s && start != S.end(); ++start){
    (*n)++;
  }
  return --start;
}

string F(){
  string retS;
  string s;
  string::iterator it;
  int n;
  for(it= S.begin(); it != S.end(); ++it){
    it = CountSeqStr(it, &s, &n);
    char strn[10000];
    sprintf(strn, "%d", n);
    retS.append(string(strn));
    retS.append(s);
  }
  return retS;
}


int main(){
  while(cin >> N && N){
    cin >> S;
    for(int i=0; i<N; i++){
      string tmp;
      S = F();
    }
    cout << S << endl;
  }
  return 0;
}