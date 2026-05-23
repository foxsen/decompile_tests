#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

struct point{
	int x,y;
	point() { x = y = 0; }
	point(int xx, int yy) { x = xx; y = yy; }
	void resize(int n) { x = (x+n)%n; y = (y+n)%n;}
};

int main()
{
	vector< vector<int> > map;
	point p;
	int n, i, j=0;

	while (cin>>n) {
		if (n == 0) break;
		map.clear();
		map.resize( n, vector<int>(n) );
		p = point(n/2, n/2+1);
		map[p.x][p.y] = 1;
		for (i = 2; i <= n*n; i++) {
			p.x++;
			p.y++;
			p.resize(n);
			while ( map[p.x][p.y] != 0 ) {
				p.x--;
				p.y++;
				p.resize(n);
			}
			map[p.x][p.y] = i;
		}
		for (p.y = 0; p.y < n; p.y++) {
			for (p.x = 0; p.x < n; p.x++) {
				cout<<setw(4)<<right<<map[p.x][p.y];
			}
			cout<<endl;
		}
	}

	return 0;
}