#include<cstdio>
#include<complex>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<iostream>
#include<cassert>
#include<algorithm>

using namespace std;

typedef double Real;
typedef complex<Real> Point;
typedef pair<Point,Point> Line;
typedef pair<Point,Point> Segment;
typedef vector<Point> Polygon;

const Real eps=1e-7;
const Real eps2=5e-7;
const Real PI=acos(-1.0);
const Point NPoint=Point(NAN,NAN);
const Real inf=1e9;

int cnt=0;

template<class T> bool eq(T a, T b){
	return abs(a-b)<eps;
}

template<class T> int sgn(T a){
	if(eq(a,(T)0)) return 0;
	if(a>0) return 1;
	return -1;
}

void print(Point p,char ch='\n'){
	printf("(%f %f)%c",p.real(),p.imag(),ch);
}

void print(Polygon poly){
	printf("----\n");
	for(int i=0;i<poly.size();i++){
		print(poly[i]);
	}
	printf("----\n");
}

Polygon poly;
Point vec;
vector<Real> xs;

Real doP(Point a,Point b){
	return (conj(a)*b).real();
}

Real crP(Point a,Point b){
	return (conj(a)*b).imag();
}

bool onSeg(Point p,Point q,Point r){
	return eq(abs(p-q),abs(p-r)+abs(r-q));
}

Point toVec(Line l){
	return l.second-l.first;
}

bool isPara_(Line l1,Line l2){
	return eq(crP(toVec(l1),toVec(l2)),(Real)0);
}

Real getArea(Polygon poly){
	Real res=0;
	for(int i=0;i+1<poly.size();i++){
		res+=crP(poly[i],poly[i+1])/2;
	}
	res=abs(res);
	return res;
}

void rot(){
	Point p=Point(0,1);
	vec/=abs(vec);
	Point m=p/vec;
	for(int i=0;i<poly.size();i++){
		poly[i]*=m;
	}
	vector<Real> tmp;
	for(int i=0;i+1<poly.size();i++){
		bool ok=true;
		for(int j=0;j<tmp.size();j++){
			if(eq(tmp[j],poly[i].real())) ok=false;
		}
		if(ok) tmp.push_back(poly[i].real());
	}
	for(int i=0;i<poly.size();i++){
		for(int j=0;j<tmp.size();j++){
			if(eq(poly[i].real(),tmp[j])){
				poly[i]=Point(tmp[j],poly[i].imag());
				break;
			}
		}
	}
	xs=tmp;
	sort(xs.begin(),xs.end());
}

Point cmp_c;
bool cmp_ang(const Point &p1,const Point &p2){
	return arg(p1-cmp_c)<arg(p2-cmp_c);
}

struct PLexCmp{
	bool operator()(const Point &p1,const Point &p2) const {
		if(p1.real()!=p2.real()) return p1.real()<p2.real();
		return p1.imag()<p2.imag();
	}
};

struct SegLexCmp{
	bool operator()(const Segment &s1,const Segment &s2) const {
		if(s1.first.real()!=s2.first.real()) return s1.first.real()<s2.first.real();
		if(s1.first.imag()!=s2.first.imag()) return s1.first.imag()<s2.first.imag();
		if(s1.second.real()!=s2.second.real()) return s1.second.real()<s2.second.real();
		return s1.second.imag()<s2.second.imag();
	}
};

map<Point,vector<Point>,PLexCmp> con_pts;
vector<Real> ys;
set<Segment,SegLexCmp> invalid_es;

