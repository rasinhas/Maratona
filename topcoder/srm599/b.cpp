#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#define EPS 1e-9

using namespace std;

const int N=5000;
double sol[5555];

void precalc()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            double l = i + j + sqrt(i*i+j*j);
            if(l == 4984) cout << i << j << endl;
            if(l > N) break;
            if(fmod(l,1.0) < EPS)
            {
                sol[(int)l] = min(sqrt(i*i+j*j)-j,sol[(int)l]);
            }
        }
    }
}

class FindPolygons {
    public:
    double minimumPolygon(int l)
    {
        for(int i=0;i<=N;i++) sol[i] = 1e9;
        precalc();
        return sol[l];
    }
};

int main()
{
    FindPolygons a;
    cout << a.minimumPolygon(4984) << endl;
    return 0;
}
