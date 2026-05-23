#include<bits/stdc++.h>

using namespace std;


#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

typedef complex<double> P;

vector<P> point;

const double EPS = 0.0000000001;


void init(){
  point.clear();
}


bool input(){
  int n;
  cin>>n;
  if(n==0)return false;

  rep(i,n){
    double a ,b;
    cin>>a>>b;
    point.push_back(P(a,b));
  }
  return true;
}

vector<P> make_cand(){
  vector<P> ret;
  rep(i,point.size()){
    reps(j,i+1,point.size()){
      P dist = point[j]-point[i];
      double d = abs(dist)/2;

      if(d>1)continue;
      double h = sqrt(1-d*d);
      P e = dist/(d*2);

      P e1 = e*P(0,1);
      P e2 = e*P(0,-1);

      P c1 = point[i]+e*d+h*e1;
      P c2 = point[i]+e*d+h*e2;

      //cout<<"d="<<d<<" h="<<h<<endl;
      //cout<<point[i]<<" "<<point[j]<<" "<<c1<<" "<<c2<<endl;
      ret.push_back(c1);
      ret.push_back(c2);
    }
  }
  rep(i,point.size()){
    ret.push_back(point[i]);
  }
  return ret;
}

int count_in(P p){
  int sum = 0;
  rep(i,point.size()){
    P d  = point[i]-p;
    if(abs(d)<=1+EPS)sum++;
  }
  return sum;
}
int solve(){
  vector<P> cand = make_cand();
  int ans = 0;
  rep(i,cand.size()){
    ans = max(ans, count_in(cand[i]));
  }
  return ans;
}

int main(){
  while(init(),input()){
    printf("%d\n",solve());
  }
}