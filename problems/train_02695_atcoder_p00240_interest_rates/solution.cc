#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int n;
  int y;
  int b[55];
  int r[55];
  int t[55];
  int max;
  int ans; 
  double q;
  while(true){
    cin>>n;
    if(n==0)break;
    cin>>y;
   max=0;
    for(int i=0;i<n;i++){
      cin>>b[i];
      cin>>r[b[i]]>>t[b[i]];
      if(t[b[i]]==1){
	q=100+y*r[b[i]];
     }
      else{
	double in = 100+r[b[i]];
	q=in;
     	for(int s=0;s<y-1;s++){
	  q*=in;
	}
    	for(int s=0;s<y-1;s++){
	  q/=100;
	}

     }
      if(max<q){
	max=q;
	ans=b[i];
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}