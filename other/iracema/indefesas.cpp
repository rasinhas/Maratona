#include <iostream>
#include <cstdio>
#define mv 500

using namespace std;

int e[4][2];

//not solved
int main()
{
    int n;
    double cx, cy;
    cin >> n;
    for(int t=1;t<=n;t++)
    {
        cx = 0;
        cy = 0;
        for(int i=0;i<4;i++)
        {
            cin >> e[i][0] >> e[i][1];
            cx += e[i][0];
            cy += e[i][1];
        }
        cx /= 4;
        cy /= 4;
    }
    return 0;
}
