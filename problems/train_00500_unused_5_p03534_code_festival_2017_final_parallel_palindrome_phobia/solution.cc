#include<bits/stdc++.h>
using namespace std;

int main(){
  int a=0,b=0,c=0;
  string S;
  cin>>S;
  int n = S.length();
  for(int i=0;i<n;i++){
    int val = S[i] - 'a';
    if(val==0) a++;
    if(val==1) b++;
    if(val==2) c++;
  }
  int ab = abs(a-b);
  int bc = abs(b-c);
  int ca = abs(c-a);
  if(ab<2 && bc<2 && ca<2){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
