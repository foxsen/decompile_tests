#include<stdio.h>
double abs(double A){
	return A<0.0?-A:A;
}
int main(){
	int a;
	while(scanf("%d",&a),~a){
		double p=(double)a/2.0;
		while(1){
			p=p-((p*p*p)-(double)a)/(3.0*p*p);
			if(abs(p*p*p-(double)a)<(double)a*0.00001)break;
			//printf("%.6lf\n",p);
		}
		printf("%.6lf\n",p);
	}
}