#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	char ch;
	while (ch = getchar(), !isdigit(ch));
	res = ch ^ 48;
	while (ch = getchar(), isdigit(ch))
		res = res * 10 + ch - 48;
}

template <class T>
inline T Max(T x, T y) {return x > y ? x : y;}
template <class T>
inline T Min(T x, T y) {return x < y ? x : y;}

using std::vector;
const int N = 2e5 + 5;
int a[N], n;

struct seg
{
	int l, r;

	seg() {}
	seg(int L, int R):
		l(L), r(R) {}

	inline bool Empty()
	{
		return l > r;
	}

	inline seg operator & (const seg &a) 
	{
		return seg(Max(l, a.l), Min(r, a.r)); 
	}

	inline seg operator ^ (const seg &a)
	{
		return a.l == l ? seg(a.r + 1, r) : seg(l, a.l - 1);
	}
};

struct node
{
	seg a;
	int v;

	node() {}
	node(seg A, int V):
		a(A), v(V) {}

	inline bool operator < (const node &a) const
	{
		return v < a.v;
	}
};

vector<node> now, nxt, cur;

int main()
{
	read(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	now.push_back(node(seg(0, 0), 0));
	for (int i = 1; i <= n + 1; ++i)
	{
		int det = a[i] - a[i - 1];
		seg lim = seg(0, a[i]), tmp;

		cur.clear();
		for (node x : now)
		{
			tmp = seg(0, Min(det + x.a.r - 1, x.a.r - 1)) & lim;
			if (!tmp.Empty())
				cur.push_back(node(tmp, x.v + 2));
			tmp = seg(det + x.a.l, x.a.r - 1) & lim;
			if (!tmp.Empty())
				cur.push_back(node(tmp, x.v + 1));
			tmp = seg(x.a.l, det + x.a.r - 1) & lim;
			if (!tmp.Empty())
				cur.push_back(node(tmp, x.v + 1));
			tmp = seg(Max(x.a.l, det + x.a.l), a[i]) & lim; 
			if (!tmp.Empty())
				cur.push_back(node(tmp, x.v));
		}
		std::sort(cur.begin(), cur.end());
		now.clear();
		for (node x : cur)
		{
			seg res = x.a;
			for (node y : now)
			{
				tmp = res & y.a;
				if (!tmp.Empty())
					res = res ^ tmp;
				if (res.Empty())
					break ;
			}
			if (!res.Empty())
				now.push_back(node(res, x.v));
		}
	}
	printf("%d\n", now[0].v);
	return 0;
}