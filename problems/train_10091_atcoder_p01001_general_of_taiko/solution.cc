#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef vector<double> vec;
typedef vector<vec> vec2;
typedef vector<vec2> vec3;
typedef vector<vec3> vec4;

template<class T> inline void chmax(T& a, T b) { if(b > a) a = b; }

enum { LT, RT, LK, RK, NONE };

int main() {
	for(;;) {
		int acc[4][4];
		for(int i = 0; i < 4; ++i)
			scanf("%d", &acc[0][i]);

		if(acc[0][0] < 0)
			break;

		for(int i = 1; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				scanf("%d", &acc[i][j]);

		int l;
		scanf("%d", &l);

		vector<int> s(l);
		for(int i = 0; i < l; ++i)
			scanf("%d", &s[i]);

		int a, b;
		scanf("%d %d", &a, &b);
		a /= 100;
		b /= 100;

		vec4 dp(101, vec3(5, vec2(11, vec(11, 0.0))));
		for(int i = 0; i < 5; ++i)
			for(int j = 0; j < 11; ++j)
				for(int k = 0; k < 11; ++k)
					dp[100][i][j][k] = 1.0;

		for(int next = l - 1; next >= 0; --next) {
			vec4 tmp(101, vec3(5, vec2(11, vec(11, 1.0))));
			if(s[next] == 0) {
				for(int sco = 0; sco < 100; ++sco)
					for(int pre = 0; pre < 5; ++pre)
						for(int com = 0; com <= 10; ++com)
							for(int pac = 0; pac <= 10; ++pac)
								tmp[sco][pre][com][pac] = dp[sco][NONE][com][10];
				dp.swap(tmp);
				continue;
			}

			const int start = (s[next] == 1 ? 0 : 2);
			for(int sco = 0; sco < 100; ++sco) {
				for(int pre = 0; pre < 4; ++pre) {
					for(int pac = 0; pac <= 10; ++pac) {
						for(int com = 0; com <= 10; ++com)
							tmp[sco][pre][com][pac] = dp[sco][NONE][0][10];

						for(int i = start; i < start + 2; ++i) {
							const int ac = max(0, (acc[pre][i] - 10) + pac);
							const double p = ac / 10.0;
							for(int com = 0; com <= 10; ++com) {
								const double buf = p * dp[min(100, sco + a + b * min(10, com))][i][min(10, com + 1)][ac] + (1.0 - p) * dp[sco][i][0][ac];
								chmax(tmp[sco][pre][com][pac], buf);
							}
						}
					}
				}

				for(int com = 0; com <= 10; ++com) {
					for(int pac = 0; pac <= 10; ++pac) {
						tmp[sco][NONE][com][pac] = dp[sco][NONE][0][10];
						for(int i = start; i < start + 2; ++i) {
							chmax(tmp[sco][NONE][com][pac], dp[min(100, sco + a + b * min(10, com))][i][min(10, com + 1)][10]);
						}
					}
				}
			}

			dp.swap(tmp);
		}

		printf("%.5lf\n", dp[0][NONE][0][10]);
	}

	return EXIT_SUCCESS;
}