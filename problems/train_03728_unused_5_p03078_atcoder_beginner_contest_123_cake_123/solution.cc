#include<bits/stdc++.h>
using namespace std;
long X,Y,Z,K,i,j,k;
int main(){
  cin>>X>>Y>>Z>>K;
  vector<long> A(X),B(Y),C(Z),ABC;
  for(i=0;i<X;i++)cin>>A[i];
  for(i=0;i<Y;i++)cin>>B[i];
  for(i=0;i<Z;i++)cin>>C[i];
  sort(A.rbegin(),A.rend());
  sort(B.rbegin(),B.rend());
  sort(C.rbegin(),C.rend());
  for(i=0;i<X;i++){
    for(j=0;j<Y;j++){
      for(k=0;k<Z;k++){
        if((i+1)*(j+1)*(k+1)>K)break;
        ABC.push_back(A[i]+B[j]+C[k]);
      }
    }
  }
  sort(ABC.rbegin(),ABC.rend());
  for(i=0;i<K;i++)cout<<ABC[i]<<endl;
}
