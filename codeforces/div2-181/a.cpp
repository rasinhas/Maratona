#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#define pb push_back
#define sz size()

using namespace std;

int main()
{
    int n;
    int a[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    cout << "1 " << a[0] << endl;
    if(a[n-1] > 0)
    {
        cout << "1 " << a[n-1] << endl;
        cout << n-2;
        for(int i=1;i<n-1;i++) cout <<  " " << a[i];
        cout << endl;
    }
    else
    {
        cout << "2 " << a[1] << " " << a[2] << endl;
        cout << n-3;
        for(int i=3;i<n;i++) cout <<  " " << a[i];
        cout << endl;
    }
    return 0;
}
