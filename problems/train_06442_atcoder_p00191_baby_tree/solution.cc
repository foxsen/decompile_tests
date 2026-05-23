#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

double g[10][100][100];
double ans[100][100];
double ans_dummy[100][100];

int n, m;

void multi(double a[100][100], double b[100][100], double c[100][100]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			double max = 0;
			for(int k = 0; k < n; k++){
				if(a[i][k] * b[k][j] > max){
					max = a[i][k] * b[k][j];
				}
			}
			c[i][j] = max;
		}
	}
}

int main(){
	
	while(true){
		
		cin >> n >> m;
		
		if(n == 0 && m == 0){
			break;
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> g[0][i][j];
				ans[i][j] = 1;
			}
		}
		
		m--;
		
		for(int i = 0; i < 9; i++){
			multi(g[i], g[i], g[i + 1]);
			if(m % 2 == 1){
				multi(ans, g[i], ans_dummy);
				for(int j = 0; j < n; j++){
					for(int k = 0; k < n; k++){
						ans[j][k] = ans_dummy[j][k];
						//cout << ans[j][k] << " ";
					}
					//cout << endl;
				}
			}
			m /= 2;
		}
		
		double max = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(max < ans[i][j]){
					max = ans[i][j];
				}
			}
		}
		
		printf("%.2f\n", max);
		
	}
	
	return 0;
}