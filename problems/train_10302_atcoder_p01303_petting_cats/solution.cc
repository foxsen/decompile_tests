#include <iostream>
using namespace std;

int main(){
     int T;
     cin>>T;

     for(int t1=0;t1<T;t1++){
	  int x,y,w,h;
	  cin>>x>>y>>w>>h;

	  int N,ans=0;
	  cin>>N;
	  for(int i=0;i<N;i++){
	       int nx,ny;
	       cin>>nx>>ny;

	       if(nx>=x&&ny>=y&&nx<=x+w&&ny<=y+h)++ans;
	  }
	  cout<<ans<<endl;
     }
     return 0;
}