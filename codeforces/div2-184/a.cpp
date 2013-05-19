#include <iostream>
#include <cstdio>

using namespace std;

int c[4];
int r[4];

int main()
{
    int a[200], n, k;
    cin >> n;
    k = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] == 0 && !c[3]) r[k++] = 0, c[3] = 1;
        else if(a[i] > 0 && a[i] < 10 && !c[2]) r[k++] = a[i], c[2] = 1;
        else if(a[i] > 9 && a[i] < 100 && a[i]%10 == 0 && !c[1]) r[k++] = a[i], c[1] = 1;
        else if(a[i] == 100 && !c[0]) r[k++] = 100, c[0] = 1;
    }
    if(!c[2] && !c[1])
    {
        for(int i=0;i<n;i++)
        {
            if(a[i] > 9 && a[i] < 100) 
            {
                c[2] = c[1] = 1, r[k++] = a[i];
                break;
            }
        }
    }
    cout << k << endl;
    for(int i=0;i<k;i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;
    return 0;
}
