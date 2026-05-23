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

/*
  今見ている行の縦の引き方と左側の引き方を覚えておくDP
 */
// 2bit単位で１つのgridの情報を表す
const int mod=100000007;
map<int,int> dp[101][3];
int H,W;
char field[101][101];

int getVal(int pos,int mask){
  return ((mask>>(pos*2))&1)+((mask>>(pos*2+1))&1)*2;
}
int insertVal(int pos,int mask,int val){
  int a[2]={val%2,val/2};
  int resMask=mask;
  for(int i=0;i<2;i++)
    if(a[i]==1)resMask|=(1<<(pos*2+i));
    else resMask&=~(1<<(pos*2+i));
  return resMask;
}

int dfs(int pos,int mask,int left){
  int cy=pos/W,cx=pos%W;
  if(pos==H*W)return 1;
  if(dp[pos][left].count(mask)>0)
    return dp[pos][left][mask];
  ll res=0;
  int num=field[cy][cx]-'0';
  // 一つ前のmaskの値を取り出す
  int up=getVal(cx,mask);
  int cnt=up+left;
  if(num==0){
    if(cx==W-1&&left!=0)return 0;
    if(cy==H-1&&up!=0)return 0;
    if(up!=0&&left!=0)return 0;
    else if(up!=0){
      int nmask=insertVal(cx,mask,up);
      res+=dfs(pos+1,nmask,0);
      res%=mod;
    }
    else if(left!=0){
      int nmask=insertVal(cx,mask,0);
      res+=dfs(pos+1,nmask,left);
      res%=mod;
    }
    else{
      int nmask=insertVal(cx,mask,0);
      res+=dfs(pos+1,nmask,0);
      res%=mod;
    }
  }
  else{
    for(int down=0;down<=2;down++){
      for(int right=0;right<=2;right++){
        if(cx==W-1&&right!=0)continue;
        if(down+right+cnt!=num)continue;
        if(cy==H-1&&down!=0)continue;
        int nmask=insertVal(cx,mask,down);
        res+=dfs(pos+1,nmask,right);
        res%=mod;
      }
    }
  }
  return dp[pos][left][mask]=res;
}

int main(){
  cin>>H>>W;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>field[i][j];
      if(field[i][j]=='.')field[i][j]='0';
    }
  }
  cout<<dfs(0,0,0)<<endl;
  return 0;
}