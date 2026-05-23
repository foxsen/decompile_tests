#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    long long x,y;

	
    cin  >> x >> y;
    if(x==y)cout << 1 << " " << 0 << endl;
    else if(x%2==0||y%2==0)cout << 1 << " " << 1 << endl;
    else {
      if(x>y)swap(x,y);
      if(y%x==0){
	y/=x;
	x/=x;
      }
      while(1){
	int f=0;
	for(int j=2;j*j<y;j++){
	  if(x%j==0&&y%j==0){
	    f=1;
	    x/=j;
	    y/=j;
	  }
	}
	if(f==0)break;
      }
      // cout << x << y << endl;
      cout << x*y/2+1 << " " << x*y/2<< endl;
    }
  }
  return 0;
  
}