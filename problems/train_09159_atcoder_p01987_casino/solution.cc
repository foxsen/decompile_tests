//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

typedef long double ld;
typedef long long ll;
ld dice[23][23*6];

struct Mat{
  ld val[2][2];
  
  Mat operator* (const Mat &b) const{
    Mat res;
    
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        res.val[i][j] = 0;
        for(int k=0;k<2;k++)
          res.val[i][j] += val[i][k] * b.val[k][j];
      }
    }

    return res;
  }
};

ld pow(ld X, ld Y, ld q, ll n){
  Mat t = {X, Y, 0, 1};
  Mat res = {1,0,0,1};
  
  while(n){
    if(n%2) res = res * t;
    t = t*t;
    n/=2;
  }

  return q * res.val[0][0] + res.val[0][1]; 
}

bool solve(){
  ll n, m;
  
  scanf("%lld%lld", &n, &m);
  if(n == 0) return false;
  
  ld q = 0; ll i = 0;

  while(i < m){
    ll l = i+1, r = m;
    ld X = 0, Y = 0;
    
    for(int j=0;j<=n*6;j++){
      if(j <= q) X += dice[n][j];
      else Y += dice[n][j] * j;
    }
    
    while(l<r){
      ll mid = (l+r)/2;
      
      if(pow(X, Y, q, mid-i) >= floor(q) + 1){
        r = mid;
      }else{
        l = mid + 1;
      }
    }
    
    q = pow(X, Y, q, l-i);
    i = l;
  }

  printf("%.5Lf\n", q);
  
  return true;
}



int main(){
  dice[0][0] = 1;

  for(int i=0;i<20;i++){
    for(int j=0;j<=i*6;j++){
      for(int k=1;k<=6;k++)
        dice[i+1][j+k] += dice[i][j] / 6;
    }
  }
  
  while(solve());
}


