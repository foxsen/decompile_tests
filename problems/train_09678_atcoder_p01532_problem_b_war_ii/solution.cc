#include <cstdio>
#include <vector>
using namespace std;

int solve(){
	int n, t, L;
	scanf("%d%d%*d%d", &n, &t, &L);
	vector<int> ts(n), hs(n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &ts[i], &hs[i]);
	}

	int s = 0;
	int k = 0;
	for( ; ; k = (k + 1) % n){
		if(ts[k]){
			++s;
			if(++t > L){ break; }
			--ts[k];
		}
		else if(hs[k]){
			s += 10;
			--hs[k];
		}
		else{ break; }

		if(s >= 9){
			ts[k] += s - 9;
			t -= s - 9;
			s = 0;

			if(t < 0){
				break;
			}
		}
	}
	return k + 1;
}

int main(){
	printf("%d\n", solve());
}