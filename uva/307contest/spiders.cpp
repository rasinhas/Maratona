#include <stdio.h>
#include <string.h>

using namespace std;

int d, p;
double s[100001];
char line[1010000];

int main()
{
    double a, b;
    int i, f, k, len, j;
    char *pch;
    while(scanf("%[^\n]", line) != EOF)
    {
        pch = strtok(line," ");
        sscanf(pch,"%d",&d);
        pch = strtok(NULL," ");
        sscanf(pch,"%d",&p);
        pch = strtok(NULL," ");
        k = 0;
        for(i=0;i<=d;i++) s[i] = -1;
        while(pch != NULL)
        {
            sscanf(pch,"%lf",&s[k]);
            pch = strtok(NULL," ");
            k++;
        }
        if(s[0] > p) printf("The spider is going to fall!\n");
        else
        {
            k--;
            if(s[k-1]*s[k-3] != s[k-2]*s[k-2] && s[k-2])
            {
                a = (s[k]*s[k-3] - s[k-1]*s[k-2])/(s[k-1]*s[k-3] - s[k-2]*s[k-2]);
                b = (s[k] - a*s[k-1])/s[k-2];
            }
            else
            {
                b = (s[k]*s[k-2] - s[k-1]*s[k-1])/(s[k-1]*(s[k-2]-s[k-3]));
                a = (s[k]-b*s[k-2])/s[k-1];
            }
            for(i=0;i<=d;i++)
            {
                if(s[i] == -1) s[i] = a*s[i-1] + b*s[i-2];
                if(s[i] > p) break;
            }
            if(i == d+1) printf("The spider may fall!\n");
            else printf("%d\n", d-i+1);
        }
        getc(stdin);
    }
    return 0;
}
