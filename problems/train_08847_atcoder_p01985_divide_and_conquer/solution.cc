#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

int main(){
  while(1){
    int n,m;
    cin>>n>>m;
    if(n==0&&m==0) break;
    vector<int> road[1000];
    lp(i,n){
      road[i].clear();
    }
    lp(i,m){
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      road[a].push_back(b);
      road[b].push_back(a);
    }
    int ans[1000],anscount=0;
    lp(i,1000){
      ans[i]=0;
    }
    lp(i,n){
      int a[1000];
      lp(j,n){
	a[j]=0;
      }
      int result=0,act;
      a[i]=1;
      while(1){
	act=0;
	for(int j=0;j<n;j++){
	  if(a[j]==1){
	    for(int k=0;k<road[j].size();k++){
	      if(a[road[j][k]]==0){
		a[road[j][k]]=2;
		act=1;
	      }
	    }
	  }
	  if(a[j]==2){
	    for(int k=0;k<road[j].size();k++){
	      if(a[road[j][k]]==0){
		a[road[j][k]]=1;
		act=1;
	      }
	    }
	  }
	}
	if(act==0) break;
      }
      lp(i,n){
	for(int j=0;j<road[i].size();j++){
	  if(a[i]==a[road[i][j]]){
	    result=-1;
	    break;
	  }
	}
	if(result==-1) break;
      }
      if(result==0){
	int count=0;
	lp(i,n){
	  if(a[i]==1) count++;
	}
	if(count%2==0){
	  if(ans[count/2]==0){
	    ans[count/2]=1;
	    anscount++;
	  }
	}
      }
    }
    cout<<anscount<<endl;
    lp(i,500){
      if(ans[i]==1) cout<<i<<endl;
    }
  }
  return 0;
}
