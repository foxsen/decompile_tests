#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
  int H,W,cnt=0,nx,ny;
  queue<pair<int,int>> q;
  pair<int,int> p;
  cin>>H>>W;
  vector<vector<int>> A(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      char cha;
      cin>>cha;
      if(cha=='#'){
        A[i][j]=0;
        q.push(pair<int,int>(i,j));
      }
      else A[i][j]=INF;
    }
  }
  while(q.size()){
    pair<int,int> P=q.front();
    q.pop();
    for(int k=0;k<4;k++){
      nx=P.second+dx[k],ny=P.first+dy[k];
      if(0<=nx&&nx<W&&0<=ny&&ny<H&&A[ny][nx]==INF){
        A[ny][nx]=A[P.first][P.second]+1;
        cnt=A[ny][nx];
        q.push(pair<int,int>(ny,nx));
      }
    }
  }
  cout<<cnt<<endl;
}
