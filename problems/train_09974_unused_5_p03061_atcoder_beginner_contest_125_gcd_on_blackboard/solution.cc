#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
  int r;
  while((r=x%y)!=0){x=y; y=r;}
  return y;
}

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++)cin >> A[i];
  sort(A.begin(),A.end());
  for(int i=A[1];i>=1;i--){
    int cnt=0; bool q=true;
    for(int j=0;j<N;j++){
      if(A[j]%i!=0){cnt++;}
      if(cnt>=2){q=false; break;}
    }
    if(q){cout << i << endl; return 0;}
  }
}