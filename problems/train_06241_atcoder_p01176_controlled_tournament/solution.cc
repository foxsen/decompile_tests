#include <iostream>
#include <cstring>

using namespace std;

static int mem[16][1<<16][5];
int vs[16][16];
int lg[16] = {1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4};

int search(int win, int lose, int cnt, int n){
	if(~mem[win][lose][cnt]) return mem[win][lose][cnt];
	if(!lose) return mem[win][lose][cnt] = 1;
	if(cnt == 0) return mem[win][lose][cnt] = 0;
	int res = 0, loseBit = 0;
	for(int t=lose;t;t&=(t-1)) loseBit++;
	if(lg[loseBit] > cnt) return mem[win][lose][cnt] = 0;
	for(int i=0;i<n;i++){
		if(!(lose&(1<<i))) continue;
		if(!vs[win][i]) continue;
		int mask = lose^(1<<i);
		int b = mask;
		do{
			res += search(win, b, cnt-1, n) * search(i, mask^b, cnt-1, n);
			b = (b-1)&mask;
		} while (b != mask);
	}
	return mem[win][lose][cnt] = res;
}

int main(){
	int n, m;
	while(cin >> n >> m, n){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin >> vs[i][j];
		memset(mem,-1,sizeof(mem));
		cout << search(m-1, (((1<<n)-1)^(1<<(m-1))), lg[n-1], n) << endl;
	}
}