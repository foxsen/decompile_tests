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
#define SIZE 100010

/* Point (x,y)*/
struct P{
  typedef double Type;
  
  Type x,y;
  
  P(Type X,Type Y){
    x = X;
    y = Y;
  }
  
  bool operator< (const P &B) const{
    return x==B.x ? y < B.y : x < B.x;
  }
  
};

/* ConvexHull(??????) */

bool ccw(P &base,P &A,P &B){
  //??´???????????????????????????
  return (A.x-base.x)*(B.y-base.y) - (A.y-base.y)*(B.x-base.x) >= 0; //double?????? -EPS
  
  //??´?????????????????????
  //return (A.x-base.x)*(B.y-base.y) - (A.y-base.y)*(B.x-base.x) > 0; //double?????? EPS
}

vector<P> ConvexHull(vector<P> s){
  vector<P> g;
  int n = (int)s.size();
  
  if(n<3) return s;
  
  sort(s.begin(),s.end());
  
  for(int i=0;i<n;i++){
    for(int m = (int)g.size();m>=2 && ccw(g[m-2],g[m-1],s[i]); m--){
      g.pop_back();
    }
    g.push_back(s[i]);
  }
  
  int t = (int)g.size();
  
  for(int i=n-2;i>=0;i--){
    for(int m = (int)g.size();m>t && ccw(g[m-2],g[m-1],s[i]); m--){
      g.pop_back();
    }
    g.push_back(s[i]);
  }
  
  reverse(g.begin(),g.end());
  g.pop_back();
  
  return g;
}


int main(){
  int n;
  int t[SIZE],d[SIZE];
  int y[SIZE],x[SIZE];
  bool s[SIZE][4] = {};
  vector<P> vec;
  
  scanf("%d",&n);

  y[0] = x[0] = 0;
  

  int dx[4] = {-1,0,1,0};
  int dy[4] = {0,1,0,-1};
  
  for(int i=1;i<n;i++){
    scanf("%d%d",t+i,d+i);

    x[i] = x[t[i]]+dx[d[i]];
    y[i] = y[t[i]]+dy[d[i]];
    s[t[i]][d[i]] = true;
  }

  for(int i=0;i<n;i++){
    vec.push_back(P(y[i],x[i]));
    vec.push_back(P(y[i],x[i]+1));
    vec.push_back(P(y[i]-1,x[i]+1));
    vec.push_back(P(y[i]-1,x[i]));
  }

  vec = ConvexHull(vec);
  
  double ans = LLINF;
  vector<double> theta;

  for(int i=0;i<vec.size();i++){
    theta.push_back(atan((vec[i].y-vec[(i+1)%vec.size()].y)/(vec[i].x-vec[(i+1)%vec.size()].x)));
  }
  theta.push_back(0);
  theta.push_back(M_PI/2);
  
  for(int i=0;i<theta.size();i++){
    double max_y = -INF;
    double max_x = -INF;
    double min_y = INF;
    double min_x = INF;
    
    for(int j=0;j<vec.size();j++){
      
      double x2 = vec[j].y*cos(theta[i])-vec[j].x*sin(theta[i]);
      double y2 = vec[j].y*sin(theta[i])+vec[j].x*cos(theta[i]);
      
      max_y = max(max_y,y2);
      max_x = max(max_x,x2);
      min_y = min(min_y,y2);
      min_x = min(min_x,x2);
      
    }

    ans = min(ans, (max_y-min_y)*(max_x-min_x));
  }

  printf("%.10lf\n",ans);
  
  return 0;
}