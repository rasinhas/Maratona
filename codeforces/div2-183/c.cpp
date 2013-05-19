#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n%2 == 0) cout << -1 << endl;
    else 
    {
        for(int i=0;i<n;i++) cout << i << " ";
        cout << endl;
        for(int i=0;i<n;i++) cout << i << " ";
        cout << endl;
        for(int i=0;i<n;i++) cout << (2*i)%n << " ";
        cout << endl;
    }
    return 0;
}
