#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

enum{UP,RIGHT,DOWN,LEFT};
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int n;

bool adja(bool data[100][100],int y,int x,int dir){
	int left=(dir+3)%4,right=(dir+1)%4;
	if(  x+dx[left ]>=0 && y+dy[left ]>=0 && x+dx[left ]<n && y+dy[left ]<n && data[y+dy[left ]][x+dx[left ]]==true )return true;
	if(  x+dx[right]>=0 && y+dy[right]>=0 && x+dx[right]<n && y+dy[right]<n && data[y+dy[right]][x+dx[right]]==true )return true;
	return false;
}

int main(){
	int a;
	cin>>a;
	bool f=false;
	rep(i,a){
		if(f)cout<<endl;
		f=true;
		bool data[100][100]={};
		cin>>n;
		
		int dir = UP;
		int y=n-1,x=0;
		
		int change_d_times = 0;
		while(1){
			data[y][x]=true;
			int ddx = x+dx[dir], ddy = y+dy[dir];
			if( ddx>=0 && ddy>=0 && ddx<n && ddy<n && !data[ddy][ddx] && !(ddx+dx[dir]>=0 && ddy+dy[dir]>=0 && ddx+dx[dir]<n && ddy+dy[dir]<n && data[ddy+dy[dir]][ddx+dx[dir]]==true) && !adja(data,ddy,ddx,dir) ){
				data[ddy][ddx]=true;
				change_d_times=0;
				x = ddx , y = ddy;
			}
			else{
				dir = (dir+1)%4;
				change_d_times++;
			}
			if(change_d_times>=5)break;
		}
		rep(i,n){
			rep(j,n){
				if(data[i][j])cout<<"#";
				else cout<<" ";
			}
			cout<<endl;
		}
	}
}