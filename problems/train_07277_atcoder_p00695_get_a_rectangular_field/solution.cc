#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int a[5][5];
int main()
{
    int n;
    int b[5][5];
    cin >> n;
    for(int lim=0;lim<n;lim++)
    {
        int M=0;
        int m;
        for(int i=0;i<5;i++)
        {
            int count=1;
            for(int j=0;j<5;j++)
            {
                cin >> b[i][j];
            }
            for(int j=4;j>=0;j--)
            {
                if(b[i][j] == 0) count = 0;
                a[i][j] = count;
                ++count;
            }
        }
        /*
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        */
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(a[i][j] != 0){
                    m = a[i][j];
                    for(int k=1;i+k-1<5 && a[i+k-1][j] != 0;k++)
                    {
                        //printf("(%d,%d) = %d, (M,m) = (%d,%d)\n",i+k-1,j,a[i+k][j],M,m);
                        m = min(m, a[i+k-1][j]);
                        M = max(M, k*m);
                    }
                }
            }
        }
        cout << M << endl;
    }
}