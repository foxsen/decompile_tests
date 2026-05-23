#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>
#include <climits>
#include <deque>
#include <bitset>
#include <cassert>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int dy[]={-1,0,1,0},dx[]={0,1,0,-1};
// adjust problem by problem
const double EPS=1e-8;
const double PI=acos(-1.0);
#ifdef __GNUC__
int popcount(int n){return __builtin_popcount(n);}
int popcount(ll n){return __builtin_popcountll(n);}
#endif
#ifndef __GNUC__
template<class T> int popcount(T n){int cnt=0;while(n){if(n%2)cnt++;n/=2;}return cnt;}
#endif
template<class T>int SIZE(T a){return a.size();}
template<class T>string IntToString(T num){string res;stringstream ss;ss<<num;return ss.str();}
template<class T>T StringToInt(string str){T res=0;for(int i=0;i<SIZE(str);i++)res=(res*10+str[i]-'0');return res;}
template<class T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> void PrintSeq(T &a,int sz){for(int i=0;i<sz;i++){cout<<a[i];if(sz==i+1)cout<<endl;else cout<<' ';}}
bool EQ(double a,double b){return abs(a-b)<EPS;}
void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}
vector<string> split(string str,char del){
  vector<string> res;
  for(int i=0,s=0;i<SIZE(str);i++){
    if(str[i]==del){if(i-s!=0)res.push_back(str.substr(s,i-s));s=i+1;}
    else if(i==SIZE(str)-1){res.push_back(str.substr(s));}
  }
  return res;
}
typedef tuple<int,int,int> tpl;
int field[10][10];
int N;
tpl ans[20];

const int sx[]={0,-1,0,1,0};
const int sy[]={0,1,1,1,2};
const int mx[]={0,1,2,0,1,2,0,1,2};
const int my[]={0,0,0,1,1,1,2,2,2};
const int lx[]={0,-1,0,1,-2,-1,0,1,2,-1,0,1,0};
const int ly[]={0,1,1,1,2,2,2,2,2,3,3,3,4};
bool dp[13][201];

bool dfs(int pos,int cnt,int sum){
  int cx=pos%10;
  int cy=pos/10;
  if(pos==100){
    return (sum==0&&cnt==N);
  }
  else{
    if(field[cy][cx]==0)return dfs(pos+1,cnt,sum);
    else{
      if(cnt==N)return false;
      if((N-cnt)*5>sum)return false;
      if(!dp[cnt][sum])return false;
      int bk[10][10];
      for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
          bk[i][j]=field[i][j];
      // small
      {
        bool isOK=true;
        for(int i=0;i<5;i++){
          int ny=cy+sy[i];
          int nx=cx+sx[i];
          if(!(ny>=0&&nx>=0&&ny<10&&nx<10&&field[ny][nx]))
            isOK=false;
        }
        if(isOK){
          for(int i=0;i<5;i++){
            int ny=cy+sy[i];
            int nx=cx+sx[i];
            field[ny][nx]--;
          }
          ans[cnt]=tpl(cx,cy+1,1);
          if(sum-5>=0&&dfs(pos,cnt+1,sum-5))
            return true;
          for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
              field[i][j]=bk[i][j];
        }
      }
      // med
      {
        bool isOK=true;
        for(int i=0;i<9;i++){
          int ny=cy+my[i];
          int nx=cx+mx[i];
          if(!(ny>=0&&nx>=0&&ny<10&&nx<10&&field[ny][nx]))
            isOK=false;
        }
        if(isOK){
          for(int i=0;i<9;i++){
            int ny=cy+my[i];
            int nx=cx+mx[i];
            field[ny][nx]--;
          }
          ans[cnt]=tpl(cx+1,cy+1,2);
          if(sum-9>=0&&dfs(pos,cnt+1,sum-9))
            return true;
          for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
              field[i][j]=bk[i][j];
        }
      }
      // lrg
      {
        bool isOK=true;
        for(int i=0;i<13;i++){
          int ny=cy+ly[i];
          int nx=cx+lx[i];
          if(!(ny>=0&&nx>=0&&ny<10&&nx<10&&field[ny][nx]))
            isOK=false;
        }
        if(isOK){
          for(int i=0;i<13;i++){
            int ny=cy+ly[i];
            int nx=cx+lx[i];
            field[ny][nx]--;
          }
          ans[cnt]=tpl(cx,cy+2,3);
          if(sum-13>=0&&dfs(pos,cnt+1,sum-13))
            return true;
          for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
              field[i][j]=bk[i][j];
        }
      }
      //if(dfs(pos+1,cnt,sum))return true;
    }
  }
  return false;
}

int main(){
  int sum=0;
  cin>>N;
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      cin>>field[i][j],sum+=field[i][j];
  for(int i=N;i>=0;i--){
    for(int j=0;j<=200;j++){
      if(i==N)dp[i][j]=(j==0);
      else{
        dp[i][j]=false;
        if(j-5>=0)dp[i][j]|=dp[i+1][j-5];
        if(j-9>=0)dp[i][j]|=dp[i+1][j-9];
        if(j-13>=0)dp[i][j]|=dp[i+1][j-13];
      }
    }
  }
  if(!dfs(0,0,sum))cout<<"no"<<endl;
  for(int i=0;i<N;i++)
    cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<endl;
  
  return 0;
}