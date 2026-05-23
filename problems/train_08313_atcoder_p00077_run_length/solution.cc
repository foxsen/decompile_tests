#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  while(getline(cin,s)) {
    string r;
    for(int i=0; i<s.length(); i++) {
      if(s[i] == '@')
	r += string(s[i+1]-'0',s[i+2]),i += 2;
      else
	r += string(1,s[i]);
    }
    cout<<r<<endl;
  }
}