#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  int sum=0;
  for(int i=1;i<=N;i++){
  int A;
    cin>>A;
    if(A!=i)
      sum++;
  }
  if(sum<=2)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}