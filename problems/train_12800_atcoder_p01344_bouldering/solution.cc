#include<cstdio>
#include<cmath>
#include<utility>
#include<vector>
#include<queue>
#include<complex>
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

typedef double Real;
typedef complex<Real> Point;

const Real PI=acos(-1.0);
const Real eps=1e-10;

template<class T> bool eq(T a,T b){
	return abs(a-b)<eps;
}
template<class T> int sgn(T a){
	if(eq(a,(T)0.0)) return 0;
	if(a>0) return 1;
	return -1;
}

void print(Point p,char ch='\n'){
	printf("(%f %f)%c",p.real(),p.imag(),ch);
}

Point getPoint(Point c,Real r,Real ang){
	return c+r*Point(cos(ang),sin(ang));
}

Real arg(Point p){
	return atan2(p.imag(),p.real());
}

struct Sector:pair<Real,Real> {
	Point c;
	Real r;
	Sector(){}
	Sector(Point c,Real r):c(c),r(r){}
	Sector(Point c,Real r,Real a,Real b){
		this->c=c;
		this->r=r;
		this->first=a;
		this->second=b;
	}
};

void print(Sector sec){
	print(sec.c);
	printf("%f %f %f\n",sec.r,sec.first,sec.second);
}

struct Circle:vector<Real> {
	Point c;
	Real r;
	Circle(){}
	Circle(Point c,Real r):c(c),r(r){}
	Circle(Sector s):c(s.c),r(s.r){}
};

Real normalize(Real t){
	while(t<-PI) t+=PI*2;
	while(t>PI) t-=PI*2;
	return t;
}

void toInf(pair<Real,Real> &p){
	Real ang=p.second-p.first;
	if(ang<0) ang+=PI*2;
	if(ang>=PI) swap(p.first,p.second);
}

bool inRange(Real l,Real r,Real x){
	if(r<l) r+=PI*2;
	if(sgn(x-l)>=0&&sgn(r-x)>=0) return true;
	if(sgn(x+PI*2-l)>=0&&sgn(r-x-PI*2)>=0) return true;
	return false;
}

void iCC(Circle &c,Circle &c2){
	if(eq(c.c,c2.c)) return;
	Real d=abs(c.c-c2.c);
	Real r=c.r,r2=c2.r;
	if(sgn(d-(r+r2))>0) return;
	else if(sgn(d-(r+r2))==0){//out tangent
		Real ang=normalize(arg(c2.c-c.c));
		c.push_back(ang);
	}else if(sgn(d-abs(r-r2))>0){//intersect two points
		Real ang=arg(c2.c-c.c);
		Real ang2=acos((r*r+d*d-r2*r2)/(2*r*d));
		c.push_back(normalize(ang+ang2));
		c.push_back(normalize(ang-ang2));
	}else if(sgn(d-abs(r-r2))==0){//in tangent
		if(r>r2){
			c.push_back(normalize(arg(c2.c-c.c)));
		}else{
			c.push_back(normalize(-arg(c2.c-c.c)));
		}
	}else{//contained
		return;
	}
}

bool iScSc_(Sector s1,Sector s2){
	if(eq(s1.c,s2.c)){
		if(!eq(s1.r,s2.r)) return false;
		if(inRange(s1.first,s1.second,s2.first)) return true;
		if(inRange(s1.first,s1.second,s2.second)) return true;
		if(inRange(s2.first,s2.second,s1.first)) return true;
		if(inRange(s2.first,s2.second,s1.second)) return true;
		return false;
	}
	Circle c1(s1);
	Circle c2(s2);
//	print(s1);
//	print(s2);
	iCC(c1,c2);
	iCC(c2,c1);
	for(int i=0;i<c1.size();i++){
		if(inRange(s1.first,s1.second,c1[i])){
			Point p=getPoint(s1.c,s1.r,c1[i]);
			Real ang=arg(p-c2.c);
			if(inRange(s2.first,s2.second,ang)){
//				print(getPoint(s2.c,s2.r,ang));
				return true;
			}
		}
	}
	return false;
}

