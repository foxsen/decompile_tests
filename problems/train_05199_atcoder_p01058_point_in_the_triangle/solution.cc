#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS=1e-10,pi=M_PI;
typedef complex<double> P;
double cross(const P& a, const P& b) {return imag(conj(a)*b);}
double dot(const P& a, const P& b) {return real(conj(a)*b);}
bool cmp(P a, P b) {
  double at=atan2(a.imag(),a.real()),at2=atan2(b.imag(),b.real());
  return at!=at2?at<at2:max(abs(a.real()),abs(a.imag()))<max(abs(b.real()),abs(b.imag()));
}
int ccw(P a, P b, P c) {
  b-=a;c-=a;
  if(cross(b,c)>EPS)return +1;
  if(cross(b,c)<-EPS)return -1;
  if(dot(b,c)<-EPS)return +2;
  if(norm(b)<norm(c))return -2;
  return 0;
}

int main() {
  ll n,m,x,y,sum[2];
  cin >> n >> m;
  for(int k=0; k<2; k++) {
    cin >> x >> y;
    if(x==n-1 && y==m-1) x=0,y=0;
    vector<P> v;
    map<double,ll> d;
    for(ll i=0; i<n; i++) {
      for(ll j=0; j<m; j++) {
        if(i-x || j-y) v.push_back(P(i-x,j-y));
      }
    }
    sort(v.begin(),v.end(),cmp);
    sum[k]=n*m*(n*m-1)*(n*m-2)/6;
    ll cnt=0,j=v.size()-1;
    while(j && (ccw(v[0],P(0,0),v[j])==1 || ccw(v[0],P(0,0),v[j])==0)) {
      cnt++;
      j--;
    }
    j=(j+1)%v.size();
    for(int i=0; i<v.size(); i++) {
      while(i!=j && ccw(v[i],P(0,0),v[j])!=1 && ccw(v[i],P(0,0),v[j])!=0) {
        cnt--;
        j=(j+1)%v.size();
      }
      sum[k]-=cnt*(cnt-1)/2;
      double at=atan2(v[i].imag(),v[i].real()),xx=v[i].real(),yy=v[i].imag();
      if(xx) xx=-xx;
      if(yy) yy=-yy;
      double at2=atan2(yy,xx);
      sum[k]-=d[at2]*(d[at2]+1)/2+d[at]*(d[at2]+1);
      cnt++;
      d[at]++;
    }
  }
  cout << abs(sum[0]-sum[1]) << endl;
  return 0;
}
