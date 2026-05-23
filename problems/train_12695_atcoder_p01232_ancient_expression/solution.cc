#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int OpeSize = 15;

struct data{
  char ope,dir;
};

vector<data> V[OpeSize];

void input(){

  for(int i = 0; i < OpeSize; i++) V[i].clear();

  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    char d;
    int num;
    cin >> d;
    cin >> num;
    while(num--){
      char ope;
      cin >> ope;
      V[i].push_back((data){ope,d});
    }
  }
}

bool isVar(const string& s){
  if(s.length() != 1) return false;
  return 'a' <= s[0] && s[0] <= 'z';
}

string rmPara(string s){
  if(s[0] != '(' || s[s.length()-1] != ')') return s;

  int p = 0;
  for(int i = 0; i < (int)s.length()-1; i++){
    if(s[i] == '(') p++;
    if(s[i] == ')') p--;
    if(p == 0) return s;
  }
  return s.substr(1,s.length()-2);
}

bool match(const vector<data>& v, const char c){
  for(int i = 0; i < (int)v.size(); i++)
    if(v[i].ope == c) return true;
  return false;
}

int find(const vector<data>& v, const string& s){
  int p = 0;

  if(v[0].dir == 'L'){
    for(int i = s.length()-1; i >= 0; i--){
      if(s[i] == '(') p++;
      if(s[i] == ')') p--;
      if(p == 0 && match(v,s[i])) return i;
    }
  }else{
    for(int i = 0; i < (int)s.length(); i++){
      if(s[i] == '(') p++;
      if(s[i] == ')') p--;
      if(p == 0 && match(v,s[i])) return i;
    }
  }
  return -1;
}

string parse(string s){

  s = rmPara(s);
 
  if(isVar(s)){
    return s;
  }else{
    //Expr Op Expr
    
    for(int i = 0; i < OpeSize; i++){
      if(V[i].empty()) continue;
      int pos = find(V[i],s);
      if(pos != -1){
	return "(" + parse(s.substr(0,pos)) + s[pos]  + parse(s.substr(pos+1)) + ")";
      }
    }
  }
  return parse(s);
}

int main(){
  
  int T;
  cin >> T;
  while(T--){
    input();
    int N;
    cin >> N;
    while(N--){
      string s;
      cin >> s;
      cout << parse(s) << endl;
    }
    if(T > 0) cout << endl;
  }
  return 0;
}