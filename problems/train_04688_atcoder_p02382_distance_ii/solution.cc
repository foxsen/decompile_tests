#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
  int n;
  double x[100];
  double y[100];
  double p1=0,p2=0,p3=0,pi=0;

  cin>>n;

  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<n;i++) cin>>y[i];

  for(int i=0;i<n;i++){
    p1+=abs(x[i]-y[i]);
  }

  for(int i=0;i<n;i++){
    p2+=(x[i]-y[i])*(x[i]-y[i]);
  }
  p2=sqrt(p2);

  for(int i=0;i<n;i++){
    p3+=(x[i]-y[i])*(x[i]-y[i])*(abs(x[i]-y[i]));
  }
  p3=pow(p3,1.0/3.0);

 for(int i=0;i<n;i++){
   pi=max(abs(x[i]-y[i]),pi);
  }

 printf("%.6f\n%.6f\n%.6f\n%.6f\n",p1,p2,p3,pi);
}