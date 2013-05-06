#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n;
    int gg, xij, xji, xii, xjj, oij, oji, oii, ojj;
    char win;
    string tab[4];
    scanf("%d", &n);
    for(int t=0;t<n;t++)
    {
        gg = 1;
        win = ' ';
        for(int i=0;i<4;i++) cin >> tab[i];
        printf("Case #%d: ", t+1);
        oii = xii = ojj = xjj = 0;
        for(int i=0;i<4;i++)
        {
            oij = oji = xij = xji = 0;
            if(tab[i][i] == 'X') xii++;
            if(tab[i][i] == 'O') oii++;
            if(tab[i][i] == 'T') xii++, oii++;
            if(tab[i][3-i] == 'X') xjj++;
            if(tab[i][3-i] == 'O') ojj++;
            if(tab[i][3-i] == 'T') xjj++, ojj++;
            for(int j=0;j<4;j++)
            {
                if(tab[i][j] == '.') gg = 0;
                if(tab[i][j] == 'O') oij++;
                if(tab[i][j] == 'X') xij++;
                if(tab[i][j] == 'T') xij++, oij++;
                if(tab[j][i] == 'O') oji++;
                if(tab[j][i] == 'X') xji++;
                if(tab[j][i] == 'T') xji++, oji++;
            }
            if(oij == 4 || oji == 4 || oii == 4 || ojj == 4) win = 'O'; 
            if(xij == 4 || xji == 4 || xii == 4 || xjj == 4) win = 'X';
            if(win != ' ') break;
        }
        if(win == ' ')
        {
            if(gg) printf("Draw\n");
            else printf("Game has not completed\n");
        }
        else printf("%c won\n", win);
    }
    return 0;
}
