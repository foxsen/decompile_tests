#include <stdio.h>
#include <string.h>

#define N	200000
#define Q	50000
#define K	400
#define L	(K * 6 + 1)

int min(int a, int b) { return a < b ? a : b; }

int aa[N], bb[N], cc[N], ii[Q], xx[Q], n; char landmark[N];
int gg[N], ii_[K], aa_[K], bb_[K], cc_[K], k;
int col[N], qu[L], l;
int kk[N + 1]; long long kk_[N];
int kka[K][L], kkb[K][L], kkc[K][L]; long long ans[N], kkba[K][L], kkac[K][L];

void setup(int hl, int hr) {
	int g, h, i, a, a_;
	long long x;

	l = 1;
	for (h = hl; h < hr; h++) {
		i = ii[h];
		if (!landmark[i]) {
			landmark[i] = 1;
			a = aa[i];
			if (!col[a])
				qu[col[a] = l++] = a;
			if (!col[bb[a]])
				qu[col[bb[a]] = l++] = bb[a];
			if (!col[cc[a]])
				qu[col[cc[a]] = l++] = cc[a];
		}
		if ((a = xx[h]) != -1) {
			if (!col[a])
				qu[col[a] = l++] = a;
			if (!col[bb[a]])
				qu[col[bb[a]] = l++] = bb[a];
			if (!col[cc[a]])
				qu[col[cc[a]] = l++] = cc[a];
		}
	}

	memset(kk, 0, l * sizeof *kk);
	for (i = 0, k = 0; i < n; i++) {
		a = aa[i];
		if (!landmark[i])
			kk[col[a]]++;
		else {
			ii_[k] = i, aa_[k] = col[a], bb_[k] = col[bb[a]], cc_[k] = col[cc[a]], gg[i] = k;
			memcpy(kka[k], kk, l * sizeof *kk), k++;
		}
	}

	memset(kk, 0, l * sizeof *kk), memset(kk_, 0, l * sizeof *kk_);
	for (i = 0, g = 0; i < n; i++)
		if (!landmark[i]) {
			a = aa[i];
			a_ = col[a], kk_[a_] += kk[a_], kk[col[bb[a]]]++;
		} else
			memcpy(kkba[g], kk_, l * sizeof *kk_), memcpy(kkb[g], kk, l * sizeof *kk), g++;

	memset(kk, 0, l * sizeof *kk), memset(kk_, 0, l * sizeof *kk_);
	for (i = n - 1, g = k - 1; i >= 0; i--)
		if (!landmark[i]) {
			a = aa[i];
			a_ = col[a], kk_[a_] += kk[a_], kk[col[cc[a]]]++;
		} else
			memcpy(kkac[g], kk_, l * sizeof *kk_), memcpy(kkc[g], kk, l * sizeof *kk), g--;

	memset(kk, 0, n * sizeof *kk), memset(kk_, 0, n * sizeof *kk_);
	x = 0;
	for (i = 0; i < n; i++)
		if (!landmark[i]) {
			a = aa[i];
			x += kk_[cc[a]], kk_[a] += kk[a], kk[bb[a]]++;
		} else
			ans[i] = x, landmark[i] = 0;
}

void cleanup() {
	while (--l)
		col[qu[l]] = 0;
}

int main() {
	static int ll[K], rr[K];
	int q, h, hl, hr, i, a;

	scanf("%d%d", &n, &q);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]), aa[i]--;
	for (i = 0; i < n; i++)
		scanf("%d", &bb[i]), bb[i]--;
	for (i = 0; i < n; i++)
		scanf("%d", &cc[i]), cc[i]--;
	for (h = 0; h < q; h++) {
		int t;

		scanf("%d%d", &t, &ii[h]), ii[h]--;
		if (t == 1)
			scanf("%d", &xx[h]), xx[h]--;
		else
			xx[h] = -1;
	}
	for (hl = 0; hl < q; hl += K) {
		hr = min(hl + K, q);
		setup(hl, hr);
		for (h = hl; h < hr; h++) {
			if (xx[h] != -1) {
				i = ii[h], a = xx[h];
				aa[i] = a, aa_[gg[i]] = col[a], bb_[gg[i]] = col[bb[a]], cc_[gg[i]] = col[cc[a]];
			} else {
				int r, k_, g, a, b, c;
				long long x;

				r = ii[h], k_ = gg[r] + 1;

				x = ans[r];	/* no landmarks */
				for (g = 0; g < k_; g++) {
					a = aa_[g], b = bb_[g], c = cc_[g];
					x += kkba[g][c];	/* c landmark */
					x += kkac[g][b] - kkac[k_ - 1][b] - (long long) (kka[k_ - 1][b] - kka[g][b]) * kkc[k_ - 1][b];	/* b landmark */
					x += (long long) kkb[g][a] * (kkc[g][a] - kkc[k_ - 1][a]);	/* a landmark */
				}

				memset(kk, 0, l * sizeof *kk);
				for (g = 0; g < k_; g++) {
					a = aa_[g], b = bb_[g];
					ll[g] = kk[a], kk[b]++;
				}

				memset(kk, 0, l * sizeof *kk);
				for (g = k_ - 1; g >= 0; g--) {
					a = aa_[g], c = cc_[g];
					rr[g] = kk[a], kk[c]++;
				}

				/* b and c landmark */
				memset(kk_, 0, l * sizeof *kk_), memset(kk, 0, l * sizeof *kk);
				for (g = 0; g < k_; g++) {
					b = bb_[g], c = cc_[g];
					x += (long long) kk[c] * kka[g][c] - kk_[c];
					kk[b]++, kk_[b] += kka[g][b];
				}

				for (g = 0; g < k_; g++) {
					a = aa_[g];
					x += (long long) ll[g] * (kkc[g][a] - kkc[k_ - 1][a]);	/* b and a landmark */
					x += (long long) kkb[g][a] * rr[g];	/* a and c landmark */
					x += (long long) ll[g] * rr[g];	/* b, a, and c landmark */
				}
				printf("%lld\n", x);
			}
		}
		cleanup();
	}
	return 0;
}