#include <stdio.h>
#include <string.h>

char braille[10][6] = {".***..", "*.....", "*.*...", "**....", "**.*..", "*..*..", "***...", "****..", "*.**..", ".**..."};
int backbraille[16] = {0,1,2,3,4,2,9,6,8,5,10,4,12,8,0,7};

int main()
{
    int d, len, i, j, val;
    char digits[130], t;
    char l1[400], l2[400], l3[400];

    while(scanf("%d", &d) && d)
    {
        scanf(" %c ", &t);
        if(t == 'S')
        {
            scanf(" %s ", digits);
            len = strlen(digits);
            for(i=0;i<3;i++)
            {
                for(j=0;j<len;j++)
                {
                    printf("%c%c ", braille[digits[j]-'0'][2*i], braille[digits[j]-'0'][2*i+1]);
                }
                printf("\n");
            }
        }
        else
        {
            scanf("%[^\n] ", l1);
            scanf("%[^\n] ", l2);
            scanf("%[^\n]", l3);
            for(i=0;i<d;i++)
            {
                val = 0;
                if(l1[3*i]=='*') val+=1; 
                if(l1[3*i+1]=='*') val+=2;
                if(l2[3*i]=='*') val+=4;
                if(l2[3*i+1]=='*') val+=8;
                printf("%c", '0'+backbraille[val]);
            }
            printf("\n");
        }
    }
    return 0;
}
