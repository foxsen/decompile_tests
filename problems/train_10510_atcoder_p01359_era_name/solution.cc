#include<iostream>
#define N 1000
using namespace std;

int main(){
  while(1){
    int n,q,e[N],w[N],que,f;
    string str[N];
    cin>>n>>q;
    if(n+q==0) break;
    for(int i=0;i<n;i++)cin>>str[i]>>e[i]>>w[i];
    for(int i=0;i<q;i++){
      cin>>que,f=0;
      for(int j=0;j<n;j++)if(e[j]-(w[j]-que)>0 && e[j]-(w[j]-que)<=e[j]) cout<<str[j]<<" "<<e[j]-(w[j]-que)<<endl,f=1;
      if(!f) cout<<"Unknown"<<endl;
    }
  }
  return 0;
}