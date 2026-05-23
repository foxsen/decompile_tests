#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

template<int um> class UF { // from kmjp
public:
	vector<int> par;
	UF() { par = vector<int>(um, 0); rep(i, 0, um) par[i] = i; }
	int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
	void operator()(int x, int y)
	{
		x = operator[](x); y = operator[](y);
		if (x != y) par[x] = y;
	}
};
//-----------------------------------------------------------------
int N, W, H;
int X[40101], Y[40101];
UF<40101> uf;
//-----------------------------------------------------------------
int main() {
	cin >> N >> W >> H;
	rep(i, 0, N) cin >> X[i] >> Y[i];

	rep(i, 0, N) rep(j, i + 1, N) if (X[i] == X[j] || Y[i] == Y[j]) uf(i, j);

	bool isWall = false;
	rep(i, 0, N) if ((X[i] == 1 || X[i] == W) || (Y[i] == 1 || Y[i] == H)) isWall = true;

	int ans = 0;
	rep(i, 0, N) if (uf[i] == i) ans++;

	if (ans == 1)
		ans = N - 1;
	else {
		if (isWall) ans--;
		ans += N - 1;
	}	

	cout << ans << endl;
}