#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int A,B,C,X,Y,ans=0;
  cin >> A >> B >> C >> X >> Y;
  if(A+B<2*C){
    ans=X*A+Y*B;
  }else{
    ans=min(X,Y)*C*2+max(X-Y,0)*min(A,2*C)+max(Y-X,0)*min(B,2*C);
  }
  cout << ans << endl;
    
}