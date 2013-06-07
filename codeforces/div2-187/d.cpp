#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define sz size()

using namespace std;

int cab[200];
int ter[200];

int main()
{
    int b, d;
    int ind, ret;
    string a, c, aux;
    cin >> b >> d;
    cin >> a;
    cin >> c;
    ind = 0;
    aux = a+a;
    for(int i=0;i<c.sz;i++)
    {
        ind = i;
        for(int j=0;j<a.sz;j++)
        {
            if(aux[j] == c[ind]) ind++;
            if(ind >= c.sz)
            {
                cab[i]++;
                ind=0;
            }
        }
        ter[i] = ind;
    }
    ret = 0;
    ind = 0;
    for(int i=0;i<b;i++)
    {
        ret += cab[ind];
        ind = ter[ind];
    }
    cout << ret/d << endl;
    return 0;
}
