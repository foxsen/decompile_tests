#include <iostream>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  if(A[0]!=0){
    cout<<-1<<endl;
    return 0;
  }
  long long cnt=0;
  for(int i=1;i<N;i++){
    if(A[i]-A[i-1]>1){
      cout<<-1<<endl;
      return 0;
    }
    if(A[i]-A[i-1]==1){
      cnt++;
    }
    else{
      cnt+=A[i];
    }
  }
  cout<<cnt<<endl;

  return 0;
}

  