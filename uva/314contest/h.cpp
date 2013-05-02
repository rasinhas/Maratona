#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
#define pb push_back
#define mp make_pair
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    int t, wc, bc, f;
    string seq;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        f = bc = wc = 0;
        cin >> seq;
        for(int j=0;j<seq.size();j++)
        {
            if(seq[j] == 'B') bc++;
            if(seq[j] == 'W') wc++;
        }
        if(seq[0] == 'W' || seq[seq.size()-1] == 'B' || wc == 0 || bc == 0)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        else
        {
            for(int j=0;j<bc;j++)
            {
                if(seq[j] == 'W')
                {
                    f = 1;
                    break;
                }
            }
            if(!f)
            {
                printf("1\n%d", bc+wc);
                for(int j=0;j<seq.size();j++) printf(" %d", j+1);
                printf("\n");
            }
            if(f)
            {
                printf("2\n%d", bc);
                for(int j=1;j<seq.size();j++) if(seq[j] == 'B') printf(" %d", j+1);
                printf(" %d\n%d 1", bc+wc, wc);
                for(int j=1;j<seq.size()-1;j++) if(seq[j] == 'W') printf(" %d", j+1);
                printf("\n");
            }
        }
    }
    return 0;
}
