#include <cstdio>
using namespace std;

int h, w, n;
int sr, sc;
char t[200001];
char a[200001];
int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
char dir[5] = "RLDU";

int main()
{
	scanf("%d %d %d", &h, &w, &n);
	scanf("%d %d", &sr, &sc);
	scanf("%s", t);
	scanf("%s", a);

	int by, bx;
	int flag = 0;

	for (int i = 0; i < 4; i++)
	{
		by = sr;
		bx = sc;
		int temp = i - (i % 2) * 2 + 1;

		for (int j = 0; j < n && flag == 0; j++)
		{
			if (t[j] == dir[i])
			{
				by += d[i][0];
				bx += d[i][1];
			}
			if (by > h || by < 1 || bx > w || bx < 1)
			{
				flag = 1;
				break;
			}		

			if (a[j] == dir[temp])
			{
				if (by + d[temp][0] > h || by + d[temp][0] < 1 || bx + d[temp][1] > w || bx + d[temp][1] < 1)
					continue;

				by += d[temp][0];
				bx += d[temp][1];
			}
		}
	}
	
	if (flag == 0)
		printf("YES");
	else
		printf("NO");

	return 0;
}