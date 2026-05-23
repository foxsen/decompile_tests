#include<iostream>
using namespace std;

int main(){

  int h[5];
  int f[4];

  while(1){
    for(int i=0;i<4;i++) f[i]=0;
    for(int i=0;i<5;i++){
      cin>>h[i];
      if(h[i]==0) break;
      f[h[i]]=1;
    }
    if(h[0]==0) break;

    int x[2], cnt=0;
    for(int i=1;i<4;i++){
      if(f[i]==1)
	x[cnt++]=i;
      //cout<<i<<" "<<f[i]<<endl;
    }
    //cout<<"    "<<cnt<<" "<<x<<endl;
    if(cnt==2){
      if(x[0]==1&&x[1]==2){
	for(int i=0;i<5;i++){
	  if(h[i]==1) cout<<1<<endl;
	  else cout<<2<<endl;
	}
      }
      if(x[0]==1&&x[1]==3){
	for(int i=0;i<5;i++){
	  if(h[i]==1) cout<<2<<endl;
	  else cout<<1<<endl;
	}
      }
      if(x[0]==2&&x[1]==3){
	for(int i=0;i<5;i++){
	  if(h[i]==2) cout<<1<<endl;
	  else cout<<2<<endl;
	}
      }
    }else{
      for(int i=0;i<5;i++) cout<<3<<endl;
    }
  }
  
  return 0;
}