#include <iostream>
#include <cstdio>

using namespace std;

int main() 
{
    long long ret1 = 0, ret2 = 0;
    long long a, b;
    cin >> a >> b;
    if(a > 0) ret1 = (a*a) - ((b/2)*(b/2)) - (((b+1)/2)*((b+1)/2));
    else ret1 = -(b*b);
    long long qmpi;
    if(a == 0) qmpi = b;
    else qmpi = (b+a)/(a+1);
    long long iqm = (a+1)-(qmpi*(a+1)-b);
    long long k = 0, v=0;
    ret2 = a;
    for(int i=0;i<a+1;i++) {
        if(i < iqm) ret2 -= (qmpi*qmpi);
        else ret2 -= (qmpi-1)*(qmpi-1);
    }
    cout << max(ret1,ret2) << endl;
    if(ret1 > ret2) {
        for(int i=0;i<(b+1)/2;i++) printf("x");
        for(int i=0;i<a;i++) printf("o");
        for(int i=0;i<b/2;i++) printf("x");
    }
    else {
        for(int i=0;i<a+1;i++) {
            for(int j=0;j<qmpi-v;j++) printf("x");
            if(i < a) printf("o");
            k++;
            if(k == iqm) v = 1;
        }
    }
    printf("\n");
    return 0;
}
