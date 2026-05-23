#include <iostream>
#include <algorithm>

using namespace std;

struct P{
	int v;
	int n;
};

int func(P cd[7], int m, int n, int c, int p)
{
	if(c > n){
		return 0;
	}
	if(c == n){
		return 1;
	}
	int s=0;
	for(int i = p; i < m; i++){
		if(cd[i].n > 0){
			cd[i].n--;
			s += func(cd, m, n, c+cd[i].v, i);
			cd[i].n++;
		}
	}
	
	return s;
}

int main()
{
	int n, m, g;
	P cd[7];
	
	while(cin >> m && m){
		for(int i = 0; i < m; i++){
			cin >> cd[i].v >> cd[i].n;
		}
		cin >> g;
		for(int i = 0; i < g; i++){
			cin >> n;
			cout << func(cd, m, n, 0, 0) << endl;
		}
	}
	
	return 0;
}