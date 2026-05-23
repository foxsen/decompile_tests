#include<cstdio>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

// dp[i][j] := ( i 組のカードがあり、そのうち j 種類の(片方の)場所がわかっている状態でのミスマッチ回数の期待値 )
double dp[501][501];
double dfs(int i,int j){
	if(i==0) return 0;

	if(dp[i][j]!=-1) return dp[i][j];

	// 一枚目を、まだ中身がわかっていない 2*i-j 枚の中から選ぶ
	// 確率 p=j/(2*i-j) で場所が知れているカードと同じ絵柄を引き当てる
	// このとき、二枚目を引いて確実に絵柄を揃えられる
	double res1=0;
	if(j>0) res1+=dfs(i-1,j-1);

	// 確率 1-p で場所が知れていないカードを引き当てる
	// 二枚目を引いたとき
	// - 一枚目と同じ絵柄だった
	// - すでに場所が知れているカードと同じ絵柄だった
	// - まだ場所が知れていないカードだった
	// の三通りが起こりうる
	double res2=0;
	if(i>j){
		res2+=1.0/(2*i-j-1)*dfs(i-1,j);
		if(j> 0 ) res2+=1.0*j/(2*i-j-1)*(dfs(i-1,j)+1);
		if(i>j+1) res2+=1.0*(2*i-2*j-2)/(2*i-j-1)*(dfs(i,j+2)+1);
	}

	double p=1.0*j/(2*i-j);
	return dp[i][j]=p*res1+(1-p)*res2;
}

int main(){
	rep(i,501) rep(j,501) dp[i][j]=-1;
	for(int n;scanf("%d",&n),n;) printf("%.9f\n",dfs(n/2,0));
	return 0;
}