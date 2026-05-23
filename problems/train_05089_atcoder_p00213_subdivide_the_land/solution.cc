//58
#include<iostream>
#include<algorithm>

using namespace std;

int x,y,n;
int a[16];
int g[10][10];

int dfs(int (*c)[10],bool (*u)[10]){
  /*
    for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
      cout<<c[i][j];
    }
    cout<<endl;
  }
  cout<<"---"<<endl;
  */
  int s=0;
  for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
      if(u[i][j]==false){
	for(int h=0;i+h<y;h++){
	  int cn=0,ci;
	  for(int w=0;j+w<x;w++){
	    for(int ch=0;ch<=h;ch++){
	      if(c[i+ch][j+w]){
		cn++;
		ci=c[i+ch][j+w];
	      }
	    }
	    if(cn==1){
	      if((h+1)*(w+1)==a[ci]){
		int n[10][10];
		copy(c[0],c[10],n[0]);
		bool nu[10][10];
		copy(u[0],u[10],nu[0]);
		for(int ii=i;ii<i+h+1;ii++){
		  for(int jj=j;jj<j+w+1;jj++){
		    n[ii][jj]=ci;
		    nu[ii][jj]=true;
		  }
		}
		s+=dfs(n,nu);
		break;
	      }
	    }
	    if(cn>1){
	      break;
	    }
	  }
	}
	return s;
      }
    }
  }
  copy(c[0],c[10],g[0]);
  return 1;
}
	      
	    

int main(){
  while(cin>>x>>y>>n,x|y|n){
    for(int i=0;i<n;i++){
      int b,k;
      cin>>b>>k;
      a[b]=k;
    }
    for(int i=0;i<y;i++){
      for(int j=0;j<x;j++){
	cin>>g[i][j];
      }
    }
    int c[10][10];
    copy(g[0],g[10],c[0]);
    bool u[10][10]={};
    if(dfs(c,u)==1){
      for(int i=0;i<y;i++){
	for(int j=0;j<x;j++){
	  cout<<g[i][j]<<((j==x-1)?'\n':' ');
	}
      }
    }else{
      cout<<"NA"<<endl;
    }
  }
  return 0;
}