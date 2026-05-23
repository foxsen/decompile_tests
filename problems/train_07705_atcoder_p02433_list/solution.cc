#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

int main(){
    list<int> A;
    int q;
    scanf("%d", &q);
    int query,x,d;
    list<int>::iterator itr=A.end();
    for (int i = 0; i < q; i++)
    {
        scanf("%d",&query);
        switch (query)
        {
        case 0:
            scanf("%d",&x);
            itr=A.insert(itr,x);
            break;

        case 1:
            scanf("%d",&d);
            if(d<0){
                for (int i = 0; i < -d; i++) itr--;          
            }else
            {
                for (int i = 0; i < d; i++) itr++;              
            }
            
            
            break;
        
        case 2:
            itr=A.erase(itr);
            break;

        default:
            break;
        }
    }
    for ( itr = A.begin(); itr != A.end(); itr++)
    {
        printf("%d\n", *itr);
    }
    
    return 0;
}
