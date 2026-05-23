#include <iostream>
using namespace std;
int DP[1001][1001];
int pt[1001][1001];
int main() {
	while(true){
	int H,W,N;

	int lastX=1,lastY=1;
	cin >> H >> W >> N;
		if(H==0)
	break;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
			cin >> pt[j][i];
	DP[1][1]=N-1;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
			if(i!=1|| j!=1 ){
			DP[j][i]=DP[j][i-1]/2+DP[j-1][i]/2;
			if(pt[j][i-1]==0 && DP[j][i-1] %2 ==1)
			DP[j][i]++;
			if(pt[j-1][i]==1 && DP[j-1][i] %2 ==1)
			DP[j][i]++;
			}
	while(lastX<=W && lastY<=H){
		if((DP[lastX][lastY]+pt[lastX][lastY])%2==1)
		lastX++;
		else
		lastY++;
	}
	cout << lastY << " " << lastX << endl;
	}
	return 0;
}