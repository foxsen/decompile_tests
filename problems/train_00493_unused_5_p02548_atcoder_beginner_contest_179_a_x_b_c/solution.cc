#include<iostream>
using namespace std;
int main(){
int n;
  int count=0;
  cin>>n;
  for(int a=1;a<=n-1;a++){
  for(int b=1;b<=(n-1)/a;b++){
  count++;
  }
  }
  cout<<count;
}
