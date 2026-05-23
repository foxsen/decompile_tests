#include<iostream>
#include<complex>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<list>
#include<iomanip>

#define EPS (1e-8)
#define EQ(a,b) (abs((a)-(b)) < EPS)
#define fs first
#define sc second
#define pb push_back
#define sz size()
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

using namespace std;

typedef complex<double> P;
typedef pair<P,P> L;
typedef pair<P,double> C;

const double PI = acos(-1);

//for vector
P unit(P p){return p / abs(p);}

pair<P,P> norm(P p){return make_pair(p*P(0,1),p*P(0,-1));}

double dot(P x,P y){return real(conj(x)*y);}

double cross(P x,P y){return imag(conj(x)*y);}

//rotate a point counter-clockwise on the origin
P rotate(P v,double s){
  return P(real(v)*cos(s) - imag(v)*sin(s), real(v)*sin(s) + imag(v)*cos(s) );
}

//return seta A
double arg(P a,P b,P c){return acos(dot(b-a,c-a)/(abs(b-a)*abs(c-a)));}
double arg(double a,double b,double c){return acos( (b*b+c*c-a*a)/(2*b*c) );}

//for circle

bool in_cir(C c,P x){return (abs(x-c.fs) +EPS < c.sc);}
bool on_cir(C c,P x){return EQ(abs(x-c.fs),c.sc);}

//circle position relation
int cpr(C a,C b){
  double d = abs(a.fs-b.fs);
  if(a.sc+b.sc + EPS < d)return -1;      //no cross point (outside)
  if(b.sc+d + EPS < a.sc)return 1;       //no cross point (inside,B in A)
  if(a.sc+d + EPS < b.sc)return 2;       //no cross point (inside,A in B)
  if(abs(a.sc+b.sc - d) < EPS)return -3; //one cross point (outside)
  if(abs(b.sc+d - a.sc) < EPS)return 3;  //one cross point (inside,B in A)
  if(abs(a.sc+d - b.sc) < EPS)return 4;  //one cross point (inside,A in B)
  return 0;                              //two cross point
}

vector<P> cp_cir_to_cir(C a, C b){
  vector<P> v;
  int pos = cpr(a,b);
  if(pos==0){
    double s = arg(b.sc,abs(b.fs-a.fs),a.sc);
    P x = a.sc * unit(b.fs - a.fs);
    v.pb(a.fs + rotate(x,s));
    v.pb(a.fs + rotate(x,-s));
  }else if(abs(pos) >= 3){
    v.pb(a.fs + a.sc * unit(b.fs-a.fs));
  }
  return v;
}

double angle(P p, C c){
  P O = c.fs, A = P(c.fs.real(),c.fs.imag()+c.sc), B = p;
  double res = arg(O,A,B);
  if(cross(A-O,B-O)<-EPS)res = 2*PI-res;
  return res;
}

int n;
C c[110];
double x,y,r;

int main(){
  while(cin>>n,n){
    rep(i,n){
      cin >> x >> y >> r;
      c[i] = C(P(x,y),r);
    }

    vector<double> cp_list[110];
    rep(i,n){
      FOR(j,i+1,n){
	vector<P> p = cp_cir_to_cir(c[i],c[j]);
	if((int)p.sz==2){
	  rep(k,2)cp_list[i].pb(angle(p[k],c[i]));
	  rep(k,2)cp_list[j].pb(angle(p[k],c[j]));
	}
      }
    }

    rep(i,n){
      sort(all(cp_list[i]));
      rep(j,(int)cp_list[i].sz-1){
	if(EQ(cp_list[i][j],cp_list[i][j+1])){
	  cp_list[i].erase(cp_list[i].begin()+j);
	  j--;
	}
      }
    }

    double ans = 0;
    rep(i,n){
      if(cp_list[i].empty()){
	bool f = true;
	rep(j,n){
	  if(i==j)continue;
	  if(in_cir(c[j],c[i].fs) && c[i].sc < c[j].sc)f = false;
	}
	if(f)ans += 2*PI*c[i].sc;
      }else{
	rep(j,cp_list[i].sz){
	  double s;
	  if(j+1<(int)cp_list[i].sz)s = (cp_list[i][j]+cp_list[i][j+1])/2;
	  else s = (cp_list[i][j]+cp_list[i][0]+2*PI)/2;

	  P p = rotate(P(0,c[i].sc),s) + c[i].fs;
	  bool f = true;
	  rep(k,n){
	    if(i==k)continue;
	    if(in_cir(c[k],p))f = false;
	  }
	  double seta = cp_list[i][(j+1)%cp_list[i].sz]-cp_list[i][j];
	  if(seta<0)seta += 2*PI;
	  if(f)ans += seta*c[i].sc;
	}
      }
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
}