bool inSc_(Sector s,Point p){
	if(eq(s.c,p)) return true;
	Real d=abs(p-s.c);
	if(sgn(d-s.r)>0) return false;
	Real ang=normalize(arg(p-s.c));
	if(inRange(s.first,s.second,ang)) return true;
	return false;
}

Real A,B,C;

bool check2(Point p1,Point p2,Point q1,Point q2){//p1==p2
	if(eq(q1,q2)) return false;
	Sector s=Sector(p1,A+B,-PI,PI);
	Circle c1,c2;
	c1=Circle(q1,C);
	c2=Circle(q2,C);
	iCC(c1,c2);
	iCC(c2,c1);
	if(c1.size()<2) return false;
	Sector s1=Sector(c1.c,c1.r,c1[0],c1[1]);
	Sector s2=Sector(c2.c,c2.r,c2[0],c2[1]);
	toInf(s1);
	toInf(s2);
	if(iScSc_(s,s1)) return true;
	if(iScSc_(s,s2)) return true;
	if(inSc_(s,getPoint(s1.c,s1.r,s1.first))) return true;
	return false;
}

bool check3(Point p1,Point p2,Point q1,Point q2){//q1==q2
	if(eq(p1,p2)) return false;
	Circle c1=Circle(p1,B);
	Circle c2=Circle(p2,B);
	iCC(c1,c2);
	iCC(c2,c1);
	if(c1.size()<2) return false;
	Sector scs[4];
	scs[0]=Sector(c1.c,c1.r+A,c1[0],c1[1]);
	scs[1]=Sector(c2.c,c2.r+A,c2[0],c2[1]);
	Point i1=getPoint(c1.c,c1.r,c1[0]);
	scs[2]=Sector(i1,A,arg(i1-c1.c),arg(i1-c2.c));
	Point i2=getPoint(c1.c,c1.r,c1[1]);
	scs[3]=Sector(i2,A,arg(i2-c1.c),arg(i2-c2.c));
	for(int i=0;i<4;i++) toInf(scs[i]);
	Sector s=Sector(q1,C,-PI,PI);
	for(int i=0;i<4;i++){
		if(iScSc_(scs[i],s)) return true;
	}
	for(int i=0;i<4;i++){
		Point p=getPoint(s.c,s.r,s.first);
		if(inSc_(scs[i],p)) return true;
	}
	return false;
}

bool check(Point p1,Point p2,Point q1,Point q2){
//	cout<<"check"<<endl;
	if(eq(p1,p2)) return check2(p1,p2,q1,q2);
	if(eq(q1,q2)) return check3(p1,p2,q1,q2);
	Circle c1=Circle(p1,B);
	Circle c2=Circle(p2,B);
	iCC(c1,c2);
	iCC(c2,c1);
	if(c1.size()<2) return false;
	Sector scs[4];
	scs[0]=Sector(c1.c,c1.r+A,c1[0],c1[1]);
	scs[1]=Sector(c2.c,c2.r+A,c2[0],c2[1]);
	Point i1=getPoint(c1.c,c1.r,c1[0]);
	scs[2]=Sector(i1,A,arg(i1-c1.c),arg(i1-c2.c));
	Point i2=getPoint(c1.c,c1.r,c1[1]);
	scs[3]=Sector(i2,A,arg(i2-c1.c),arg(i2-c2.c));
	for(int i=0;i<4;i++) toInf(scs[i]);
	{
		Point tmp=getPoint(scs[0].c,scs[0].r,scs[0].first);
		Real d1=abs(tmp-q1);
		Real d2=abs(tmp-q2);
		if(sgn(d1-C)<=0&&sgn(d2-C)<=0){
			return true;
		}
	}
	c1.clear();
	c2.clear();
	c1=Circle(q1,C);
	c2=Circle(q2,C);
	iCC(c1,c2);
	iCC(c2,c1);
	if(c1.size()<2) return false;
	Sector s1=Sector(c1.c,c1.r,c1[0],c1[1]);
	Sector s2=Sector(c2.c,c2.r,c2[0],c2[1]);
	toInf(s1);
	toInf(s2);
	for(int i=0;i<4;i++){
		bool flg=iScSc_(scs[i],s1);
		if(flg) return true;
		flg=iScSc_(scs[i],s2);
		if(flg) return true;
	}
	Point tmp=getPoint(c1.c,c1.r,c1[0]);
	for(int i=2;i<4;i++){
		if(inSc_(scs[i],tmp)) return true;
	}
	for(int i=0;i<2;i++){
		if(inSc_(scs[i],tmp)){
			if(inSc_(scs[i^1],tmp)) return true;
			Real d=abs(scs[i].c-tmp);
			if(d>B) return true;
		}
	}
	return false;
}

