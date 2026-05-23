// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1100, mod = 1e9 + 7, inf = 1e9 + 10;

bool a[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    int N = max(n, m);
    for(int i = 1; i <= N; i++){
	for(int x = 0; x < (1<<i); x++)
	    for(int y = 0; y < (1<<i); y++)
		a[x][y] = a[x & ((1<<(i-1))-1)][y & ((1<<(i-1))-1)] ^ ( bit(x, i-1) && bit(y, i-1) );
    }    
    for(int i = 1; i < (1<<n); i++){
	for(int j = 1; j < (1<<m); j++)
	    cout << (a[i][j] ^  a[i-1][j] ^ a[i][j-1] ^ a[i-1][j-1]);
	cout << "\n";
    }
    return 0;
}
