//2017-11-5
//miaomiao
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define ppb pop_back
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)

#define N (300000+5)

vector<int> ans;

int main(){	
	int k, n;
	scanf("%d%d", &k, &n);
	
	if(!(k&1)){
		printf("%d", k/2);
		For(i, 2, n) printf(" %d", k);
		return 0;
	}
	
	For(i, 1, n) ans.pb((k+1)/2);
	int nn = n / 2;

	while(nn--){
		if(ans.back() == 1) ans.ppb();
		else{
			--ans.back();
			For(i, ans.size()+1, n) ans.pb(k);
		}
	}

	For(i, 0, ans.size()-1) printf("%d%c", ans[i], i==((int)ans.size()-1)? '\n': ' ');

	return 0;
}