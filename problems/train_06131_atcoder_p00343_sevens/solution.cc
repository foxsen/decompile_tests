#include<bits/stdc++.h>

using namespace std;
#define INF (1<<28)
#define DEKAI 1000000007
#define lp(i,n) for(int i=0;i<n;i++)
#define int long long
int stat;

int check(vector<int> a,int n){
  lp(i,a.size()){
    if(a[i]==n){
      return i+1;
    }
  }
  return 0;
}

int calc(vector<int> a,vector<int> b,int c[],int pos){
  /*cout<<a.size()<<" "<<b.size()<<" "<<pos<<endl;
  int hoge;
  cin>>hoge;*/
  if(b.size()==0){
    return 0;
  }
  if(a.size()==0) return 1;
  vector<int> tr;
  if(pos==0) tr=a;
  else tr=b;
  int eg=0;
  bool sc=pos;
  lp(i,14){
    if(i==0)continue;
    //if(stat>0)return 0;
    if(c[i]==1)continue;
    if(i!=1){
      if(c[i-1]==1&&check(tr,i)){
        eg=1;
        tr.erase(tr.begin()+(check(tr,i)-1));
        c[i]=1;
        if(pos==0) {
          sc|=calc(tr,b,c,1);
        }
        else sc&=calc(a,tr,c,0);
        c[i]=0;
        tr.push_back(i);
      }
    }
    if(i!=13){
      if(c[i+1]==1&&check(tr,i)){
        eg=1;
        tr.erase(tr.begin()+(check(tr,i)-1));
        c[i]=1;
        if(pos==0) {
          sc|=calc(tr,b,c,1);
        }
        else sc&=calc(a,tr,c,0);
        c[i]=0;
        tr.push_back(i);
      }
    }
  }
  if(eg==0){
      if(pos==0)sc=calc(a,b,c,1);
      else sc=calc(a,b,c,0);
  }
  return sc;
}


signed main(){
  int n;
  cin>>n;
  vector<int> a,b;
  lp(i,n){
    stat=0;
    a.clear();
    b.clear();
    int c[14];
    lp(j,14)c[j]=0;
    lp(j,6){
      int x;
      cin>>x;
      c[x]=1;
      a.push_back(x);
    }
    lp(j,14){
      if(j==0||j==7) continue;
      if(c[j]==0) b.push_back(j);
      c[j]=0;
    }
    c[7]=1;
    stat=calc(a,b,c,0);
    if(stat==0) cout<<"no"<<endl;
    else cout<<"yes"<<endl;
  }
  return 0;
}