bool genConPts(Real x){
	map<Point,vector<Point>,PLexCmp> emptyMap;
	swap(emptyMap,con_pts);
	ys.clear();
	set<Segment,SegLexCmp> emptySet;
	swap(invalid_es,emptySet);
	for(int i=0;i+1<poly.size();i++){
		Point p=poly[i],q=poly[i+1];
		if(p.real()==x){
			ys.push_back(p.imag());
		}
	//	bool swapped=false;
		if(p.real()>q.real()){
	//		swapped=true;
			swap(p,q);
		}
		if(q.real()<=x||p.real()>=x){
			con_pts[p].push_back(q);
			con_pts[q].push_back(p);
			invalid_es.insert(Segment(poly[i+1],poly[i]));
			continue;
		}
		Real y=p.imag()+((q.imag()-p.imag())*(x-p.real())/(q.real()-p.real()));
		if(y==p.imag()){
			if(p.imag()>q.imag()) y+=eps;
			else y-=eps;
		}
		ys.push_back(y);
		Point r=Point(x,y);
		con_pts[p].push_back(r);
		con_pts[r].push_back(p);
		con_pts[q].push_back(r);
		con_pts[r].push_back(q);
		invalid_es.insert(Segment(poly[i+1],r));
		invalid_es.insert(Segment(r,poly[i]));
	}
	sort(ys.begin(),ys.end());
	int ln=ys.size();
	ys.erase(unique(ys.begin(),ys.end()),ys.end());
	if(ln!=ys.size()) return false;
	for(int i=0;i+1<ys.size();i++){
		Point p=Point(x,ys[i]);
		Point q=Point(x,ys[i+1]);
		con_pts[p].push_back(q);
		con_pts[q].push_back(p);
	}
	map<Point,vector<Point>,PLexCmp> :: iterator it=con_pts.begin();
	for(;it!=con_pts.end();it++){
		vector<Point> &vec=it->second;
		cmp_c=it->first;
		sort(vec.begin(),vec.end(),cmp_ang);
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
	/*	vector<Point> vec2;
		for(int i=0;i<vec.size();i++){
			if(i==0||(vec[i].real()!=vec[i-1].real()||vec[i].imag()!=vec[i-1].imag())){
				vec2.push_back(vec[i]);
			}
		}
		vec=vec2;*/
	}
	for(it=con_pts.begin();it!=con_pts.end();it++){
		for(int i=0;i<(it->second).size();i++){
			Point p=(it->second)[i];
			assert(con_pts.find(p)!=con_pts.end());
		}
	}
	return true;
}

void stroke(vector<Point> &vec,Point cur,Point prv,Point ini){
	vector<Point> pts=con_pts[cur];
	cmp_c=cur;
	int id=distance(pts.begin(),lower_bound(pts.begin(),pts.end(),prv,cmp_ang));
	assert(prv==pts[id]);
	id--;
	if(id==-1) id=pts.size()-1;
	assert(0<=id&&id<pts.size());
	Point nxt=pts[id];
	vec.push_back(nxt);
	if(nxt==ini) return;
	stroke(vec,nxt,cur,ini);
}

int whichSide(Polygon poly,Real x){
	bool le=false,ri=false;
	for(int i=0;i<poly.size();i++){
		if(poly[i].real()<x) le=true;
		if(poly[i].real()>x) ri=true;
	}
	if(le&&ri) return 0;
	else if(le) return -1;
	else if(ri) return 1;
	printf("error whichSide\n");
	printf("%f\n",x);
	print(poly);
	for(int i=0;i<ys.size();i++){
		printf("%f\n",ys[i]);
	}
	vector<Point> vec=con_pts[poly[0]];
	print(poly[0]);
	for(int i=0;i<vec.size();i++){
		printf("-");
		print(vec[i]);
	}
	printf("\n\n\n");
	map<Point,vector<Point>,PLexCmp> ::iterator it=con_pts.begin();
	for(;it!=con_pts.end();it++){
		print(it->first);
		for(int i=0;i<(it->second).size();i++){
			printf("-");
			print((it->second)[i]);
		}
	}
	exit(0);
}

bool isValid_(Polygon poly){
	for(int i=0;i+1<poly.size();i++){
		Segment seg=Segment(poly[i],poly[i+1]);
		if(invalid_es.find(seg)!=invalid_es.end()) return false;
	}
	return true;
}

