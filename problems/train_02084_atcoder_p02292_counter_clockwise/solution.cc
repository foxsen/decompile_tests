#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

#define x(p) real(p)
#define y(p) imag(p)

const double eps=1e-10;
const double inf=1e12;
typedef complex<double> P;

namespace std{
  bool operator<(const P& a,const P& b){
    return x(a)==x(b)?y(a)<y(b):x(a)<x(b);
  }
}
double cross(const P& a,const P& b){
  return y(conj(a)*b);
}
double dot(const P& a,const P& b){
  return x(conj(a)*b);
}
struct L : public vector<P> { // line and segment
  L(const P& a,const P &b){
    push_back(a);
    push_back(b);
  }
};

P projection(const L& l,const P& p){
  P b=l[1]-l[0],c=p-l[0];
  return l[0]+b*x(c/b);
}
P reflection(const L& l,const P& p){
  return p+2.0*(projection(l,p)-p);
}
//// counter-clockwise
int ccw(P a,P b,P c) {
  b=b-a;c=c-a;
  if(cross(b,c)>0) return +1;       // counter clockwise
  if(cross(b,c)<0) return -1;       // clockwise
  if(dot(b,c)<0)   return +2;       // c--a--b on line
  if(norm(b)<norm(c)) return -2;       // a--b--c on line
  return 0;
}

string s[]={"ONLINE_FRONT","CLOCKWISE","ON_SEGMENT","COUNTER_CLOCKWISE","ONLINE_BACK"};

int main(){
	cin.sync_with_stdio(false);
  int q;
  double x1,x2,x3,y1,y2,y3;
  cin>>x1>>y1>>x2>>y2;
  cin>>q;
  rep(i,q){
    cin>>x3>>y3;
    int res=ccw(P(x1,y1),P(x2,y2),P(x3,y3));
    cout<<s[res+2]<<endl;
  }
	return 0;
}