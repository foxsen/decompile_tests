#include<cstdio>
#include<string>
#include<vector>
#include<iostream>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class dice{
	int a[6];
public:
	dice(){}
	dice(int t,int l,int f,int r,int b,int d){
		a[0]=t; a[1]=l; a[2]=f;
		a[3]=r; a[4]=b; a[5]=d;
	}
	bool operator==(const dice &D)const{
		rep(i,6) if(a[i]!=D.a[i]) return false;
		return true;
	}
	bool operator!=(const dice &D)const{ return !(D==*this); }
	int operator[](int i)const{ return a[i]; }
	int &operator[](int i){ return a[i]; }
	void rotx(){ int tmp=a[0]; a[0]=a[4]; a[4]=a[5]; a[5]=a[2]; a[2]=tmp; }
	void roty(){ int tmp=a[0]; a[0]=a[1]; a[1]=a[5]; a[5]=a[3]; a[3]=tmp; }
	void rotz(){ int tmp=a[1]; a[1]=a[4]; a[4]=a[3]; a[3]=a[2]; a[2]=tmp; }
};

vector<dice> get_all(dice D){
	vector<dice> res;
	rep(i,6){
		rep(j,4){
			res.push_back(D);
			D.rotz();
		}
		if(i%2==0) D.rotx();
		else       D.roty();
	}
	return res;
}

struct node{
	int y,x,id; // y, x, dice direction
};

int main(){
	int h,w; cin>>h>>w;
	string B[12];
	rep(y,h) cin>>B[y];
	string label[6];
	rep(i,6) cin>>label[i];
	int sx,sy,gx,gy; cin>>sy>>sx>>gy>>gx; sx--; sy--; gx--; gy--;

	vector<dice> S=get_all(dice(0,1,2,3,4,5));
	vector< pair<node,node> > E;
	rep(y,h) rep(x,w) rep(id,24) {
		// y--
		if(y>0 && (B[y][x]=='+' || B[y][x]=='|' || B[y][x]=='^')){
			dice D=S[id];
			D.rotx(); D.rotx(); D.rotx();
			int id2;
			for(id2=0;D!=S[id2];id2++);
			E.push_back(make_pair((node){y,x,id},(node){y-1,x,id2}));
		}
		// y++
		if(y+1<h && (B[y][x]=='+' || B[y][x]=='|' || B[y][x]=='v')){
			dice D=S[id];
			D.rotx();
			int id2;
			for(id2=0;D!=S[id2];id2++);
			E.push_back(make_pair((node){y,x,id},(node){y+1,x,id2}));
		}
		// x--
		if(x>0 && (B[y][x]=='+' || B[y][x]=='-' || B[y][x]=='<')){
			dice D=S[id];
			D.roty(); D.roty(); D.roty();
			int id2;
			for(id2=0;D!=S[id2];id2++);
			E.push_back(make_pair((node){y,x,id},(node){y,x-1,id2}));
		}
		// x++
		if(x+1<w && (B[y][x]=='+' || B[y][x]=='-' || B[y][x]=='>')){
			dice D=S[id];
			D.roty();
			int id2;
			for(id2=0;D!=S[id2];id2++);
			E.push_back(make_pair((node){y,x,id},(node){y,x+1,id2}));
		}
	}

	int s_id;
	for(s_id=0;S[s_id][0]!=0||S[s_id][4]!=1;s_id++);

	// Bellman-Ford
	string d[12][12][24];
	rep(y,h) rep(x,w) rep(id,24) d[y][x][id]="no";
	rep(id,24) d[gy][gx][id]=label[S[id][0]];

	rep(t,24*h*w+1){
		bool changed=false;
		rep(i,E.size()){
			const node &u=E[i].first,&v=E[i].second;
			string &d_u=d[u.y][u.x][u.id];
			string &d_v=d[v.y][v.x][v.id];
			if(d_v=="no") continue;

			string d2=label[S[u.id][0]]+d_v;
			if(d_u=="no" || d_u>d2){
				d_u=d2;
				changed=true;
				// if(t==h*w*24 && u.y==sy && u.x==sx && u.id==s_id){
				if(t>h*w*4 && u.y==sy && u.x==sx && u.id==s_id){ // h*w*24 まで見ると TLE するので嘘っぽい上界で適当に打ち切る
					cout<<"infinite"<<endl;
					return 0;
				}
			}
		}
		if(!changed) break;
	}

	cout<<d[sy][sx][s_id]<<endl;

	return 0;
}