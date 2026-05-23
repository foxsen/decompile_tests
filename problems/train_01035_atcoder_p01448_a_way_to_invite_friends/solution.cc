#include <iostream>
#define llint long long

using namespace std;

llint n;
llint dif[100005];

int main(void)
{
	cin >> n;
	llint l, r;
	for(int i = 1; i <= n; i++){
		cin >> l >> r;
		dif[l]++, dif[r+1]--;
	}
	for(int i = 1; i < 100005; i++) dif[i] += dif[i-1];
	
	llint ans = 0;
	for(int i = n; i >= 1; i--){
		if(dif[i+1] >= i){
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	
	return 0;
}
