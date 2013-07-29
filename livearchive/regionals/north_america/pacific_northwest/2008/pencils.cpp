#include <iostream>
#define eps 1e-4

using namespace std;

double mod(double a) { return a > 0 ? a : -a; } 

void print(int i, int j, int k)
{
    cout << i << " at four cents each" << endl;
    cout << j << " at two for a penny" << endl;
    cout << k << " at four for a penny" << endl;
    cout << endl;
}

int main()
{
    int t=1;
    int n;
    while((cin >> n) && n)
    {
        double c;
        int f=0;
        cout << "Case " << t++ << ": " << n << " pencils for " << n << " cents" << endl;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                for(int k=1;k<n;k++)
                {
                    c = (double)((i*4.0)+(j/2.0)+(k/4.0));
                    if(mod(c-n) < eps && (i + j + k) == n)
                    {
                        print(i,j,k);
                        f = 1;
                    }
                }
            }
        }
        if(!f) cout << "No solution found." << endl << endl;
    }
    return 0;
}
