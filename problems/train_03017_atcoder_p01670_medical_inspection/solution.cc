#include<iostream>
#include<bitset>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

typedef bitset<300000/10> BS;

BS absbs;
BS is[3000];
vector<int> idx;
int a[32345],b[32345];

int rec(const BS &bs,int nth,int r){
  if(r<0)return r;
  if(bs==absbs)return r;
  while((is[idx[nth]]&~bs).none()){
    nth++;
  }
  BS n=is[idx[nth]]&~bs;
  if(n.count()==1){
    for(int i=0;;i++){
      if(n[i]){
	return rec(bs|is[a[i]^b[i]^idx[nth]],nth+1,r-1);
      }
    }
  }else{
    int rv=rec(bs|is[idx[nth]],nth+1,r-1);
    BS o=bs;
    int c=0;
    for(int i=0;n.any();i++){
      if(n[i]){
	o|=bs|is[a[i]^b[i]^idx[nth]];
	c++;
	n[i]=false;
      }
    }
    return max(rv,rec(o,nth+1,r-c));
  }
}

int main(){
  int N,M,K;
  cin>>N>>M>>K;
  int pop[32345]={};
  for(int i=0;i<M;i++){
    absbs[i]=true;
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
    pop[a[i]]++;
    pop[b[i]]++;
    is[a[i]][i]=true;
    is[b[i]][i]=true;
  }
  idx.resize(N);
  iota(begin(idx),end(idx),0);
  sort(begin(idx),end(idx),[pop](int a,int b){
      return pop[a]>pop[b];
    });
  int r=rec(BS(),0,K);
  if(r<0){
    cout<<"Impossible"<<endl;
  }else{
    cout<<K-r<<endl;
  }
}