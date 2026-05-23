#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int i=1,s=1;
  while(s!=0){
    s=(i*n)%360;
    i++;
  }
  
  cout<<i-1;
  return 0;
}
