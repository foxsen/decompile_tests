#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

int win[1000010][20];
string S;

int winner(int x,int y){
    if(x<y){
        if(S[y-x-1]=='0') return x;
        else return y;
    }else{
        if(S[x-y-1]=='0') return y;
        else return x;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin>>N;
  cin>>S;
  int M=pow(2,N);
  vector<int> P(M);
  rep(i,M) cin>>P[i];

  vector<int> A(2*M);
  rep(i,2*M) A[i]=P[i%M];

  for(int i=0;i<2*M;i++) win[i][0]=A[i];

  for(int k=1;k<=N;k++){
      for(int j=0;j+k-1<2*M;j++){
          int rig=j+(1<<(k-1));
          win[j][k]=winner(win[j][k-1],win[rig][k-1]);
      }
  }

  for(int i=0;i<M;i++) cout<<win[i][N]<<"\n";

  return 0;
}

