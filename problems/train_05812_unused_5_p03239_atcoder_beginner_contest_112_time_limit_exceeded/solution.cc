using namespace std;
#include<iostream>

int main(){
 int n,tl,c,t,cm=1001;
  cin>>n>>tl;
  for(int i=0;i<n;i++){
    cin>>c>>t;
    if(c<cm && t<=tl)cm=c;
  }
  if(cm>1000)cout<<"TLE"<<endl;
  else cout <<cm<<endl;
  return 0;
}
  