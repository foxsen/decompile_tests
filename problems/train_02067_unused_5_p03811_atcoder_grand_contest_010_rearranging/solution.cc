#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
int N, a[2001], G[2001][2001], q[2002], ue[2002], ref[2002], v[2001], L, d[2001];
std::vector < int > E[2001];
int gcd(int a, int b)
{
	int r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	std::sort(a + 1, a + N + 1);
	for (int i = 1; i < N; i++)
		for (int j = i + 1; j <= N; j++)
			if (gcd(a[i], a[j]) != 1)
				G[i][j] = G[j][i] = 1;
	for (int i = 1; i <= N; i++)
		G[0][i] = G[i][0] = 1;
	int D = 1;
	q[1] = 0;
	ue[1] = 0;
	v[0] = 1;
	ref[L = 1] = 0;
	while (D)
	{
		while (ue[D] <= N && (!G[q[D]][ue[D]] || v[ue[D]]))
			ue[D]++;
		if (ue[D] <= N)
		{
			int To = ue[D]++;
			E[q[D]].push_back(To);
			d[To]++;
			q[++D] = To;
			ue[D] = 0;
			v[ref[++L] = To] = 1;
		}
		else
			D--;
	}
	std::vector < int > O;
	std::set < int > S;
	for (int i = 0; i <= N; i++)
		if (!d[i])
			S.insert(i);
	while (!S.empty())
	{
		auto it = S.end();
		int u = *--it;
		S.erase(it);
		O.push_back(u);
		for (int v : E[u])
			if (!--d[v])
				S.insert(v);
	}
	for (int i : O)
		if (i)
			printf("%d ", a[i]);
	puts("");
	return 0;
}
