#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int u[111111];
int a[111111];
vector <int> asc, desc;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(u[a[i]] == 0) 
        {
            u[a[i]]++;
            asc.push_back(a[i]);
        }
        else if(u[a[i]] == 1) 
        {
            u[a[i]]++;
            desc.push_back(a[i]);
        }
    }
    sort(asc.begin(),asc.end());
    sort(desc.begin(),desc.end(),greater<int>());
    int s = asc.size()+desc.size();
    int m = 0;
    if(desc.size() > 0 && asc[asc.size()-1] == desc[0]) m = 1;
    cout << s - m << endl;
    for(int i=0;i<asc.size();i++) cout << asc[i] << " ";
    for(int i=m;i<desc.size();i++) cout << desc[i] << " ";
    cout << endl;
    return 0;
}
