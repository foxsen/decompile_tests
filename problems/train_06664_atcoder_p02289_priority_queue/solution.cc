#include<bits/stdc++.h>

using namespace std;

int main()
{

    priority_queue<int> q;

    string s;

    while(cin>>s)
    {
        if(s=="end")
        {
            break;
        }else if(s=="insert")
        {
            int a;
            cin>>a;
            q.push(a);
        }else
        {
            cout<<q.top()<<endl;q.pop();
        }
    }



    return 0;
}

