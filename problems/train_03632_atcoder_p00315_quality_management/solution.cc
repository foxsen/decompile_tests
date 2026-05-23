#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x,y;
};
typedef vector<Point>V_Point;
char box[1001][1002];
int box1[1001][1001];
int flg[1000][1000]={0};
int main(void){
	int q,n,m;
	int w,h;
	int x,y;
	int a1,b1,a2,b2,a3,b3;
	int flag,flag2;
	int cnt;
	int mis;
	int i,j;
	Point pp;
	V_Point v;
	cin>>q>>m;
	// printf("q=%d m=%d\n",q,m);
	w=m;	h=m;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cin>>box[i][j];
		}
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			box1[i+1][j+1]=box[i][j]-'0';
		}
	}
	// for(i=1;i<=h;i++){
		// for(j=1;j<=w;j++){
			// cout<<box[i][j];
		// }
		// cout<<endl;
	// }
	mis=0;
	for(i=1;i<=h/2;i++){
		for(j=1;j<=w/2;j++){
			flag=0;	
			a1=i;		b1=w+1-j;
			a2=h+1-i;	b2=w+1-j;
			a3=h+1-i;	b3=j;
			if(box1[i][j]!=box1[a1][b1])		flag=1;
			if(box1[i][j]!=box1[a2][b2])		flag=1;
			if(box1[i][j]!=box1[a3][b3])		flag=1;
			if(flag==1){
				flg[i][j]=1;
				flg[a1][b1]=1;
				flg[a2][b2]=1;
				flg[a3][b3]=1;
				// printf("i=%d j=%d\n",i,j);
				mis++;
			}
			// if(i==1&&j==3||i==4&&j==3){
				// printf("left_up    y=%d x=%d\n",i,j);
				// printf("right_up   y=%d x=%d\n",a1,b1);
				// printf("right_down y=%d x=%d\n",a2,b2);
				// printf("left_down  y=%d x=%d\n",a3,b3);
			// }
		}
	}
	// printf("mistake=%d\n",mis);
	cnt=0;
	if(mis==0)	cnt++;
	// printf("cnt_now=%d\n",cnt);
	for(i=0;i<q-1;i++){
		// printf("cloth_now=%d\n",i+2);
		// printf("mistake_now=%d\n",mis);
		cin>>n;
		// printf("n=%d\n",n);
		v.clear();
		for(j=0;j<n;j++){
			cin>>y>>x;
			// printf("y=%d x=%d\n",y,x);
			if(box1[y][x]==0)	box1[y][x]=1;
			else				box1[y][x]=0;
			pp.y=y;	pp.x=x;
			v.push_back(pp);
		}
		// printf("check2\n");
		for(j=0;j<(int)v.size();j++){
			flag=0;
			pp=v[j];
			a1=pp.y;		b1=w+1-pp.x;
			a2=h+1-pp.y;	b2=w+1-pp.x;
			a3=h+1-pp.y;	b3=pp.x;
			// printf("y=%d x=%d map=%c flg=%d\n",pp.y,pp.x,box[pp,y][pp.x],flg[pp.y][pp.x]);
			// printf("y=%d x=%d map=%c\n",a1,b1,box[a1][b1]);
			// printf("y=%d x=%d map=%c\n",a2,b2,box[a2][b2]);
			// printf("y=%d x=%d map=%c\n",a3,b3,box[a3][b3]);
			// printf("\n");
			if(flg[pp.y][pp.x]==1){
				if(box1[pp.y][pp.x]==box1[a1][b1]&&box1[a1][b1]==box1[a2][b2]&&box1[a2][b2]==box1[a3][b3]){
					mis--;
					flg[pp.y][pp.x]=0;
					flg[a1][b1]=0;
					flg[a2][b2]=0;
					flg[a3][b3]=0;
				}
			}
			else{
				if(!(box1[pp.y][pp.x]==box1[a1][b1]&&box1[a1][b1]==box1[a2][b2]&&box1[a2][b2]==box1[a3][b3])){
					mis++;
					flg[pp.y][pp.x]=1;
					flg[a1][b1]=1;
					flg[a2][b2]=1;
					flg[a3][b3]=1;
				}
			}
		}
		// printf("mistake_next=%d\n",mis);
		if(mis==0){
			cnt++;
			// printf("i=%d cnt_now=%d\n",i+2,cnt);
		}
	}
	cout<<cnt<<endl;
	return 0;
}
		
	
	
	
	
	
	
	
