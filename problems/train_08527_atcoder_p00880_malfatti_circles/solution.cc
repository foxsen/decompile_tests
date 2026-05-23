#include<cstdio>
#include<cmath>
#include<complex>
#define eps 1e-12
#define RE real()
#define IM imag()
using namespace std;
typedef complex<double> Point;
Point I,A,B,C;

int main()
{
    double x1,y1,x2,y2,x3,y3;
    while(~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3))
    {
        if(fabs(x1)<eps && fabs(y1)<eps && fabs(x2)<eps && fabs(y2)<eps && fabs(x3)<eps && fabs(y3)<eps) break;
        A = Point(x1,y1), B = Point(x2,y2), C = Point(x3,y3);
        double a,b,c;
        c = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        a = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
        b = sqrt((x1-x3)*(x1-x3) + (y3-y1)*(y3-y1));
        double p = (c+a+b)/2.0;
        double r = sqrt(p*(p-a)*(p-b)*(p-c))/p;
        I = Point( ((a*A.RE+b*B.RE+c*C.RE)/(a+b+c)),((a*A.IM+b*B.IM+c*C.IM)/(a+b+c)));
        double Ia,Ib,Ic;
        Ia = sqrt((x1-I.RE)*(x1-I.RE) + (y1-I.IM)*(y1-I.IM));
        Ib = sqrt((x2-I.RE)*(x2-I.RE) + (y2-I.IM)*(y2-I.IM));
        Ic = sqrt((x3-I.RE)*(x3-I.RE) + (y3-I.IM)*(y3-I.IM));
        double  r1=(r/(2*(p-a)))*(p-r+Ia-Ib-Ic);
        double  r2=(r/(2*(p-b)))*(p-r+Ib-Ia-Ic);
        double  r3=(r/(2*(p-c)))*(p-r+Ic-Ib-Ia);
        printf("%.6f %.6f %.6f\n",r1,r2,r3);
    }
    return 0;
}