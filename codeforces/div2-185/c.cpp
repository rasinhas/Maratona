#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, k, cy;
    cin >> n >> k;
    if((n*(n-1))/2 <= k) cout << "no solution" << endl;
    else
    {
        cy = 0;
        for(int i=0;i<n;i++)
        {
            printf("%d %d\n", i%2, cy);
            cy++;
        }
    }
    return 0;
}
