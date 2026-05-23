#include <iostream>
#include <complex>
#include <cmath>
#include <cstdio>

using namespace std;

typedef complex<double> P;

const double PI = acos(-1.0);

int main(){
	int N, D;
	while(cin >> N >> D, N){
		P p = P(0,0); double dir = PI/2;
		for(int i=0;i<N;i++){
			int L, R, T; cin >> L >> R >> T;
			if(L==R){
				p = p + T*L/180.0*PI*P(cos(dir), sin(dir));
			}
			else {
				double r = ((double)L+R)/(L-R)*D;
				P c = p + P(cos(dir), sin(dir))*P(0,-1)*r;
				double agl = (r > 0 ? -L/abs(r+D) : R/abs(r-D))*T*PI/180.0;
				dir += agl;
				p = (p-c)*P(cos(agl), sin(agl))+c;
			}
		}
		printf("%.8lf\n%.8lf\n", real(p), imag(p));
	}
}