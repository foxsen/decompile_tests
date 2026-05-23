#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int N,c[20];

int f(int *c,int l){
	//if(!l)return 0;
	int res=l;
	//cout<<l<<": ";rep(i,20)cout<<c[i]<<(i<19?" ":"\n");
	rep(i,l){
		//cout<<"i"<<i<<" ";
		if(c[i]==-1)break;
		if(i%4<3&&c[i]==c[i+1]){
			//if(l==2)return 0;
			int d[20];
			rep(j,20)d[j]=c[j];
			for(int j=i;j<l-2;j++)d[j]=d[j+2];
			d[l-2]=-1;d[l-1]=-1;
			res=min(res,f(d,l-2));
		}
		if(i/4<4&&c[i]==c[i+4]){
			//if(l==2)return 0;
			int d[20];
			rep(j,20)d[j]=c[j];
			for(int j=i;j<=i+2;j++)d[j]=d[j+1];
			for(int j=i+3;j<l-2;j++)d[j]=d[j+2];
			d[l-2]=-1;d[l-1]=-1;
			res=min(res,f(d,l-2));
		}
		if(i%4<3&&i/4<4&&c[i]==c[i+5]){
			//if(l==2)return 0;
			int d[20];
			rep(j,20)d[j]=c[j];
			for(int j=i;j<=i+3;j++)d[j]=d[j+1];
			for(int j=i+4;j<l-2;j++)d[j]=d[j+2];
			d[l-2]=-1;d[l-1]=-1;
			res=min(res,f(d,l-2));
		}
		if(i%4>0&&i/4<4&&c[i]==c[i+3]){
			//if(l==2)return 0;
			int d[20];
			rep(j,20)d[j]=c[j];
			for(int j=i;j<=i+1;j++)d[j]=d[j+1];
			for(int j=i+2;j<l-2;j++)d[j]=d[j+2];
			d[l-2]=-1;d[l-1]=-1;
			res=min(res,f(d,l-2));
		}
		//if(!res)return 0;
	}
	//cout<<l<<"return "<<res<<endl;
	return res;
}

int main(){
	cin>>N;
	while(N--){
		rep(i,20)cin>>c[i];
		cout<<f(c,20)<<endl;
	}
}