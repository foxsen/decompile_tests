#include<algorithm>
#include<iostream>
#include<complex>
#include<vector>
using namespace std;
#define x second
#define y first
#define M st.size()
typedef complex<double> point;
pair<int,int> a[100000];
vector<int> st;
bool ccw(point a,point b,point c){
  b-=a;
  c-=a;
  c*=conj(b);
  if(c.imag()<=0)return true;  
  return false;
}

void check(int i){
 while(M>=2){
      int s=st[M-2];
      int e=st[M-1];
      point S=point(a[s].x,a[s].y);
      point E=point(a[e].x,a[e].y);
      point N=point(a[i].x,a[i].y);
      if(ccw(S,E,N))break;
      st.pop_back();
    }
 st.push_back(i);
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y;
  sort(a,a+n);
  for(int i=0;i<n;i++)check(i);
  for(int i=n-2;i>=0;i--)check(i);
  st.pop_back();
  cout<<M<<endl;
  for(int i=M;i>0;i--)cout<<a[st[i%M]].x<<' '<<a[st[i%M]].y<<endl;
  return 0;
}