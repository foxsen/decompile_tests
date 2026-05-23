#include<map>
#include<cctype>
#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct point{
	int x,y,z;
	point operator+(const point &a)const{ return (point){x+a.x,y+a.y,z+a.z}; }
	point operator-(const point &a)const{ return (point){x-a.x,y-a.y,z-a.z}; }
	bool operator==(const point &a)const{ return x==a.x && y==a.y && z==a.z; }
};

struct edge{
	point u,v;
	bool operator==(const edge &e)const{ return u==e.u && v==e.v || u==e.v && v==e.u; }
};

struct key{
	int n;
	edge E[300];
};

key getkey(){
	key K={};
	point p={0,0,0};
	map<int,point> f;
	int n; scanf("%d",&n);
	while(n--){
		char s[8]; scanf("%s",s);

		if(isdigit(s[0])){
			int a; sscanf(s,"%d",&a);
			if(f.count(a)) p=f[a];
			else           f[a]=p;
		}
		else{
			point q=p;
			if(s[0]=='+' && s[1]=='x') q.x++;
			if(s[0]=='-' && s[1]=='x') q.x--;
			if(s[0]=='+' && s[1]=='y') q.y++;
			if(s[0]=='-' && s[1]=='y') q.y--;
			if(s[0]=='+' && s[1]=='z') q.z++;
			if(s[0]=='-' && s[1]=='z') q.z--;
			K.E[K.n++]=(edge){p,q};
			p=q;
		}
	}

	return K;
}

struct matrix{
	int a[3][3];

	point operator*(const point &p)const{
		int x=a[0][0]*p.x+a[0][1]*p.y+a[0][2]*p.z;
		int y=a[1][0]*p.x+a[1][1]*p.y+a[1][2]*p.z;
		int z=a[2][0]*p.x+a[2][1]*p.y+a[2][2]*p.z;
		return (point){x,y,z};
	}

	matrix operator*(const matrix &A)const{
		matrix B={};
		rep(i,3) rep(j,3) rep(k,3) B.a[i][j]+=a[i][k]*A.a[k][j];
		return B;
	}

	bool operator==(const matrix &A)const{
		rep(i,3) rep(j,3) if(a[i][j]!=A.a[i][j]) return false;
		return true;
	}
};

vector<matrix> R;

bool issame(const key &K1,const key &K2){
	if(K1.n!=K2.n) return false;

	point shift1=K1.E[0].u;
	point dir1=K1.E[0].v-shift1;
	rep(i,K2.n){
		point shift2,dir2;
		rep(t,2){
			if(t==0) shift2=K2.E[i].u, dir2=K2.E[i].v-shift2;
			if(t==1) shift2=K2.E[i].v, dir2=K2.E[i].u-shift2;

			rep(j,R.size()) if(R[j]*dir1==dir2) {
				bool ok=true;
				rep(k,K1.n){
					edge e=K1.E[k];
					e=(edge){e.u-shift1,e.v-shift1};
					e=(edge){R[j]*e.u,R[j]*e.v};
					e=(edge){e.u+shift2,e.v+shift2};
					if(count(K2.E,K2.E+K2.n,e)!=1){ ok=false; break; }
				}
				if(ok) return true;
			}
		}
	}
	return false;
}

int main(){
	matrix I,X,Y,Z;
	I.a[0][0]= 1; I.a[0][1]= 0; I.a[0][2]= 0;
	I.a[1][0]= 0; I.a[1][1]= 1; I.a[1][2]= 0;
	I.a[2][0]= 0; I.a[2][1]= 0; I.a[2][2]= 1;
	X.a[0][0]= 1; X.a[0][1]= 0; X.a[0][2]= 0;
	X.a[1][0]= 0; X.a[1][1]= 0; X.a[1][2]=-1;
	X.a[2][0]= 0; X.a[2][1]= 1; X.a[2][2]= 0;
	Y.a[0][0]= 0; Y.a[0][1]= 0; Y.a[0][2]=-1;
	Y.a[1][0]= 0; Y.a[1][1]= 1; Y.a[1][2]= 0;
	Y.a[2][0]= 1; Y.a[2][1]= 0; Y.a[2][2]= 0;
	Z.a[0][0]= 0; Z.a[0][1]=-1; Z.a[0][2]= 0;
	Z.a[1][0]= 1; Z.a[1][1]= 0; Z.a[1][2]= 0;
	Z.a[2][0]= 0; Z.a[2][1]= 0; Z.a[2][2]= 1;

	R.push_back(I);
	while(1){
		bool change=false;
		rep(i,R.size()){
			rep(j,3){
				matrix A=(j==0?X*R[i]:j==1?Y*R[i]:Z*R[i]);
				if(count(R.begin(),R.end(),A)==0){ R.push_back(A); change=true; }
			}
		}
		if(!change) break;
	}

	while(1){
		key K1=getkey(); if(K1.n==0) break;
		key K2=getkey();

		puts(issame(K1,K2)?"SAME":"DIFFERENT");
	}

	return 0;
}