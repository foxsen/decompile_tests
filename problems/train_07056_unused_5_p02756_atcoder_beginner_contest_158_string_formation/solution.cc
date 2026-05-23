#include <bits/stdc++.h>
using namespace std;

int main(){
string s,t,u,v;  
int64_t a,b,c,d;
b=0;
cin>>s>>a;
for(int64_t i=0;i<a;i++){
   cin>>c;
  if(c==1){b++;}
  if(c==2){
    cin>>d>>t;
    if((b+d)%2==1){u=t+u;}
    else{v=v+t;}
  }
}
if(b%2==0){cout<<u+s+v<<endl;}
else{
  for(int64_t i=0;i<v.size();i++){
    cout<<v.at(v.size()-1-i);
  }
  for(int64_t i=0;i<s.size();i++){
    cout<<s.at(s.size()-1-i);
  }
  for(int64_t i=0;i<u.size();i++){
    cout<<u.at(u.size()-1-i);
  }
  cout<<endl;
  }
}