#include <cstdio>
int exist[1001][1001][3]={};
char field[1001][1001];
int m,n,Q;
int main(){
	scanf("%d %d %d",&m,&n,&Q);
	for(int i=0;i<m;i++){
			scanf("%s",field[i]);
	}
	for(int i=0;i<m;i++){
		for(int j=i+1;j<=m;j++){
			if(field[i][0]=='J'){
				exist[j][1][0]++;
			}else if(field[i][0]=='O'){
				exist[j][1][1]++;
			}else{
				exist[j][1][2]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(field[0][i]=='J'){
				exist[1][j][0]++;
			}else if(field[0][i]=='O'){
				exist[1][j][1]++;
			}else{
				exist[1][j][2]++;
			}
		}
	}
	if(field[0][0]=='J'){
		exist[1][1][0]=1;
	}else if(field[0][0]=='O'){
		exist[1][1][1]=1;
	}else{
		exist[1][1][2]=1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<3;k++){
			exist[i][j][k]=exist[i][j-1][k];
			}
			for(int k=0;k<i;k++){
				if(field[k][j-1]=='J'){
					exist[i][j][0]++;
				}else if(field[k][j-1]=='O'){
					exist[i][j][1]++;
				}else{
					exist[i][j][2]++;
				}
			}
		}
	}
	for(int i=0;i<Q;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
			int J=exist[c][d][0]-exist[c][b-1][0]-exist[a-1][d][0]+exist[a-1][b-1][0];
			int O=exist[c][d][1]-exist[c][b-1][1]-exist[a-1][d][1]+exist[a-1][b-1][1];
			printf("%d %d %d\n",J,O,(c-a+1)*(1+d-b)-J-O);
	}
	return 0;
}