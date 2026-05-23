#include<cstdio>

using namespace std;

const int dx[]={1,-1,-1,1},dy[]={-1,-1,1,1};

int main(){
	for(int n;scanf("%d ",&n),~n;){
		bool mirror[17][17]={};
		for(int k=0;k<n;k++){
			char d;
			int i,j;
			scanf("%c%d%d ",&d,&j,&i);
			if(d=='x')	mirror[2*i][2*j+1]=true;
			else		mirror[2*i+1][2*j]=true;
		}

		int x=1,y=0,dir=3;
		bool loop=false;
		for(int t=0;;t++){
			x+=dx[dir],y+=dy[dir];
			if(mirror[y][x]){
				if(y%2==0){
					switch(dir){
						case 0:	dir=3;	break;
						case 1:	dir=2;	break;
						case 2:	dir=1;	break;
						case 3:	dir=0;	break;
					}
				}
				else{
					switch(dir){
						case 0:	dir=1;	break;
						case 1:	dir=0;	break;
						case 2:	dir=3;	break;
						case 3:	dir=2;	break;
					}
				}
			}
			else{
				if(x==0 || x==16 || y==0 || y==16)	break;
				int bx=x-dx[dir],by=y-dy[dir];
				if(t>1 && x+bx==3 && y+by==1){ loop=true; break; }
			}
		}

		if(loop)	puts("75 25");
		else		printf("%d %d\n",50*x,50*y);
	}

	return 0;
}