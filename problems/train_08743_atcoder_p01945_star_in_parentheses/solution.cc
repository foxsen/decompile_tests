#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
typedef long long int ll;

int main(){
  string s;
  cin>>s;
  stack<int> a;
  a.push(0);
  int b=1;
  for(int i=0;i<s.size();i++){
    if(s[i]=='('){a.push(b);b++;}
    else if(s[i]==')'){b=a.top();a.pop();}
    else {cout<<a.top()<<endl;return 0;}
  }
  return 0;
}

