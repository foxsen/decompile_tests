#include<map>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

typedef	vector<int>	vi;

void rotx(vi &v){
	vi t=v;
	v[0]=t[3];	v[1]=t[2];	v[2]=t[6];	v[3]=t[7];
	v[4]=t[0];	v[5]=t[1];	v[6]=t[5];	v[7]=t[4];
}

void roty(vi &v){
	vi t=v;
	v[0]=t[4];	v[1]=t[0];	v[2]=t[3];	v[3]=t[7];
	v[4]=t[5];	v[5]=t[1];	v[6]=t[2];	v[7]=t[6];
}

void rotz(vi &v){
	vi t=v;
	v[0]=t[3];	v[1]=t[0];	v[2]=t[1];	v[3]=t[2];
	v[4]=t[7];	v[5]=t[4];	v[6]=t[5];	v[7]=t[6];
}

vi findRegularPaint(vi a){
	vi reg=a;
	rep(i,4){
		rep(j,4){
			reg=min(reg,a);
			rotz(a);
		}
		rotx(a);
	}
	roty(a);
	rep(i,4){
		reg=min(reg,a);
		rotz(a);
	}
	roty(a),roty(a);
	rep(i,4){
		reg=min(reg,a);
		rotz(a);
	}

	return reg;
}

int vi2int(const vi &a){
	int res=0;
	rep(i,a.size())	res=res*10+a[i];
	return res;
}

int main(){
	while(1){
		string s[8];
		rep(i,8) if(!(cin>>s[i])) return 0;

		int clr[8];
		{
			int id=0;
			map<string,int> colorid;
			rep(i,8){
				if(colorid.count(s[i])==0)	colorid[s[i]]=id++;
				clr[i]=colorid[s[i]];
			}
		}
		sort(clr,clr+8);

		set<int> cube;
		do{
			cube.insert(vi2int(findRegularPaint(vi(clr,clr+8))));
		}while(next_permutation(clr+1,clr+8));

		cout<<cube.size()<<endl;
	}
}