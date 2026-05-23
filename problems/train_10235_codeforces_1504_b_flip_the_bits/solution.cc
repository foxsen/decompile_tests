#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int ta;
    cin >> ta;
    while (ta-- > 0)
    {
        int n;
        cin >> n;
        string w;
        cin >> w;
        string w1;
        cin >> w1;
        int ze = 0, on = 0;
        for (int i = 0; i < n; i++)
        {
            if (w[i] == '1')
                on++;
            else
                ze++;
        }
        int f = 0, s = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s % 2 == 1)
            {
                if (w[i] == '1')
                    w[i] = '0';
                else
                    w[i] = '1';
            }
            if (w[i] != w1[i] && ze != on)
            {

                f = 1;
                break;
            }
            else
            {
                if (w[i] == w1[i] && w[i] == '0')
                    ze--;
                else if (w[i] == w1[i] && w[i] == '1')
                    on--;
                if (w[i] != w1[i] && w[i] == '0')
                {
                    s++;
                    ze--;
                    swap(ze, on);
                }
                else if (w[i] != w1[i] && w[i] == '1')
                {
                    s++;
                    on--;
                    swap(ze, on);
                }
            }
        }
        if (f == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}