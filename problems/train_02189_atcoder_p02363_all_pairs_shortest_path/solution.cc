#include <iostream>

using namespace std;

const int N = 100;

const long long INFTY = (1LL << 32);

int n;

long long Graph[N][N];//图的邻接矩阵



void floyd() { //弗洛伊德算法
	for (int k=0; k<n; k++) {
		for (int i = 0; i<n; i++) {
			
			if (Graph[i][k] == INFTY) continue;
			
			for (int j = 0; j<n; j++) {
				if (Graph[k][j] == INFTY) continue;
				
				Graph[i][j] = min(Graph[i][j],Graph[i][k] + Graph[k][j]);
			}
		}
	}
}

int main() {
	int Ne;
	cin >> n >> Ne;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			Graph[i][j] = (i == j ? 0 : INFTY);
		}
	}
	
	for (int i=0; i<Ne; i++) {
		int s,t,d;
		cin >> s >> t >> d;
		Graph[s][t] = d;
	}
	floyd();
	
	for (int i=0;i<n;i++) {
		if (Graph[i][i] < 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
 	}
 	
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (j) {
				cout << " ";
			}
			if (Graph[i][j] == INFTY) {
				cout << "INF";
			} else {
				cout << Graph[i][j];
			}
		}
		cout << endl;
	}
	
}
