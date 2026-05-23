#include <iostream>
#include <string>
using namespace std;
int main(){
string S;
  cin>>S;
int len,ans;
  ans=0;
  len=S.length();
for(int i=0;i<len;i++){
if(S[i]!=S[len-1-i]){ans++;}
} 
  cout<<ans/2;
}