#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    vector <pair<int,int> > c;
    string f1="", f2;
    cin >> n;
    for(int i=0;i<n/2;i++) f1 += '1';
    for(int i=n/2;i<n;i++) f1 += '0';
    f2 = f1;
    for(int i=0;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        c.push_back(make_pair(a,0));
        c.push_back(make_pair(b,1));
    }
    sort(c.begin(),c.end()); 
    int a=0, b=0;
    for(int i=0;i<n;i++)
    {
        if(c[i].second == 0)
        {
            f1[a] = '1';
            a++;
        }
        else 
        {
            f2[b] = '1';
            b++;
        }
    }
    cout << f1 << endl << f2 << endl;
    return 0;
}
