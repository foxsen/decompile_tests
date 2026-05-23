#include <bits/stdc++.h>
using namespace std;

int d; //日数
const int z=26; //コンテスト数
vector<int> c(z); //コンテストiが開催されないペナルティ
vector<vector<int>> s; //i日目にコンテストjが開催された時の満足度

int score(vector<int> &t)
{
    int sum = 0;
    vector<int> last(z, -1); //コンテストが最後に開催された日
    for (int i = 0; i < t.size(); i++)
    {
        sum += s[i][t[i]];
        last[t[i]] = i;
        for (int j = 0; j < z; j++)
        {
            sum -= c[j] * ((i+1) - (last[j]+1));
        }
        
    }
    return sum;
}

void Main()
{
    cin >> d;
    s = vector<vector<int>>(d, vector<int>(z));
    for (int i = 0; i < z; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < z; j++)
        {
            cin >> s[i][j];
        }
    }

    vector<int> t;
    for (int i = 0; i < d; i++)
    {
        int tmp;
        cin >> tmp;
        t.push_back(tmp-1);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int d, q;
        cin >> d >> q;
        d--; q--;
        t[d] = q;
        cout << score(t) << endl;
    }

    
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
