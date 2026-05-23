#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

class Rect{public:int h;int pos;};

int w,h,ct[504][504];
char t[504][504];

void mkCT(void){
	rep(j,w){
		int count = 1;
		rep(i,h){
			if(t[i][j] == '*') count = 0;
			ct[i][j] = count++;
		}
	}
}

int calArea(void){
	mkCT();

	int res = 0;
	stack<Rect> s;

	rep(i,h)rep(j,w+1){
		Rect rect;
		rect.h = ct[i][j];
		rect.pos = j;

		if(s.empty()){
			s.push(rect);
		}
		else {
			Rect tmp = s.top();
			if(tmp.h < rect.h){
				s.push(rect);
			}
			else if(tmp.h > rect.h){
				int pre = -1;
				while(!s.empty() && s.top().h >= rect.h){
					tmp = s.top(); s.pop();
					pre = tmp.pos;
					res = max(res, tmp.h * (j - tmp.pos));
				}
				rect.pos = pre;
				s.push(rect);
			}
		}
	}

	return res;
}

int main(void){
	while(scanf("%d%d",&h,&w) && (h||w)){
		rep(i,h){
			scanf("%s",t[i]);
			ct[i][w] = 0;
		}
		printf("%d\n",calArea());
	}

	return 0;
}