#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
 
int N;
ll T[1001];
int main(){
 
  cin>>N;
  for(int i=0;i<N;i++)cin>>T[i];
  if(N==1)cout<<T[0]<<endl;
  else{
    sort(T,T+N);
    ll res=0;
    while(1){
      if(N==3){
        res+=T[0]+T[1]+T[2];
        break;
      }
      else if(N==2){
        res+=T[1];
        break;
      }
      else{
        if(T[1]*2-T[0]<T[N-2])res+=T[0]+2*T[1]+T[N-1];
        else res+=T[N-1]+2*T[0]+T[N-2];
        N-=2;
      }
    }
    cout<<res<<endl;
  }
   
  return 0;
}
