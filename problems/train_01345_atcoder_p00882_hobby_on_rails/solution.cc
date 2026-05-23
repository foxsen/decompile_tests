#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
char in[2];
char t[8][8];
int conv[8][8];
int H,W;
int ret;
int used[20][20];
int pr[8];
int pc[8];
int pd[8];
int lr[4][3]={{1,1,0},{0,2,1},{1,1,2},{2,0,1}};
int lc[4][3]={{0,2,1},{1,1,2},{2,0,1},{1,1,0}};
int rr[4][3]={{1,1,2},{0,2,1},{1,1,0},{2,0,1}};
int rc[4][3]={{0,2,1},{1,1,0},{2,0,1},{1,1,2}};
int at[8][3];
int au[8][3];
int al[8][3];
int ps;
int v[8][3][1<<6];
void go(int a,int b){
	for(int i=0;i<ps;i++)for(int j=0;j<3;j++)for(int k=0;k<(1<<ps);k++)v[i][j][k]=-1;
	int len=0;
	int A=a;
	int B=b;
	int bit=0;
	while(1){
		v[A][B][bit]=len;
		len+=al[A][B]+1;
		int ta=at[A][B];int tb=au[A][B];
		A=ta;
		if(tb==0){
			if(bit&(1<<A))B=1;
			else B=2;
			bit^=(1<<A);
		}else B=0;
		if(~v[A][B][bit])break;
	}
	ret=max(ret,len-v[A][B][bit]);
}
void calc(){
	/*for(int i=0;i<ps;i++){
		for(int j=0;j<3;j++){
			printf("(%d, %d, %d)",at[i][j],au[i][j],al[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	for(int i=0;i<ps;i++)for(int j=0;j<3;j++){
		go(i,j);
	}
}
void dfs_route(int P1,int P2,int TR,int TC,int MR,int MC,int L){
	if(MR<0||MC<0||MR>=H||MC>=W)return;
	if(~conv[MR][MC]){
		int M=conv[MR][MC];
		bool ok=false;
		for(int i=0;i<3;i++){
			if(!~at[M][i]&&((t[MR][MC]=='L'&&TR==MR*2+lr[pd[M]][i]&&TC==MC*2+lc[pd[M]][i])||(t[MR][MC]=='R'&&TR==MR*2+rr[pd[M]][i]&&TC==MC*2+rc[pd[M]][i]))){
				at[P1][P2]=M;au[P1][P2]=i;
				at[M][i]=P1;au[M][i]=P2;
				al[P1][P2]=al[M][i]=L;
				ok=true;break;
			}
		}
		if(!ok)return;
		for(int i=0;i<ps;i++){
			for(int j=0;j<3;j++){
				if(!~at[i][j]){
					int sr=pr[i]*2;
					int sc=pc[i]*2;
					int kr=pr[i];int kc=pc[i];
					if(t[pr[i]][pc[i]]=='L'){sr+=lr[pd[i]][j];sc+=lc[pd[i]][j];
					if(lr[pd[i]][j]==0)kr--;if(lr[pd[i]][j]==2)kr++;
					if(lc[pd[i]][j]==0)kc--;if(lc[pd[i]][j]==2)kc++;}
					if(t[pr[i]][pc[i]]=='R'){sr+=rr[pd[i]][j];sc+=rc[pd[i]][j];
					if(rr[pd[i]][j]==0)kr--;if(rr[pd[i]][j]==2)kr++;
					if(rc[pd[i]][j]==0)kc--;if(rc[pd[i]][j]==2)kc++;}
					dfs_route(i,j,sr,sc,kr,kc,0);
					at[at[P1][P2]][au[P1][P2]]=au[at[P1][P2]][au[P1][P2]]=-1;
					at[P1][P2]=au[P1][P2]=-1;
					return;
				}
			}
		}
		calc();
		at[at[P1][P2]][au[P1][P2]]=au[at[P1][P2]][au[P1][P2]]=-1;
		at[P1][P2]=au[P1][P2]=-1;
		return;
	}
	if(used[MR][MC])return;
	used[MR][MC]=1;
	if(t[MR][MC]=='S'){
		int nr,nc,mr,mc;
		if(TR%2){
			nr=TR;nc=MC*4+2-TC;
			mr=MR;mc=(nc-MC-1);
		}else{
			nc=TC;nr=MR*4+2-TR;
			mc=MC;mr=(nr-MR-1);
		}
		dfs_route(P1,P2,nr,nc,mr,mc,L+1);
	}else{
		if(TR%2){
			dfs_route(P1,P2,MR*2,MC*2+1,MR-1,MC,L+1);
			dfs_route(P1,P2,MR*2+2,MC*2+1,MR+1,MC,L+1);
		}else{
			dfs_route(P1,P2,MR*2+1,MC*2,MR,MC-1,L+1);
			dfs_route(P1,P2,MR*2+1,MC*2+2,MR,MC+1,L+1);
		}
	}
	used[MR][MC]=0;
}
void dfs_dir(int a){
	if(a==ps){
		for(int i=0;i<ps;i++)for(int j=0;j<3;j++){
			at[i][j]=au[i][j]=-1;
		}
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)used[i][j]=0;
		int sr=pr[0]*2;
		int sc=pc[0]*2;
		int kr=pr[0];int kc=pc[0];
		if(t[pr[0]][pc[0]]=='L'){sr+=lr[pd[0]][0];sc+=lc[pd[0]][0];
		if(lr[pd[0]][0]==0)kr--;if(lr[pd[0]][0]==2)kr++;
		if(lc[pd[0]][0]==0)kc--;if(lc[pd[0]][0]==2)kc++;}
		if(t[pr[0]][pc[0]]=='R'){sr+=rr[pd[0]][0];sc+=rc[pd[0]][0];
		if(rr[pd[0]][0]==0)kr--;if(rr[pd[0]][0]==2)kr++;
		if(rc[pd[0]][0]==0)kc--;if(rc[pd[0]][0]==2)kc++;}
		dfs_route(0,0,sr,sc,kr,kc,0);
		return;
	}
	for(int i=0;i<4;i++){
		pd[a]=i;
		dfs_dir(a+1);
	}
}
int main(){
	int a,b;
	while(scanf("%d%d",&b,&a),a){
		H=a;W=b;
		for(int i=0;i<a;i++)for(int j=0;j<b;j++){
			scanf("%s",in);
			t[i][j]=in[0];
		}
		for(int i=0;i<a;i++)for(int j=0;j<b;j++)conv[i][j]=-1;
		ret=0;
		ps=0;
		for(int i=0;i<a;i++)for(int j=0;j<b;j++){
			if(t[i][j]=='L'||t[i][j]=='R'){
				conv[i][j]=ps;
				pr[ps]=i;pc[ps++]=j;
			}
		}
		if(ps%2){
			printf("0\n");continue;
		}
		dfs_dir(0);
		printf("%d\n",ret);
	}
}