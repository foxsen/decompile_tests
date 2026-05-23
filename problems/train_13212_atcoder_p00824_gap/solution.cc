#include<set>
#include<queue>
#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct board{
	int a[4][8];
	bool operator<(const board &B)const{
		rep(i,4) rep(j,8) if(a[i][j]!=B.a[i][j]) return a[i][j]<B.a[i][j];
		return false;
	}
};

bool isgoal(const board &B){
	rep(i,4) rep(j,7) if(B.a[i][j]!=(i+1)*10+(j+1)) return false;
	return true;
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		board B0;
		rep(i,4){
			B0.a[i][0]=(i+1)*10+1;
			rep(j,7){
				int a; scanf("%d",&a);
				B0.a[i][j+1]=(a%10==1?-1:a);
			}
		}

		set<board> Vis; // すでに訪れた盤面
		Vis.insert(B0);

		int ans=-1;
		queue< pair<int,board> > Q;
		Q.push(make_pair(0,B0));
		while(!Q.empty()){
			int t=Q.front().first;
			board B=Q.front().second; Q.pop();

			if(isgoal(B)){ ans=t; break; }

			static int x[48],y[48];
			rep(i,4) rep(j,8) if(B.a[i][j]!=-1) {
				x[B.a[i][j]]=j;
				y[B.a[i][j]]=i;
			}
			rep(i,4) rep(j,8) if(B.a[i][j]==-1) {
				int left=B.a[i][j-1];
				if(left%10<7 && left!=-1){
					int tmp=B.a[y[left+1]][x[left+1]];
					B.a[i][j]=left+1;
					B.a[y[left+1]][x[left+1]]=-1;

					if(Vis.count(B)==0){
						Vis.insert(B);
						Q.push(make_pair(t+1,B));
					}

					B.a[i][j]=-1;
					B.a[y[left+1]][x[left+1]]=tmp;
				}
			}
		}

		printf("%d\n",ans);
	}

	return 0;
}