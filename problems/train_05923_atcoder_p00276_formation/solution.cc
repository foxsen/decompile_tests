#include<bits/stdc++.h>
using namespace std;
signed main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  long long Q,team=0,C,A,N;
  cin>>Q;
  for(int i=0;i<Q;i++){
    cin>>C>>A>>N;
    while(true){
      if(C>0 && A>0 && N>0){
	team++;
	C--;
	A--;
	N--;
	continue;
      }
      else if(C>=2 && A>=1){
	team++;
	C-=2;
	A--;
	continue;
      }
      else if(C>=3){
	team++;
	C-=3;
	continue;
      }
      else{
	cout<<team<<'\n';
	team=0;
	break;
      }
    }
  }
  return(0);
}

