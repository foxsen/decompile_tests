#include<stdio.h>
#include<math.h>

int main()
{
    long long int W,E,s,x,y,a,b,c,d,i,j,z,k,N,M,t,m,max;
    scanf("%lld", &N);
    for(i=0; i<N; i++)
    {
        scanf("%lld", &M);
        if((M%2)!=0)
        {
            printf("YES\n");
        }
        else
        {
            y=0;
            E=M;
            while(E!=0)
            {
                E=E/2;
                if((E%2)!=0 && E>1)
                {
                    y=1;
                    break;
                }
            }
            if(y==1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
