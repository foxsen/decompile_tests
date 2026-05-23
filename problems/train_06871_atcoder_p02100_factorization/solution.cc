#include<bits/stdc++.h>
using namespace std;
  
string s;

bool check(int x){
  
  long long p=0, value=0;
  
  while(p<s.size()){
    
    int num=0, flag=0;
    
    if(s[p]=='-') flag=1;
    if(s[p]!='x') p++;

    while('0'<=s[p]&&s[p]<='9') num=num*10+s[p++]-'0';
    
    if(num==0) num=1;
    
    if(flag) num*=-1;
    
    if(s[p+1]=='^') value+=num*pow(x,s[p+2]-'0'), p+=3;
    else value+=num*x, p++;
    
  }
  
  return value==0;
}

int main(){
  
  cin>>s;
  
  s+="x^0";
  
  for(int i=2000;i>=-2000;i--)
    if(check(i)){
      cout<<"(x";
      if(i<0) cout<<"+"<<i*(-1);
      else cout<<"-"<<i;
      cout<<")";
    }
  
  cout<<endl;
  
  return 0;
}