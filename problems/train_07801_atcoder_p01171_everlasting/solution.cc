//05
#include<iostream>

using namespace std;

int main(){
  static bool cmp[1000001]={true,true};
  for(int i=2;i<1000001;i++){
    if(!cmp[i]){
      for(int j=2;i*j<1000001;j++){
	cmp[i*j]=true;
      }
    }
  }
  for(int k[2];cin>>k[0]>>k[1],k[0]|k[1];){
    int r[2]={};
    for(int i=0;i<2;i++){
      bool m=false;
      for(int l=k[i];l>=2;l--){
	if(!cmp[l]&&k[i]%l==0){
	  r[i]+=(m)?-l:l;
	  m=true;
	}
      }
    }
    cout<<((r[0]>r[1])?'a':'b')<<endl;
  }
  return 0;
}