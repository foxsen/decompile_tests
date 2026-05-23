#include <iostream>
using namespace std;

// 入力
int dx[4], dy[4];
// used[y][x] := (y,x) にカードをおいたかどうか
bool used[4][4];

int solve(int n){
	if(n == 0) return 1;
	
	int res = 0;
	
	// 1 枚目のカードを置く
	int x1, y1;
	for( y1 = 0 ; y1 < 4 ; y1++ ){
		for( x1 = 0 ; x1 < 4 ; x1++ ){
			if( !used[y1][x1] ) break;
		}
		if( x1 != 4 ) break;
	}
	used[y1][x1] = true;
	
	// 2 枚目のカードを置く
	for(int i=0 ; i < 4 ; i++ ){
		int mx = x1 + dx[i];
		int my = y1 + dy[i];
		if( mx < 0 || my < 0 || mx >= 4 || my >= 4 || used[my][mx] ) continue;
		used[my][mx] = true;
		res += solve(n-1);
		used[my][mx] = false;
	}
	
	used[y1][x1] = false;
	return res;
}

int main(){
	while( cin >> dx[0] ){
		if( dx[0] > 4 ) break;
		
		cin >> dy[0];
		for(int i=1 ; i < 4 ; i++ ){
			cin >> dx[i] >> dy[i];
		}
		
		// 初期化
		for(int y=0 ; y < 4 ; y++ ){
			for(int x=0 ; x < 4 ; x++ ){
				used[y][x] = false;
			}
		}
		int ans = solve(8);
		cout << ans << endl;
	}
}