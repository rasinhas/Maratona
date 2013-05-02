#include <iostream>
#include <stdio.h>

using namespace std;


//se n%4 == 0 => n
//senao adiciona algarismo em n
int main()
{
    int h[1000];
    p = 1;
    for(int i=1;i<15;i++)
    {
        h[i] = 9*p*(i+1) - (9*p/4);
        //precisa disso?
        //if(p > 10) h[i] -= 1;
        p *= 10;
    }
    while(scanf("%lld", &n) && n)
    {
        a = 0;
        for(int i=0;i<n;i++)
        {
            a += h[i];
            if(a >= n) break;
        }
        //o algarismo q procuro esta em um cara com i algarismos

    }
    return 0;
}
