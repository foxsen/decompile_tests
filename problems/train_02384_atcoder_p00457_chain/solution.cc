#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n;

int search(int num, int a[20000]){
	int ref = a[num];
	int ans = 0;
	for(int i = 1; i <= 3; i++){
		a[num] = i;
		int ind1 = num;
		int ind2 = num;
		int ind1_p = ind1;
		int ind2_p = ind2;
		while(true){
			if(ind1 < 0 || ind2 > n - 1){
				break;
			}
			if(a[ind1] != a[ind2]){
				break;
			}
			int cnt = 2;
			if(ind1 == ind2){
				cnt--;
			}
			while(ind1 > 0 && a[ind1] == a[ind1 - 1]){
				ind1--;
				cnt++;
			}
			while(ind2 < n - 1 && a[ind2] == a[ind2 + 1]){
				ind2++;
				cnt++;
			}
			if(cnt < 4){
				break;
			}
			ind1_p = ind1;
			ind2_p = ind2;
			ind1--;
			ind2++;
		}
		//cout << num << " " << i << " " << ind1_p << " " << ind2_p << endl;
		ans = max(ans, ind2_p - ind1_p + 1);
	}
	a[num] = ref;
	if(ans < 4){
		ans = 0;
	}
	return ans;
}

int main(){
	
	int a[20000];
	
	while(true){
		cin >> n;
		if(n == 0){
			break;
		}
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans = max(ans, search(i, a));
		}
		cout << n - ans << endl;
	}
	
	return 0;
}