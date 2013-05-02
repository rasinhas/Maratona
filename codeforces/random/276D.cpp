#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    unsigned long long l, r, a, b, ret=0;
    int q=0;
    unsigned long long pot[100];
    int lb[100], rb[100];
    memset(lb,0,sizeof(lb));
    memset(rb,0,sizeof(rb));
    pot[0] = 1;
    for(int i=1;i<64;i++) pot[i] = 2*pot[i-1];
    cin >> l >> r;
    a = l;
    b = r;
    while(a || b)
    {
        if(b && b%2) rb[q] = 1;
        b/=2;
        if(a && a%2) lb[q] = 1;
        a/=2;
        q++;
    }
    a = l;
    b = r;
    for(int i=q-1;i>=0;i--)
    {
        if(lb[i] == rb[i])
        {
            if(lb[i] == 0 && a+pot[i] < r) { lb[i] = 1; a+=pot[i];}
            else if(lb[i] == 1 && b-pot[i] > l) { rb[i] = 0; b-=pot[i];}
        }
        if(lb[i] != rb[i]) ret += pot[i];
    }
    /*
    for(int i=0;i<q;i++) printf("%d ", rb[i]);
    printf("\n");
    for(int i=0;i<q;i++) printf("%d ", lb[i]);
    printf("\n");
    */
    cout << ret << endl;
    return 0;
}
