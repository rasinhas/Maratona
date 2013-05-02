#include <stdio.h>
#include <iostream>
#include <string>
#define sz size()

using namespace std;

int main()
{
    int ret=1;
    int aoc=0, azc=0, boc=0, bzc=0;
    string a, b;
    cin >> a;
    cin >> b;
    if(a.sz != b.sz) ret = 0;
    else
    {
        for(int i=0;i<a.sz;i++)
        {
            if(a[i] == '0') azc++;
            else aoc++;
        }
        for(int i=0;i<b.sz;i++)
        {
            if(b[i] == '0') bzc++;
            else boc++;
        }
        if(boc == 0 && aoc != 0) ret = 0;
        if(aoc == 0 && boc != 0) ret = 0;
    }
    if(!ret) printf("NO\n");
    else printf("YES\n");
    return 0;
}
