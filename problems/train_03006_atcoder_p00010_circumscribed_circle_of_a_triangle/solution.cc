#include <stdio.h>
#include <math.h>

using namespace std;


int main(){
	int n;
	double x1,x2,x3,y1,y2,y3,ox,oy,r;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
		ox=((y2-y1)*((y3*y3-y1*y1)+(x3*x3-x1*x1))-(y3-y1)*((y2*y2-y1*y1)+(x2*x2-x1*x1)))/
				(2*((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)));
		if(y2 != y1){
			oy=(2*(x1-x2)*ox+(y2*y2-y1*y1)+(x2*x2-x1*x1))/(2*(y2-y1));
		}else{
			oy=(2*(x1-x3)*ox+(y3*y3-y1*y1)+(x3*x3-x1*x1))/(2*(y3-y1));
		}

		r = sqrt((ox-x1)*(ox-x1)+(oy-y1)*(oy-y1));
		printf("%.3lf %.3lf %.3lf\n",ox,oy,r);
	}
    return 0;
}