#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  long long n;
  long long t[50];

  t[0] = 0;
  for(int i=1;i<=30;i++){
    t[i] = t[i-1]*3+1LL;
  }

  while(scanf("%lld",&n)!=EOF){
    if(n<=0){
      printf("0\n");
      continue;
    }
    if(n==1){
      printf("1\n");
      continue;
    }
    if(n&1)printf("%lld\n",1LL + 4LL*t[n/2]);
    else printf("%lld\n",1LL + 3LL*t[n/2-1] + t[n/2]);
  }
}