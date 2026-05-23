#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n,t,m,a[222222],i,flag;
   scanf("%d",&t);
  while(t--)
  {
   scanf("%d%d",&n,&m);
      for( i=0;i<n;i++)
       scanf("%d",&a[i]);
     long long sum=0,temp=1;
      flag=1;
      while(flag)
      {
          for(i=0;i<n;i++)
          {
              if(a[i]%temp==0)
                sum+=a[i];
              else
              {
                  flag=0;
                  break;
              }
          }
          temp*=m;
      }
      printf("%lld\n",sum);
  }
    return 0;
}

 			    	     	     				 	  	 	