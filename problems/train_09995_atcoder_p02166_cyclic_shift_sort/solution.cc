#include <iostream>
#include <utility>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#define llint long long
#define mod 998244353
#define eps 1e-8

using namespace std;

struct BIT{
	int size;
	vector<int> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	int query(int i){
		int ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, int x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n, k;
llint p[100005];
BIT bit(100005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	if(n == k){
		for(int i = 0; i < n; i++) p[i] = p[i+1]-1;
		int x;
		for(int i = 0; i < n; i++){
			if(p[i] == 0){
				x = i;
				break;
			}
		}
		for(int i = 0; i < n; i++){
			if(p[(x+i)%n] != i){
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
		return 0;
	}
	
	int inv = 0;
	for(int i = 1; i <= n; i++){
		inv += (i-1) - bit.query(p[i]);
		bit.add(p[i], 1);
	}
	///cout << inv << endl;
	
	if(k % 2 == 0) cout << "Yes" << endl;
	else{
		if(inv % 2 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
