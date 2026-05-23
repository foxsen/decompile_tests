#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>
#include <complex>

using namespace std;

typedef complex<double> Point;

const double Eps = 1e-8;

double dot(const Point& a, const Point& b)
{
	return a.real()*b.real() + a.imag()*b.imag();
}
double cross(const Point& a, const Point& b)
{
	return a.real()*b.imag() - a.imag()*b.real();
}
double distance_line_point(const Point& point, const Point& a, const Point& b)
{
	return abs(cross(a-b, point-b) / (a-b));
}
double distance_linesegment_point(const Point& point, const Point& a, const Point& b)
{
	if (dot(b-a, point-a) < 0)
		return abs(a-point);
	else if (dot(a-b, point-b) < 0)
		return abs(b-point);
	else
		return distance_line_point(point, a, b);
}
int main()
{
	int R, N;
	while (scanf("%d %d", &R, &N), R | N)
	{
		double r[1000], v[1000], d[1000], angle[1000];
		for (int i = 0; i < N; ++i)
		{
			double x, y;
			scanf("%lf %lf %lf %lf", &x, &y, r+i, v+i);
			d[i] = sqrt(x*x + y*y);
			angle[i] = atan2(y, x);
		}

		int ans = 0;
		bool used[1000];
		fill(used, used+N, false);
		while (true)
		{
			double shot_angle;
			double near = 1e30;
			for (int i = 0; i < N; ++i)
			{
				if (used[i])
					continue;

				d[i] -= v[i];
				if (d[i] < R + Eps)
				{
					++ans;
					used[i] = true;
				}
				else if (abs(d[i]) < near)
				{
					near = (d[i]);
					shot_angle = angle[i];
				}
			}
			if (near > 1e29)
				break;

			for (int i = 0; i < N; ++i)
				if (!used[i]
				&& distance_linesegment_point(Point(d[i]*cos(angle[i])
					, d[i]*sin(angle[i])), Point(1e10*cos(shot_angle), 1e10*sin(shot_angle))
					, Point(R*cos(shot_angle), R*sin(shot_angle))) < r[i] + Eps)
					used[i] = true;
		}
		printf("%d\n", ans);
	}

	return 0;
}