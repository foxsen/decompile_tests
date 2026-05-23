#include<bits/stdc++.h>
using namespace std;
int a[10];
int num[10];
int cnt;
bool flag(){
  for(int i=0;i<9;i++){
    if(a[i]==-1) return false;
  }
  return true;
}
void dfs(int k){
  for(int i=k;i<9;i++){
    if(a[i]==-1){
      for(int j=1;j<10;j++){
	if(num[j]==0){
	  a[i]=j;
	  num[j]=1;
	  dfs(i);
	  num[j]=0;
	  a[i]=-1;
	}
      }
    }
    if(i==8 && flag()){
      if(a[0]+a[1]*10+a[2]+a[3]*100+a[4]*10+a[5]==a[6]*100+a[7]*10+a[8]){
	//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<" "<<a[6]<<" "<<a[7]<<" "<<a[8]<<endl;
	cnt++;
      }
    }
  }
}
      
int main(){
  for(int i=0;i<9;i++){
    cin>>a[i];
    num[a[i]]=1;
  }
  dfs(0);
  cout<<cnt<<endl;
  return 0;
}
  
  

