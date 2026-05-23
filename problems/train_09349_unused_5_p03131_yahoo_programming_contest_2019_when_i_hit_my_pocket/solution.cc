#include <iostream>

using namespace std;

int main(){
  long int K,A,B;
  cin>>K>>A>>B;

  if(B-A<=2){
    cout<<K+1<<endl;
  }else{
    cout<<K+1+(B-A-2)*((K-A+1)/2)<<endl;
  }
  return 0;
}