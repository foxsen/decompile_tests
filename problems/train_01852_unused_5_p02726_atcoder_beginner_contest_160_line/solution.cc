#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,X,Y;
  cin>>N>>X>>Y;
  X=X-1;
  Y=Y-1;
  int k=0;
  vector<int> V(N-1);
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      k=min(j-i,abs(X-i)+1+abs(Y-j));
      V.at(k-1)++;
    }
  }
  for(int i=0;i<N-1;i++){
    cout<<V.at(i)<<endl;
  }
}