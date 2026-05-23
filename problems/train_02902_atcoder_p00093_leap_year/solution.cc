#include<stdio.h>
int main(void)
{
	int y,y2;
	int i;
	int flg,flg2;
	flg=0;

	scanf("%d %d",&y,&y2);
	while(y!=0 && y2!=0){
		if(flg==0){
			flg=1;
		}
		else{
			printf("\n");
		}
		flg2=0;
		for(i=y;i<=y2;i++){
			if(y%400==0){
				printf("%d\n",y);
				flg2=1;
			}
			 if(y%4==0){
				if(y%100!=0){
					printf("%d\n",y);
				flg2=1;
				}
			}
			y++;
		}
		if(flg2==0){
			printf("NA\n");
		}
		scanf("%d %d",&y,&y2);
	}
	return 0;
}