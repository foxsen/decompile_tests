#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double t;
  cin>>n>>t;
  double a[n];
  for(int i=0;i<n;i++){
    double x,h;
    cin>>x>>h;
    a[i]=h/x;
    if(a[i]>=a[0]){
      a[0]=a[i];
    }
  }
  
  printf("%lf", a[0]*t);
  
  return 0;
}
   
 
      
 
  
   
  
	
	  
	  
	  
	  
	  
	  
     
  
  
  
  
  

  

 
  


 

    
  

