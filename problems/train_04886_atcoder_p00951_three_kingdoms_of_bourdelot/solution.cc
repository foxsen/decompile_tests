#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
map<string,int>myhash;
int hashclock=0;
int g[2000][310][310];
vector<int>fg[310][310];
bool visit[2000];
int n;
int getnu(){
	string tss;
	cin>>tss;
	if(myhash.count(tss))
		return myhash[tss];
	hashclock++;
	myhash[tss]=hashclock;
	return hashclock;
}
void floyd(int i){
	for(int j=1;j<=hashclock;j++)
		for(int a=1;a<=hashclock;a++)
			for(int b=1;b<=hashclock;b++)
				if((g[i][a][j]!=0)&&(g[i][j][b]!=0))
					g[i][a][b]=1;
}
bool getans(){
	int x,y;
	x=getnu();
	y=getnu();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			int a=getnu(),b=getnu();
			g[i][a][b]=1;
			fg[a][b].push_back(i);
		}
	}
	bool flag=1;
	g[0][x][y]=1;
	while(flag){
		flag=0;
		for(int i=1;i<=hashclock;i++)
			for(int j=1;j<=hashclock;j++)
				if(g[0][i][j]){
					for(vector<int>::iterator it=fg[i][j].begin();it!=fg[i][j].end();it++)
						if(visit[*it]==false){
							for(int a=1;a<=hashclock;a++)
								for(int b=1;b<=hashclock;b++)
									if(g[*it][a][b])
										g[0][a][b]=1;
							visit[*it]=true;
							flag=1;
						}
				}
		floyd(0);
	}
	for(int i=1;i<=hashclock;i++)
		for(int j=1;j<=hashclock;j++)
			if((g[0][i][j]!=0)&&(g[0][j][i]!=0)){
				//cout<<i<<endl<<j<<endl;
				return 0;

			}
	return 1;

}
int main(){
    //freopen("in2.txt","r+",stdin);
	if(getans()){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}