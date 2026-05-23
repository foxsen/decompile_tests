#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
# define  ll   long long
using namespace std;

ll gcd(ll x,ll y){
  return y==0 ? x: gcd(y,x%y);
}

ll getSum(ll x){
   ll s = 0;
   while(x>0){
     s += x % 10;
     x /= 10;
  }
  return s;
}

int main(){

   int t;
   scanf("%d",&t);
   while(t--){
      ll x;
      scanf("%lld",&x);
      while(gcd(x,getSum(x))==1) x++;
      printf("%lld\n",x);

   }
  return 0;
}