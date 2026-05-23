#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

double prim(int n, vector< vector<double> > &G){
  double ans = 0.0;
  priority_queue< pair<double,int> > wait;
  bool connected[n];
  fill(connected,connected+n,false);
  wait.push(make_pair(0.0,0));
  while(!wait.empty()){
    double cost = -wait.top().first;
    int v = wait.top().second;
    wait.pop();
    if(connected[v]) continue;
    ans += cost;
    connected[v] = true;
    for(int i = 0; i < n; ++i){
      if(!connected[i]){
        wait.push(make_pair(-G[v][i],i));
      }
    }
  }
  return ans;
}

int main(){
  int n;
  while(cin >> n, n){
    double x[n], y[n], z[n], r[n];
    for(int i = 0; i < n; ++i){
      cin >> x[i] >> y[i] >> z[i] >> r[i];
    }
    vector< vector<double> > dist(n,vector<double>(n,0));
    
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        dist[i][j] = max(0.0,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]))-r[i]-r[j]);
      }
    }
    printf("%.3f\n",prim(n,dist));
  }
  return 0;
}