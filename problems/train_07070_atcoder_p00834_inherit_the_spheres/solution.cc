#include<iostream>
#include<complex>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define pb         push_back
#define mp         make_pair

const double eps = 1e-10;

typedef complex<double> P;

class Point{
public:
  double x,y,z;
};

class DisjointSet{
public:
  vector<int> rank,p;
  DisjointSet(){}
  DisjointSet(int size){
    rank.resize(size,0);
    p.resize(size,0);
  }
  
  void makeset(int x){
    p[x]=x;
    rank[x]=0;
  }
  void merge(int x,int y){
    link(findset(x),findset(y));
  }

  void link(int x,int y){
    if (rank[x] > rank[y]){
      p[y]=x;
    }else {
      p[x]=y;
      if (rank[x] == rank[y])rank[y]++;
    }
  }
  int findset(int x){
    if (x != p[x])p[x] = findset(p[x]);
    return p[x];
  }
};

int is_intersected_circle(P a,P b,double r1,double r2){
  double d =abs(a-b);
  if (d<eps&&abs(r1-r2)<eps)return 3;
  if (d+r2 < r1)return 0;
  if (d+r1 < r2)return 1;

  if (d > r1+r2)return 4;

  return 2;
}

inline double calc_r(double z,double r){
  if (z < 0)z*=-1;
  return sqrt(r*r-z*z);
}



double bsearch(P a,P b,double az,double bz,double ar,double br,double r,double l,
	       bool islower){
  double mid;
  while(l < r+eps){
    mid = (r+l)/2;
    if (islower){
      if (is_intersected_circle(a,b,calc_r(az-mid,ar),calc_r(bz-mid,br))==2)r=mid-eps;
      else l=mid+eps;
    }else {
      if (is_intersected_circle(a,b,calc_r(az-mid,ar),calc_r(bz-mid,br))==2)l=mid+eps;
      else r=mid-eps;
    }
  }
  return mid;
}

int is_intersected_sphere(Point a,Point b,double r1,double r2){
  double d =sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
  if (d<eps&&abs(r1-r2)<eps)return 3;
  if (d+r2 < r1)return 0;
  if (d+r1 < r2)return 1;
  if (d > r1+r2)return 4;
  return 2;
}

double compute_z(Point a,Point b,double r1,double r2){
  double l,m,n;
  double d =sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)); 
  double z;
  l=(d*d-r2*r2+r1*r1)/(2*d);
  z = a.z + (b.z-a.z)*l/d;
  return z;
}

bool is_contain_center_in_sphere(Point a,Point b,double r1){
  double d =sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)); 
  if (d < r1+eps)return true;
  return false;
}

bool is_contain_center_in_circle(P a,P b,double r1){
  if (isnan(r1))return false;
  double d = abs(a-b);
  if (d < r1 + eps)return true;
  return false;
}

bool is_contain_on_intersection(P a,P b,double ra,double rb){
   return is_contain_center_in_circle(a,b,ra)||is_contain_center_in_circle(b,a,rb);
}

void solve(int n,Point *in,double *r){
  vector<pair<double,int> > ans;
  rep(i,n){
    ans.pb(mp(in[i].z-r[i],1));
    ans.pb(mp(in[i].z+r[i],0));
  }

  rep(i,n){
    REP(j,i+1,n){
      int tmp = is_intersected_sphere(in[i],in[j],r[i],r[j]);
      if (is_intersected_sphere(in[i],in[j],r[i],r[j]) == 2){
	double z = compute_z(in[i],in[j],r[i],r[j]);
	double right,left;
	right=z;
	left=max(in[i].z-r[i],in[j].z-r[j]);
	double tmp =bsearch(P(in[i].x,in[i].y),P(in[j].x,in[j].y),in[i].z,in[j].z,
			    r[i],r[j],right,left,true); 
	ans.pb(mp(tmp,1));//start of intersection
	right=min(in[i].z+r[i],in[j].z+r[j]);
	left=z;
	tmp = bsearch(P(in[i].x,in[i].y),P(in[j].x,in[j].y),in[i].z,in[j].z,
		      r[i],r[j],right,left,false);
	ans.pb(mp(tmp,0));//start of intersection
      }
    }
  }


  int component=0;
  sort(ALL(ans));
  DisjointSet dj(n);
  vector<int >ret;
  rep(k,ans.size()){
    int tmp=0;
    double z = ans[k].first+eps;
    rep(i,n)dj.makeset(i);

    //cout <<k <<" " << z <<" " << ans[k].second <<  endl;



    rep(i,n){
      if (isnan(calc_r(in[i].z-z,r[i])))continue;
      REP(j,i+1,n){
	if (isnan(calc_r(in[j].z-z,r[j])))continue;	
	if (
	    is_contain_on_intersection(
				       P(in[i].x,in[i].y),
				       P(in[j].x,in[j].y),
				       calc_r(in[i].z-z,r[i]),
				       calc_r(in[j].z-z,r[j]))
	    ||
	    is_intersected_circle(P(in[i].x,in[i].y),
				  P(in[j].x,in[j].y),
				  calc_r(in[i].z-z,r[i]),
				  calc_r(in[j].z-z,r[j])) == 2
	    
	    )dj.merge(i,j);
      }
    }
    
    rep(i,n){
      if (isnan(calc_r(in[i].z-z,r[i])))continue;
      if (i == dj.findset(i))tmp++;
    }

    /*
      rep(i,n){
      if (isnan(calc_r(in[i].z-z,r[i])))cout <<"= ";
      else cout << dj.findset(i) <<" ";
    }
    cout << endl;
    */    

    
    if (tmp > component)ret.pb(1);//cout << 1;
    else if (tmp < component)ret.pb(0);//cout << 0;
    

    component=tmp;
  }

  cout << ret.size() << endl;
  rep(i,ret.size()){
    cout << ret[i];
  }
  cout << endl;

      /*
  sort(ALL(ans));
  cout << ans.size() << endl;
  rep(i,ans.size()){
    cout << ans[i].second;
  }
  cout << endl;
      */
}


int main(){
  int n;
  while(cin>>n && n){
    double r[n];
    Point in[n];
    rep(i,n){
      cin>>in[i].x>>in[i].y>>in[i].z >>r[i];
    }
    solve(n,in,r);
  }
}