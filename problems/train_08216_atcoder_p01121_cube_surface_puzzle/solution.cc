#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define N 1010000
vector<int>b;
vector<int>s;
vector<int>r;
int n, k;
char a[N];



int main(void) {
	int a[6][4][2];
	int r[6][4][2];
	int num[24][4];
	int d[4];
	vector<int>nummake;
	f(i, 4)nummake.push_back(i);
	f(i, 24) {
		f(j, 4)num[i][j] = nummake[j];
		next_permutation(nummake.begin(), nummake.end());
	}
	bool used[6];
	int b[12];
	int bb[12];
	int n, k, kk, nn;
	int x, y, z;
	int e[4];
	int p[4];
	int q[4];
	char c[10][10];
	bool v, vv;
	while (true) {
		vv = false;
		scanf("%d", &n);
		if (n == 0)return 0;
		k = 1;
		f(i, n)k = k * 2;
		nn = k / 2;
		k--;
		kk = (k / 2) - 1;
		f(i, 6)used[i] = false;
		used[0] = true;
		f(i, 6) {
			f(ii, 10) {
				f(jj, 10)c[ii][jj] = 0;
			}
			f(ii, n)scanf("%s", c[ii]);

			x = 0;
			f(j, n) {
				x *= 2;
				if (c[0][j] == 'X')x++;
			}
			a[i][0][0] = x;
			r[i][0][1] = x;
			x = 0;
			for (int j = n - 1; j >= 0; j--) {
				x *= 2;
				if (c[0][j] == 'X')x++;
			}
			a[i][0][1] = x;
			r[i][0][0] = x;
			x = 0;
			f(j, n) {
				x *= 2;
				if (c[j][n - 1] == 'X')x++;
			}
			a[i][1][0] = x;
			r[i][3][1] = x;
			x = 0;
			for (int j = n - 1; j >= 0; j--) {
				x *= 2;
				if (c[j][n - 1] == 'X')x++;
			}
			a[i][3][1] = x;
			r[i][1][0] = x;
			x = 0;
			for (int j = n - 1; j >= 0; j--) {
				x *= 2;
				if (c[n - 1][j] == 'X')x++;
			}
			a[i][2][0] = x;
			r[i][2][1] = x;
			x = 0;
			f(j, n) {
				x *= 2;
				if (c[n - 1][j] == 'X')x++;
			}
			a[i][2][1] = x;
			r[i][2][0] = x;

			x = 0;
			for (int j = n - 1; j >= 0; j--) {
				x *= 2;
				if (c[j][0] == 'X')x++;
			}
			a[i][3][0] = x;
			r[i][1][1] = x;
			x = 0;
			f(j, n) {
				x *= 2;
				if (c[j][0] == 'X')x++;
			}
			a[i][1][1] = x;
			r[i][3][0] = x;
		}

		f(i, 4)b[i] = a[0][i][0];
		f(i, 40) {
			x = i / 8;
			x++;
			used[x] = true;
			if ((i % 8) < 4) {
				y = i % 4;
				f(j, 4) {
					z = (y + j) % 4;
					b[j + 4] = a[x][z][0];
				}
			}
			else {
				y = i % 4;
				f(j, 4) {
					z = (y + j) % 4;
					b[j + 4] = a[x][z][1];
				}
			}
			x = 0;
			f(j, 6) {
				if (!used[j]) {
					d[x] = j;
					x++;
				}
			}
			f(j, 24) {
				f(ii, 4)e[ii] = d[num[j][ii]];
				f(i0, 8) {
					p[0] = i0 % 4;
					q[0] = i0 / 4;
					x = p[0] % 4;
					bb[0] = r[e[0]][x][q[0]];
					if ((b[0] & bb[0]) != 0)continue;
					if ((kk&(b[0] | bb[0])) != kk)continue;
					x = (p[0] + 1) % 4;
					b[8] = a[e[0]][x][q[0]];
					x = (p[0] + 2) % 4;
					bb[4] = a[e[0]][x][q[0]];
					if ((b[4] & bb[4]) != 0)continue;
					if ((kk&(b[4] | bb[4])) != kk)continue;
					x = (p[0] + 3) % 4;
					b[9] = r[e[0]][x][q[0]];
					f(i1, 8) {
						p[1] = i1 % 4;
						q[1] = i1 / 4;
						x = p[1] % 4;
						bb[1] = r[e[1]][x][q[1]];
						if ((b[1] & bb[1]) != 0)continue;
						if ((kk&(b[1] | bb[1])) != kk)continue;
						x = (p[1] + 1) % 4;
						bb[9] = a[e[1]][x][q[1]];
						if ((b[9] & bb[9]) != 0)continue;
						if ((kk&(b[9] | bb[9])) != kk)continue;
						x = (p[1] + 2) % 4;
						bb[5] = a[e[1]][x][q[1]];
						if ((b[5] & bb[5]) != 0)continue;
						if ((kk&(b[5] | bb[5])) != kk)continue;
						x = (p[1] + 3) % 4;
						b[10] = r[e[1]][x][q[1]];
						f(i2, 8) {
							p[2] = i2 % 4;
							q[2] = i2 / 4;
							x = p[2] % 4;
							bb[2] = r[e[2]][x][q[2]];
							if ((b[2] & bb[2]) != 0)continue;
							if ((kk&(b[2] | bb[2])) != kk)continue;
							x = (p[2] + 1) % 4;
							bb[10] = a[e[2]][x][q[2]];
							if ((b[10] & bb[10]) != 0)continue;
							if ((kk&(b[10] | bb[10])) != kk)continue;
							x = (p[2] + 2) % 4;
							bb[6] = a[e[2]][x][q[2]];
							if ((b[6] & bb[6]) != 0)continue;
							if ((kk&(b[6] | bb[6])) != kk)continue;
							x = (p[2] + 3) % 4;
							b[11] = r[e[2]][x][q[2]];
							f(i3, 8) {
								p[3] = i3 % 4;
								q[3] = i3 / 4;
								x = p[3] % 4;
								bb[3] = r[e[3]][x][q[3]];
								if ((b[3] & bb[3]) != 0)continue;
								if ((kk&(b[3] | bb[3])) != kk)continue;
								x = (p[3] + 1) % 4;
								bb[11] = a[e[3]][x][q[3]];
								if ((b[11] & bb[11]) != 0)continue;
								if ((kk&(b[11] | bb[11])) != kk)continue;
								x = (p[3] + 2) % 4;
								bb[7] = a[e[3]][x][q[3]];
								if ((b[7] & bb[7]) != 0)continue;
								if ((kk&(b[7] | bb[7])) != kk)continue;
								x = (p[3] + 3) % 4;
								bb[8] = r[e[3]][x][q[3]];
								if ((b[8] & bb[8]) != 0)continue;
								if ((kk&(b[8] | bb[8])) != kk)continue;
								if ((b[7] + b[8] + bb[8]) % 2 == 0)continue;
								if ((b[4] + b[9] + bb[9]) % 2 == 0)continue;
								if ((b[5] + b[10] + bb[10]) % 2 == 0)continue;
								if ((b[6] + b[11] + bb[11]) % 2 == 0)continue;
								if ((b[3] + (b[8] / nn) + (bb[8] / nn)) % 2 == 0)continue;
								if ((b[0] + (b[9] / nn) + (bb[9] / nn)) % 2 == 0)continue;
								if ((b[1] + (b[10] / nn) + (bb[10] / nn)) % 2 == 0)continue;
								if ((b[2] + (b[11] / nn) + (bb[11] / nn)) % 2 == 0)continue;
								vv = true;
								break;
							}
							if (vv)break;
						}
						if (vv)break;
					}
					if (vv)break;
				}
				if (vv)break;
			}
			x = (i / 8) + 1;
			used[x] = false;
			if (vv)break;
		}
		if (!vv) {
			f(i, 4)b[i] = a[0][i][1];
			f(i, 40) {
				x = i / 8;
				x++;
				used[x] = true;
				if ((i % 8) < 4) {
					y = i % 4;
					f(j, 4) {
						z = (y + j) % 4;
						b[j + 4] = a[x][z][0];
					}
				}
				else {
					y = i % 4;
					f(j, 4) {
						z = (y + j) % 4;
						b[j + 4] = a[x][z][1];
					}
				}
				x = 0;
				f(j, 6) {
					if (!used[j]) {
						d[x] = j;
						x++;
					}
				}
				f(j, 24) {
					f(ii, 4)e[ii] = d[num[j][ii]];
					f(i0, 8) {
						p[0] = i0 % 4;
						q[0] = i0 / 4;
						x = p[0] % 4;
						bb[0] = r[e[0]][x][q[0]];
						if ((b[0] & bb[0]) != 0)continue;
						if ((kk&(b[0] | bb[0])) != kk)continue;
						x = (p[0] + 1) % 4;
						b[8] = a[e[0]][x][q[0]];
						x = (p[0] + 2) % 4;
						bb[4] = a[e[0]][x][q[0]];
						if ((b[4] & bb[4]) != 0)continue;
						if ((kk&(b[4] | bb[4])) != kk)continue;
						x = (p[0] + 3) % 4;
						b[9] = r[e[0]][x][q[0]];
						f(i1, 8) {
							p[1] = i1 % 4;
							q[1] = i1 / 4;
							x = p[1] % 4;
							bb[1] = r[e[1]][x][q[1]];
							if ((b[1] & bb[1]) != 0)continue;
							if ((kk&(b[1] | bb[1])) != kk)continue;
							x = (p[1] + 1) % 4;
							bb[9] = a[e[1]][x][q[1]];
							if ((b[9] & bb[9]) != 0)continue;
							if ((kk&(b[9] | bb[9])) != kk)continue;
							x = (p[1] + 2) % 4;
							bb[5] = a[e[1]][x][q[1]];
							if ((b[5] & bb[5]) != 0)continue;
							if ((kk&(b[5] | bb[5])) != kk)continue;
							x = (p[1] + 3) % 4;
							b[10] = r[e[1]][x][q[1]];
							f(i2, 8) {
								p[2] = i2 % 4;
								q[2] = i2 / 4;
								x = p[2] % 4;
								bb[2] = r[e[2]][x][q[2]];
								if ((b[2] & bb[2]) != 0)continue;
								if ((kk&(b[2] | bb[2])) != kk)continue;
								x = (p[2] + 1) % 4;
								bb[10] = a[e[2]][x][q[2]];
								if ((b[10] & bb[10]) != 0)continue;
								if ((kk&(b[10] | bb[10])) != kk)continue;
								x = (p[2] + 2) % 4;
								bb[6] = a[e[2]][x][q[2]];
								if ((b[6] & bb[6]) != 0)continue;
								if ((kk&(b[6] | bb[6])) != kk)continue;
								x = (p[2] + 3) % 4;
								b[11] = r[e[2]][x][q[2]];
								f(i3, 8) {
									p[3] = i3 % 4;
									q[3] = i3 / 4;
									x = p[3] % 4;
									bb[3] = r[e[3]][x][q[3]];
									if ((b[3] & bb[3]) != 0)continue;
									if ((kk&(b[3] | bb[3])) != kk)continue;
									x = (p[3] + 1) % 4;
									bb[11] = a[e[3]][x][q[3]];
									if ((b[11] & bb[11]) != 0)continue;
									if ((kk&(b[11] | bb[11])) != kk)continue;
									x = (p[3] + 2) % 4;
									bb[7] = a[e[3]][x][q[3]];
									if ((b[7] & bb[7]) != 0)continue;
									if ((kk&(b[7] | bb[7])) != kk)continue;
									x = (p[3] + 3) % 4;
									bb[8] = r[e[3]][x][q[3]];
									if ((b[8] & bb[8]) != 0)continue;
									if ((kk&(b[8] | bb[8])) != kk)continue;
									if ((b[7] + b[8] + bb[8]) % 2 == 0)continue;
									if ((b[4] + b[9] + bb[9]) % 2 == 0)continue;
									if ((b[5] + b[10] + bb[10]) % 2 == 0)continue;
									if ((b[6] + b[11] + bb[11]) % 2 == 0)continue;
									if ((b[3] + (b[8] / nn) + (bb[8] / nn)) % 2 == 0)continue;
									if ((b[0] + (b[9] / nn) + (bb[9] / nn)) % 2 == 0)continue;
									if ((b[1] + (b[10] / nn) + (bb[10] / nn)) % 2 == 0)continue;
									if ((b[2] + (b[11] / nn) + (bb[11] / nn)) % 2 == 0)continue;
									vv = true;
									break;
								}
								if (vv)break;
							}
							if (vv)break;
						}
						if (vv)break;
					}
					if (vv)break;
				}
				x = (i / 8) + 1;
				used[x] = false;
				if (vv)break;
			}
		}
		if (vv)printf("Yes\n");
		else printf("No\n");
	}


	return 0;
}
