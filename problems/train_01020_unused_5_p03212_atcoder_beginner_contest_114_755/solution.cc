#include <cstdio>
int N,count=0;
void dfs(long long nextnum,unsigned	char flag){
	if(nextnum<=N){
		if(flag==7){
			count++;
		}
		dfs(nextnum*10+3,flag|01);
		dfs(nextnum*10+5,flag|02);
		dfs(nextnum*10+7,flag|04);
	}
} 
int main(){
	scanf("%d",&N);
	dfs(0,0);
	printf("%d",count);
	return 0;
}