#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cassert>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
typedef pair<int,int> pii;
const int N = 10000;

void compute(int i,int *buf){
  buf[0]=i/1000%10;
  buf[1]=i/100%10;
  buf[2]=i/10%10;
  buf[3]=i%10;
}

pii hitAndBlow(int n,int q){
  int hit=0,blow=0;
  int buf1[5],buf2[5];
  compute(n,buf1);
  compute(q,buf2);
  rep(i,4){
    rep(j,4){
      if (buf1[i] == buf2[j]){
	if (i == j)hit++;
	else blow++;
      }
    }
  }
  return make_pair(hit,blow);
}

int solve(vector<int> &a){
  if (a.size() > 15)return -1;
  rep(i,N){
    int buf[5];
    bool isok=true;
    compute(i,buf);
    rep(j,4)REP(k,j+1,4)if (buf[j] == buf[k]){isok=false;}
    int cnt[5][5]={0};
    rep(j,a.size()){
      pii tmp = hitAndBlow(a[j],i);
      cnt[tmp.first][tmp.second]++;
      if (cnt[tmp.first][tmp.second] > 1)isok=false;
    }
    if (isok)return i;
  }
  return -1;
}

int main(){
  int n;
  while(cin>>n && n){
    vector<pii> in(n);
    vector<int> cand,query(n);
    rep(i,n)cin>>query[i]>>in[i].first>>in[i].second;
    rep(i,N){
      bool isok=true;
      int buf[5];
      compute(i,buf);
      rep(j,4)REP(k,j+1,4)if (buf[j] == buf[k]){isok=false;}
      rep(j,n){
	pii tmp =hitAndBlow(i,query[j]);
	if (tmp.first == in[j].first && tmp.second == in[j].second);
	else {
	  isok=false;
	}
      }
      if (isok)cand.push_back(i);
    }
    sort(cand.begin(),cand.end());
    int ans = cand.size() == 1?cand[0]:solve(cand);
    if (ans !=-1)printf("%04d\n",ans);
    else puts("????");
  }
  return false;
}