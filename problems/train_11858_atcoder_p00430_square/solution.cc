#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int a[31];
int f(int n){
  if(n){
    for(int i=n;i>0;--i){
      if(s.empty()||s.top()>=i){
	s.push(i);f(n-i);s.pop();
      }
    }
  }
  else{
    if(!s.empty()){
      stack<int> t(s);
      int b=t.size();
      for(int i=b-1;i>=0;--i){
	a[i]=t.top();t.pop();
      }
      cout<<a[0];
      for(int i=1;i<b;++i) cout<<' '<<a[i];
      cout<<endl;
    }
  }
  return 0;
}
int main(){
  int n;
  while(cin>>n,n){
    f(n);
  }
  return 0;
}