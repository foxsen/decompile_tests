#include <cstdio>
#pragma warning(disable : 4996)
int N, Q, v[1048588], vx[1048588], vy[1048588], pc[75]; char s[1048588], qs[29];
int main() {
	scanf("%d%d%s", &N, &Q, s);
	for (int i = 0; i < 1 << N; ++i) {
		v[i] = s[i] - '0';
		vx[i] = v[i];
		vy[i] = v[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 1 << N; ++j) {
			if ((j >> i) & 1) {
				vx[j] += vx[j - (1 << i)];
				vy[j - (1 << i)] += vy[j];
			}
		}
	}
	pc[0] = 1;
	for (int i = 1; i < 1 << (N / 3); i++) {
		pc[i] = pc[i >> 1] ^ (i & 1);
	}
	for (int i = 0; i < Q; ++i) {
		scanf("%s", qs);
		int cx = 0, cy = 0, cz = 0, sx = 0, sy = 0, sz = 0;
		for (int j = 0; j < N; ++j) {
			if (qs[N - j - 1] == '0') ++cx, sx |= 1 << j;
			if (qs[N - j - 1] == '1') ++cy, sy |= 1 << j;
			if (qs[N - j - 1] == '?') ++cz, sz |= 1 << j;
		}
		int ret = 0;
		if (3 * cz <= N) {
			for (int j = sz; j >= 0; --j) {
				j &= sz;
				ret += v[j + sy];
			}
		}
		else if (3 * cy <= N) {
			for (int j = sy, k = 0; j >= 0; --j, ++k) {
				j &= sy;
				if(pc[k]) ret += vx[j + sz];
				else ret -= vx[j + sz];
			}
		}
		else {
			for (int j = sx, k = 0; j >= 0; --j, ++k) {
				j &= sx;
				if (pc[k]) ret += vy[sx + sy - j];
				else ret -= vy[sx + sy - j];
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
