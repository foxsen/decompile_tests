#include<stdio.h>
#define OK 128

const int INF = 1<<25;

int di(const int d[OK][OK],int n,int s,int f){
	int i,j,dist[OK],done[OK];
	for(i=1;i<=n;i++){
		dist[i]=INF;
		done[i]=0;
	}
	dist[s]=0;
	
	for(;;){
		int e=-1;
		for(i=1;i<=n;i++) if(done[i]==0 && (e==-1 || dist[i] < dist[e])) e=i;
		
		if(e==-1) break;
		
		done[e]=1;
		if(e==f) return dist[e];
		for(i=1;i<=n;i++){
			int pw=dist[e]+d[e][i];
			if(pw<dist[i]) dist[i]=pw;
		}
		//printf("dist[%d] =%d\n",e,dist[e]);
	}
	return INF;
}

int main(){
	int n,k,f,a,b,c,d,e,i,j,an,is[OK][OK];
	for(;;){
		scanf("%d%d",&n,&k);
		if(!n && !k) break;
		for(i=0;i<=n;i++) for(j=0;j<=n;j++){
			is[i][j]=INF;
			if(i==j)is[i][j]=0;
		}
		
		for(i=0;i<k;i++){
			scanf("%d",&f);
			if(f){
				scanf("%d%d%d",&c,&d,&e);
				if(is[c][d]>e){
					is[c][d]=e;
					is[d][c]=e;
				}
			}
			else{
				scanf("%d%d",&a,&b);
				an=di(is,n,a,b);
				if(an==INF)an=-1;
				printf("%d\n",an);
			}
		}
	}

}