pair<Real,Real> calcArea(Real x){
	Real le=0,ri=0;
	bool flg=genConPts(x);
	if(flg==false){
		return make_pair(inf,inf);
	}
	if(ys.size()<=1){
		return make_pair(inf,inf);
	}/*
	for(map<Point,vector<Point>,PLexCmp>::iterator it=con_pts.begin();it!=con_pts.end();it++){
		print(it->first,':');
		vector<Point> vec=it->second;
		for(int i=0;i<vec.size();i++){
			print(vec[i]);
		}
	}*/
	for(int i=0;i+1<ys.size();i++){
		Point p=Point(x,ys[i]);
		Point q=Point(x,ys[i+1]);
		vector<Point> poly;
		stroke(poly,p,q,p);
		poly.push_back(poly[0]);
		//bool flg=isRight(poly,x);
		int side=whichSide(poly,x);
		Real area=getArea(poly);/*
		if(flg) ri=max(ri,area);
		else {}//le=max(le,area);*/
		bool flg=isValid_(poly);
		if(side==1&&flg) ri=max(ri,area);
		//print(poly);
		
		poly.clear();
		stroke(poly,q,p,q);
		poly.push_back(poly[0]);
		//print(poly);
		//flg=isRight(poly,x);
		side=whichSide(poly,x);
		area=getArea(poly);/*
		if(flg) {}//ri=max(ri,area);
		else le=max(le,area);*/
		flg=isValid_(poly);
		if(side==-1&&flg) le=max(le,area);
	}
	return make_pair(le,ri);
}

Real calcEdgeCase(){
	Real res=getArea(poly);
	for(int i=1;i+1<xs.size();i++){
		pair<Real,Real> p=calcArea(xs[i]);
	//	printf("%f %f %f\n",xs[i],p.first,p.second);
		res=min(res,max(p.first,p.second));
	}
	return res;
}

Real calc(Real lb,Real ub,Real cur_best){
	Real res=inf;
	pair<Real,Real> p1,p2;
	p1=calcArea(lb);
	p2=calcArea(ub);
//	printf("a%f %f %f\n",lb,ub,cur_best);
	if(lb>ub) return cur_best;
	//if(max(p1.first,p1.second)>cur_best||max(p2.first,p2.second)>cur_best) return cur_best;
	if(p1.first>p1.second) return min(cur_best,p1.first);
	if(p2.first<p2.second) return min(cur_best,p2.second);
	for(int stage=0;stage<100;stage++){
		Real mid=(ub+lb)/2;
		pair<Real,Real> p=calcArea(mid);
		if(p.first>0&&p.second>0){
			res=min(res,max(p.first,p.second));
		}
		if(p.first==0||p.second==0){
			if(stage<50){
				Real tmp=cur_best;
				Real a=calc(lb+eps,mid-eps,tmp);
				tmp=min(tmp,a);
				a=calc(mid+eps,ub-eps,tmp);
				tmp=min(tmp,a);
				return tmp;
			}
		}
	//	printf("%f %f %f\n",mid,p.first,p.second);
		if(p.first<p.second){
			lb=mid;
		}else{
			ub=mid;
		}
	}
	return res;
}

Real solve(){
	rot();
	Real res=calcEdgeCase();
	//printf("edge case best = %f\n",res);
/*	for(int i=0;i+1<xs.size();i++){
		Real lb=xs[i]+eps2,ub=xs[i+1]-eps2;
		Real tmp=calc(lb,ub,res);
		res=min(res,tmp);
	}*/
	Real l=inf,r=-inf;
	vector<Real> xs;
	for(int i=0;i+1<poly.size();i++){
		l=min(l,poly[i].real());
		r=max(r,poly[i].real());
		Point p=poly[i],q=poly[i+1],r=poly[i+2>=poly.size()?0:i+2];
		if(crP(p-q,r-q)>0){
			if(p.real()==q.real()||q.real()==r.real()) continue;
			if(p.real()<q.real()!=q.real()<r.real()){
				xs.push_back(q.real());
			}
		}
	}
	xs.push_back(l);
	xs.push_back(r);
	sort(xs.begin(),xs.end());
	for(int i=0;i+1<xs.size();i++){
		Real lb=xs[i]+eps2,ub=xs[i+1]-eps2;
		Real tmp=calc(lb,ub,res);
		res=min(res,tmp);
	}
	return res;
}

void init(){
	poly.clear();
	xs.clear();
	ys.clear();
	map<Point,vector<Point>,PLexCmp> tmp;
	swap(con_pts,tmp);
}

void input(){
	int N;
	scanf("%d",&N);
	if(N==0) exit(0);
	int x,y;
	scanf("%d%d",&x,&y);
	vec=Point(x,y);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		poly.push_back(Point(x,y));
	}
	poly.push_back(poly[0]);
	cnt++;
}

int main(){
	while(true){
		init();
		input();
		Real ans=solve();
		printf("%f\n",ans);
//		cout<<ans<<"\n";
//		break;
	}
	return 0;
}