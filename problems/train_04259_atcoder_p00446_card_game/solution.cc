#include<iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    if(n==0) break;
    int a[2*n+1],b;
    bool t = true;
    int tt = n,ht = n;
    for(int i=1;i<=2*n;i++) a[i] = 1;
    for(int i=0;i<n;i++){
      cin >> b;
      a[b] = 0;
    }
    while(tt!=0&&ht!=0){
      for(int i=1;i<=2*n;i++){
	if(t&&a[i]==0){
	  a[i] = 2;
	  tt--;
	  t = false;
	}
	else if(!t&&a[i]==1){
	  a[i] = 2;
	  ht--;
	  t = true;
	}
	if(tt==0||ht==0) break;
      }
      if(t) t = false;
      else t = true;
    }
    cout << ht << endl;
    cout << tt << endl;
  }
  return 0;
}