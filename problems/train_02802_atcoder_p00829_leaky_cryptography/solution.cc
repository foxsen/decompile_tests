#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
void hex(LL n){
  if(n/16) hex(n/16);
  LL las=n%16;
  if(las<10) cout << char(las+'0');
  else cout << char(las-10+'a');
}
LL solve(void){
  vector<string> ins(9);
  REP(i,9) cin >> ins[i];
  vector<int> cs(9,0);
  REP(i,9){
    REP(k,ins[i].size()){
      int j=ins[i].size()-1-k;
      if('0'<=ins[i][j] && ins[i][j]<='9') ins[i][j]-='0';
      else {
	ins[i][j]=ins[i][j]-'a'+10;
      }
      REP(l,4) if(ins[i][j]&(1<<l)) cs[i]=(cs[i]|(1<<(l+k*4)));
      
    }
  }
  LL answer=0;
  int carry=0;
  REP(i,32){
    int pari=0;
    REP(j,8) if(cs[j]&(1<<i)) ++pari;
    if(carry&(1<<i)) ++pari;
    if(((cs[8]>>i)&1)!=(pari&1)){
      if(carry&(1<<i)) pari-=2;
      pari=8-pari;
      answer+=(1ll<<i);
    }
    carry+=((pari/2)<<(i+1));
  }
  return answer;
};

int main(void)
{
  int n;
  cin >> n;
  REP(i,n){
    hex(solve());
    cout << endl;
  }
  return 0;
}