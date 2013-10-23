#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int t[222222], d[222222], dif[222222];

int main()
{
    int n, da=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> t[i] >> d[i];
        da += d[i];
        dif[i] = da-t[i];
    }
    int b=0, s=0;
    priority_queue <int> q;
    for(int i=0;i<n;i++)
    {
        q.push(d[i]);
        if(dif[i] > b)
        {
            b += q.top();
            q.pop();
            s++;
        }
    }
    cout << s << endl;
    return 0;
}
