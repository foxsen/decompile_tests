#include<iostream>
#include<string>
using namespace std;
int main()
{
  int n,c;
  cin>>n;
  int max=0;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    if(a>max){
      max=a;
      c=a+b;
    }
  }
  cout<<c;
}
