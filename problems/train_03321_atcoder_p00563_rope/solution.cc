#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 1000100

/* RangeMinimumQuery(0-index) */

struct RMQ{
  typedef int Type;
  int segn2;
  Type inf;
  vector<Type> data;
  
  RMQ(int n){
    inf = INF; //init value
    for(segn2=1;segn2<n;segn2*=2);
    data.assign(segn2*2,inf);
  }
  
  //get minimum value [a,b]
  Type query(int a,int b,int l=0,int r=-1,int k=0){
    if(r==-1) r+=segn2;
    if(a<=l && r<=b) return data[k];
    if(r<a || b<l) return inf;
    return min(query(a,b,l,(l+r)/2,k*2+1),query(a,b,(l+r)/2+1,r,k*2+2));
  }
  
  //set kth number x
  void set(int k,Type x){
    k+=segn2-1;
    data[k]=x;
    while(k>0){
      k=(k-1)/2;
      data[k]=min(data[k*2+1],data[k*2+2]);
    }
    return;
  }
};

int n,m;
int c[SIZE];

int ans[SIZE];
vector<int> vec[SIZE];
int rest[SIZE];

RMQ rmq(SIZE);

void calc(int mode){
  
  c[n] = -1;
  
  for(int i=0;i<m;i++){
    rest[i] = n - vec[i].size();
    rmq.set(i, rest[i]);
  }

  for(int i=0;i<m;i++){
    int minus_sum = 0;

    for(int j=0;j<(int)vec[i].size();j++){
      int a = (vec[i][j]-mode)/2*2+mode; //c[a] == i
      int b = a; //c[b] != i

      if((mode == 0 && n%2 == 1 && vec[i][j]==n-1) ||
         (mode == 1 && (vec[i][j]==0 || (n%2==0 && vec[i][j]==n-1)))){
        minus_sum++;
        continue;
      }

      if(c[a] == i) b++;
      else a++;
      
      if(c[a] == c[b]){
        if(a == vec[i][j]) minus_sum+=2;
        continue;
      }

      minus_sum++;
      rest[c[b]]++;
      rmq.set(c[b], rest[c[b]]);
      /*
      debug(b);
      debug(c[b]);
      debug(mode);
      debug(vec[i][j]);
      */
    }
    
    int this_ans = min(rmq.query(-INF,i-1),rmq.query(i+1,m)) - minus_sum;

    ans[i] = min(ans[i], this_ans);

    //cerr << mode << " " << i << " : " << this_ans << " (" << minus_sum << ")" << endl;

    for(int j=0;j<(int)vec[i].size();j++){
      int a = (vec[i][j]-mode)/2*2+mode; //c[a] == i
      int b = a; //c[b] != i

      if((mode == 0 && n%2 == 1 && vec[i][j]==n-1) ||
         (mode == 1 && (vec[i][j]==0 || (n%2==0 && vec[i][j]==n-1)))){
        continue;
      }

      if(c[a] == i) b++;
      else a++;
      
      if(c[a] == c[b]){
        continue;
      }

      rest[c[b]]--;
      rmq.set(c[b], rest[c[b]]);
    }
     
  }

}
  
  

int main(){

  scanf("%d%d",&n,&m);
  
  if(m == 1){
    puts("0");
    return 0;
  }

  for(int i=0;i<m;i++){
    ans[i] = INF;
  }
  
  for(int i=0;i<n;i++){
    scanf("%d",c+i);
    c[i]--;
  }
 
  for(int i=0;i<n;i++){
    vec[c[i]].push_back(i);
  }
  
  // |1 2|3 4|5 6|7 ...

  calc(0);
  calc(1);

  for(int i=0;i<m;i++){
    printf("%d\n",ans[i]);
  }
  
  return 0;
}