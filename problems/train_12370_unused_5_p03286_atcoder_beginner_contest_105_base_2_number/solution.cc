#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n;
  if(!n){cout<<0;return 0;}
  while(n){
    if(n%2){s="1"+s;n--;}
    else s="0"+s;
    n/=(-2);
  }
  cout<<s;
}