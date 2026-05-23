#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)


int main(){
  while(1){
    int n;
    cin>>n;
    if(n==0) break;
    int a[50];
    string memo;
    lp(i,n){
      cin>>memo;
      a[i]=memo.size();
    }
    lp(i,n){
      int ans=0;
      int count=0,stats=0;
      for(int j=i;j<n;j++){
	if(stats==0||stats==2){
	  count+=a[j];
	  if(count==5){
	    stats++;
	    count=0;
	  }
	  if(count>5) break;
	}
	else if(stats==1||stats==3||stats==4){
	  count+=a[j];
	  if(count==7){
	    stats++;
	    count=0;
	  }
	  if(count>7) break;
	}
	if(stats==5) {
	  ans=1;
	  break;
	}
      }
      if(ans==1) {
	cout<<i+1<<endl;
	break;
      }
    }
  }
  return 0;
}

