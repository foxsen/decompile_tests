#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;

#define EPS 1e-8
#define INF 1e100

typedef complex<double> P;
typedef vector<P> vP;

const P iu(0.0, 1.0);

double dot(P a, P b){
	return real(a) * real(b) + imag(a) * imag(b);
}

double cross(P a, P b){
	return real(a) * imag(b) - imag(a) * real(b);
}

int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > EPS)	return +1;	// counter clockwise
	if (cross(b, c) < -EPS)	return -1;	// clockwise
	if (dot(b, c) < -EPS)	return +2;	// c--a--b on line
	if (norm(b) < norm(c))	return -2;	// a--b--c on line
	return 0;
}

P crosspoint(P a1, P a2, P b1, P b2){
	double t = cross(b1 - a1, b1 - b2) / cross(a2 - a1, b1 - b2);
	return a1 + t * (a2 - a1);
}

P centroid(const vP &pl){
	P s;
	int sz = pl.size() - 1;
	if(sz < 1){ return P(INF, INF); }
	for(int i = 1; i <= sz; ++i){
		s += pl[i];
	}
	return s / (double)sz;
}

vP convex_cut(const vP &pl, P la, P lb) {
	vP Q;
	for (int i = 1; i < pl.size(); ++i) {
		P A = pl[i-1], B = pl[i];
		if (ccw(la, lb, A) != -1){ Q.push_back(A); }
		if (ccw(la, lb, A) * ccw(la, lb, B) < 0){
			Q.push_back(crosspoint(A, B, la, lb));
		}
	}
	if(!Q.empty() && Q.back() != Q[0]){
		Q.push_back(Q[0]);
	}
	return Q;
}

double area(const vP p){
	double s = 0.0;
	for(int i = 1; i < p.size(); ++i){
		s += cross(p[i-1], p[i]);
	}
	return 0.5 * abs(s);
}

int main(){
	const double L = 10000.0;
	int T = 0;
	int x, y;

	while(1){
		P pt[3];
		for(int i = 0; i < 3; ++i){
			scanf("%d%d", &x, &y);
			pt[i] = P(x, y);
			if(x == 0){ return 0; }
		}

		vP plg(5);
		plg[1] = P(0.0, L);
		plg[2] = P(L, L);
		plg[3] = P(L, 0.0);

		for(int k = 1; k < 3; ++k){
			P mid = 0.5 * (pt[0] + pt[k]);
			P dif = iu * (pt[k] - pt[0]);
			
			vP p1 = convex_cut(plg, mid, mid + dif);
			vP p2 = convex_cut(plg, mid, mid - dif);

			if(p1.empty()){ p1.swap(p2); }
				//直線と多角形の交点がないケース。一方は空、他方は元の多角形
			P cn = centroid(p1);
			plg.swap(norm(pt[0] - cn) < norm(pt[k] - cn) ? p1 : p2);
		}

		printf("%d %f\n", ++T, area(plg) / (L * L));
	}
}