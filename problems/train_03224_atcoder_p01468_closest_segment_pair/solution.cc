#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

#define EPS 1e-8
#define EQ(a) (-EPS<a && a<EPS)
#define MP make_pair

bool operator<(P l,P r){
  if(l.real()!=r.real())return l.real()<r.real();
  return l.imag()<r.imag();
}

struct line{P a,b;};

bool operator<(line l,line r){
  if(l.a!=r.a)return l.a<r.a;
  return l.b<r.b;
}

double dot(P a,P b){
  return (conj(a)*b).real();
}
double cross(P a,P b){
  return (conj(a)*b).imag();
}
double po(P a){
  return a.real()*a.real() + a.imag()*a.imag();
}

// http://www.deqnotes.net/acmicpc/2d_geometry/lines
double distance(line a,P b){
  if ( dot(a.b-a.a, b-a.a) < EPS ) return po(b-a.a);
  if ( dot(a.a-a.b, b-a.b) < EPS ) return po(b-a.b);
  double t = abs( cross(a.b-a.a, b-a.a) );
  return t*t / po(a.b-a.a);
}

// http://www5d.biglobe.ne.jp/~tomoya03/shtml/algorithm/Intersection.htm
bool intersect(line a,line b){
  double x,y;
  x = cross(a.b-a.a, b.a-a.a);
  y = cross(a.b-a.a, b.b-a.a);
  if(EQ(x)&&EQ(y))return false;
  if(x*y>EPS)return false;
  x = cross(b.b-b.a, a.a-b.a);
  y = cross(b.b-b.a, a.b-b.a);
  if(EQ(x)&&EQ(y))return false;
  if(x*y>EPS)return false;
  return true;
}

int main(){
  int n;
  scanf("%d",&n);
  if(n>5100){ // (101*101-1)/2 = 10200/2 = 5100
    // law of "su of hato"
    cout << "0.0000000" << endl;
    return 0;
  }
  assert(n <= 5100);
  // O(N^2) ~ O(1e8)
  line lines[n];
  double result = 114514.0;
  REP(i,n){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a<c) lines[i] = (line){P(a,b),P(c,d)};
    else    lines[i] = (line){P(c,d),P(a,b)};
  }
  sort(lines,lines+n);
  REP(i,n){
    line a = lines[i];
    FOR(j,i+1,n){
      line b = lines[j];
      if(a.b.real()+result < b.a.real())break;
      if(intersect(a,b)){
        cout << "0.0000000" << endl;
        return 0;
      }
      result = min(result,
        min(min(distance(a,b.a), distance(a,b.b)),
            min(distance(b,a.a), distance(b,a.b))) );
    }
  }
  cout.precision(10);
  cout << fixed << sqrt(result) << endl;
  return 0;
}