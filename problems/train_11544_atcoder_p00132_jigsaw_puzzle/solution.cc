/*
  sample input
real    0m1.756s
user    0m1.652s
sys     0m0.012s
 */
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
const int R =20,C=20;
class st{
public:
  int r,c;
  bool m[R][C];
  bool all[4][R][C];
  int rotreq;
  int cnt;
  int id;
  void rot(){
    bool tmp[R][C];
    rep(i,r)rep(j,c)tmp[i][j]=m[i][j];
    rep(i,c){
      rep(j,r){
	m[i][j]=tmp[j][c-1-i];
      }
    }
    swap(r,c);
  }
  void set(int i){
    id=i;
    cnt=0;
    rep(i,r)rep(j,c)if (m[i][j])cnt++;
    rotreq=0;
    rep(k,4){
      rot();
      rep(i,r)rep(j,c)all[k][i][j]=m[i][j];
    }
    rep(k,4){
      bool isok=true;
      rep(kk,k){
	if (r != c && k%2 != kk%2)continue;
	bool issame=true;
	rep(i,r)rep(j,c)if (all[k][i][j] != all[kk][i][j])issame=false;
	if (issame)isok=false;
      }
      if (isok)rotreq|=(1<<k);
    }
  }
  bool issame(const st & a)const{
    rep(k,4){
      int rr=k%2==1?r:c,cc=k%2==1?c:r;
      if (a.r != rr || a.c != cc)continue;
      bool issame=true;
      rep(i,rr){
	rep(j,cc){
	  if (a.m[i][j] != all[j][i][j])issame=false;
	}
      }
      if (issame)return true;
    }
    return false;
  }
  bool operator<(const st & a)const{
    if (!issame(a)){
      if (cnt != a.cnt)return cnt > a.cnt;
      else return r*c > a.r*a.c;
    }
    return false;
  }
};

void output(int r,int c,bool m[R][C]){
  rep(i,r){
    rep(j,c)cout << m[i][j];
    cout << endl;
  }
  cout << endl;
}

void getinp(int r,int c,bool a[R][C]){
  rep(i,r){
    rep(j,c){char t;cin>>t;a[i][j]=t=='#';}
  }
}

bool issame[10][10];
bool solve(int now,const vector<int> & num,const int r,const int c,bool ori[R][C],st *in,int last){
  //output(r,c,ori);
  if (now == num.size()){
    rep(i,r)rep(j,c)if (!ori[i][j])return false;
    return true;
  }
  bool covered[R][C]={};
  rep(i,r)rep(j,c)covered[i][j]=ori[i][j];
  int prev=now==0?-1:(issame[num[now]][num[now-1]]?last:-1);
  int p=num[now];
  REP(i,now,num.size()){
    int p=num[i];
    bool havecand=false;
    rep(k,4){
      in[p].rot();
      if ((in[p].rotreq&(1<<k)) == 0)continue;
      rep(i,r){
	if (i+in[p].r > r)break;
	rep(j,c){
	  if (j+in[p].c > c)break;

	  bool isok=true;	
	  rep(ii,in[p].r)rep(jj,in[p].c)
	    if (ori[i+ii][j+jj] && in[p].m[ii][jj]){isok=false;}
	  if (!isok)continue;
	  havecand=true;
	  rep(ii,in[p].r)rep(jj,in[p].c)covered[i+ii][j+jj]=true;
	}
      }
    }
    if (!havecand)return false;
  }

  //output(r,c,covered);

  rep(i,r)rep(j,c)if (!covered[i][j])return false;

  rep(k,4){
    in[p].rot();
    //swap(in[p].r,in[p].c);
    if ((in[p].rotreq&(1<<k)) == 0)continue;
    rep(i,r){
      if (i+in[p].r > r)break;
      rep(j,c){
	if (i*j+c <= prev)continue;
	/*
	if (j+in[p].c > c)break;
	bool isok=true;	
	rep(ii,in[p].r)rep(jj,in[p].c)
	  if (ori[i+ii][j+jj] && in[p].all[k][ii][jj]){isok=false;}
	if (!isok)continue;
	rep(ii,in[p].r)rep(jj,in[p].c)if (in[p].all[k][ii][jj])ori[i+ii][j+jj]=true;
	bool ret=solve(now+1,num,r,c,ori,in,i*c+j);
	rep(ii,in[p].r)rep(jj,in[p].c)if (in[p].all[k][ii][jj])ori[i+ii][j+jj]=false;
	if (ret)return true;
	*/

	if (j+in[p].c > c)break;
	bool isok=true;	
	rep(ii,in[p].r)rep(jj,in[p].c)
	  if (ori[i+ii][j+jj] && in[p].m[ii][jj]){isok=false;}
	if (!isok)continue;
	rep(ii,in[p].r)rep(jj,in[p].c)if (in[p].m[ii][jj])ori[i+ii][j+jj]=true;
	bool ret=solve(now+1,num,r,c,ori,in,i*c+j);
	rep(ii,in[p].r)rep(jj,in[p].c)if (in[p].m[ii][jj])ori[i+ii][j+jj]=false;
	if (ret)return true;

      }
    }
  }
  return false;
}

int main(){
  bool in[R][C]={};
  int r,c;
  while(cin>>r>>c && r){
    int total=0;
    getinp(r,c,in);
    rep(i,r)rep(j,c)if (!in[i][j])total++;

    int n;
    cin>>n;
    st inp[n];
    rep(i,n){
      cin>>inp[i].r>>inp[i].c;
      getinp(inp[i].r,inp[i].c,inp[i].m);
      inp[i].set(i);
    }
    sort(inp,inp+n);
    map<int,int> M;
    rep(i,n)M[inp[i].id]=i;
    rep(i,n){
      REP(j,i+1,n){
	if (inp[i].issame(inp[j]))issame[i][j]=issame[j][i]=true;
	else issame[i][j]=issame[j][i]=false;
      }
    }

    int q;
    cin>>q;
    rep(k,q){
      int num;cin>>num;
      vector<int> a(num);
      int sum=0;
      rep(i,num){
	cin>>a[i];
	a[i]--;
	a[i]=M[a[i]];
	sum+=inp[a[i]].cnt;
      }
      if (sum == total && solve(0,a,r,c,in,inp,-1))cout <<"YES" << endl;
      else cout <<"NO"<<endl;
    }
  }
  return false;
}