Point pts[33];
int N;

int dis[33][33][33][33];
const int iinf=1e9;

void precalc(){
//	check(pts[0],pts[5],pts[1],pts[3]);
	//exit(0);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				for(int l=0;l<N;l++){
					bool flg=check(pts[i],pts[j],pts[k],pts[l]);
					if(flg) dis[i][j][k][l]=-1;
					else dis[i][j][k][l]=iinf;
				}
			}
		}
	}
}

int cnt(int i,int j,int k,int l){
	set<int> se;
	se.insert(i);
	se.insert(j);
	se.insert(k);
	se.insert(l);
	return se.size();
}

struct State{
	int i,j,k,l;
	State(){}
	State(int i,int j,int k,int l):i(i),j(j),k(k),l(l){
//		if(cnt(i,j,k,l)<4) i=-1;
		if(i==j||i==k||i==l||j==k||j==l||k==l) i=-1;
	}
};

bool isValid(State st){
	int i=st.i,j=st.j,k=st.k,l=st.l;
	if(i==j||i==k||i==l||j==k||j==l||k==l) return false;
//	if(cnt(i,j,k,l)<4) return false;
	if(dis[i][j][k][l]==iinf) return false;
	return true;
}

int cnt2(State st1,State st2){
	return 3;
/*	set<int> se;
	if(st1.i==st2.i) se.insert(st1.i);
	if(st1.j==st2.j) se.insert(st1.j);
	if(st1.k==st2.k) se.insert(st1.k);
	if(st1.l==st2.l) se.insert(st1.l);
	return se.size();*/
}

State getNxt(State st,int a,int b){
	State ini=st;
	if(a==0) st.i=b;
	else if(a==1) st.j=b;
	else if(a==2) st.k=b;
	else st.l=b;
	int c=cnt2(ini,st);
	if(c<3) st.i=-1;
	return st;
}

queue<State> que;
int bfs(){
	while(!que.empty()) que.pop();
	que.push(State(0,1,2,3));
	dis[0][1][2][3]=0;
	while(!que.empty()){
		State st=que.front();
		que.pop();
		if(st.i==-1) continue;
		int cur=dis[st.i][st.j][st.k][st.l];
		for(int i=0;i<4;i++){
			for(int j=0;j<N;j++){
				State nst=getNxt(st,i,j);
				if(nst.i==-1) continue;
				bool flg=isValid(nst);
				if(!flg) continue;
				int nd=cur+1;
				int &nxt=dis[nst.i][nst.j][nst.k][nst.l];
				if(nxt!=-1&&nxt<=nd) continue;
				nxt=nd;
				que.push(nst);
			}
		}
	}
	int res=iinf;
	for(int i=0;i<N;i++) for(int j=0;j<N;j++){
		for(int k=0;k<N;k++) for(int l=0;l<N;l++){
			if(i==N-1||j==N-1||k==N-1||l==N-1){
				if(dis[i][j][k][l]!=-1){
					res=min(res,dis[i][j][k][l]);
				}
			}
		}
	}
	if(res==iinf) return -1;
	return res;
}

void input(){
	scanf("%d",&N);
	scanf("%lf%lf%lf",&A,&B,&C);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		pts[i]=Point(x,y);
	}
}

int solve(){
	precalc();
	int res=bfs();
	return res;
}

int main(){
	input();
	int ans=solve();
	printf("%d\n",ans);
	return 0;
}