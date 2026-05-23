#include<bits/stdc++.h>
using namespace std;
#define M 100005
vector<int>edge[M];
int Get_sg(int x,int pre){
	int res=0;
	for(int i=0;i<edge[x].size();i++)
		if(edge[x][i]!=pre)res^=(Get_sg(edge[x][i],x)+1);
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	if(Get_sg(1,-1))puts("Alice");
	else puts("Bob");  
	return 0;
}  