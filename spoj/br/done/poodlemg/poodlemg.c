#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int n, p, i, pages;
    char poodle[30];
    while(scanf("%d %d",&n, &p) && n)
    {
        for(i=0;i<21;i++) poodle[i]='\0';
        if(n%p==0) pages=(n/p);
        else pages=(n/p)+1;
        poodle[0]='P';
        poodle[1]='o';
        poodle[2]='o';
        if(pages>6)
        {
            for(i=3;i<pages-3;i++)
            {
                poodle[i]='o';
                if(i==17) break; 
            }
            poodle[i]='d';
            poodle[i+1]='l';
            poodle[i+2]='e';
        }
        else
        {
            poodle[3]='d';
            poodle[4]='l';
            poodle[5]='e';
        }
        printf("%s\n",poodle);
    }
    return 0;
}
