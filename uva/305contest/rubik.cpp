#include <iostream>
#include <ctype.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

char mov[100];
int cubos[60], vis[60];
vector <int> ciclos;

int mdc(int a, int b)
{
    if(a % b == 0) return b;
    return mdc(b, a % b);
}

/*
Modelagem do cubo

  ---       T=> top
  |T|       F=> front
---------   R=> right
|F|R|B|L|   B=> back
---------   L=> left
  |D|       D=> down
  ---
           ------------
           | 46 47 48 |
           | 49 50 51 |
           | 52 53 54 |
---------------------------------------------
| 1  2  3  | 10 11 12 | 19 20 21 | 28 29 30 |
| 4  5  6  | 13 14 15 | 22 23 24 | 31 32 33 |
| 7  8  9  | 16 17 18 | 25 26 27 | 34 35 35 |
---------------------------------------------
           | 37 38 39 |
           | 40 41 42 |
           | 43 44 45 |
           ------------

Movimentos modelados no sentido horário.
Para girar no anti-horario, repete-se o 
movimento 3 vezes no sentido horário.
*/

int bases[6]={46,1,10,19,28,37};

void print_cubo()
{
    for(i=0;i<6;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%d",cubos[bases[i]+j]);
            if(j%3 == 2) printf("\n");
        }
    }
}

void rotate(int a, int b, int c, int d)
{
    swap(cubos[a],cubos[b]);
    swap(cubos[b],cubos[c]);
    swap(cubos[c],cubos[d]);
}

void mv_r()
{
    rotate(3,39,25,48);
    rotate(6,42,22,51);
    rotate(9,45,19,54);
    rotate(10,16,18,12);
    rotate(11,13,17,15);
}

void mv_l()
{
    rotate(1,46,27,37);
    rotate(4,49,24,40);
    rotate(7,52,21,43);
    rotate(28,34,36,30);
    rotate(29,31,35,33);
}

void mv_u()
{
    rotate(1,10,19,28);
    rotate(2,11,20,29);
    rotate(3,12,21,30);
    rotate(52,54,48,46);
    rotate(53,51,47,49);
}

void mv_d()
{
    rotate(7,34,25,16);
    rotate(8,35,26,17);
    rotate(9,36,27,18);
    rotate(37,43,45,39);
    rotate(38,40,44,42);
}

void mv_b()
{
    rotate(12,45,34,46);
    rotate(15,44,31,47);
    rotate(18,43,28,48);
    rotate(19,25,27,21);
    rotate(20,22,26,24);
}

void mv_f()
{
    rotate(30,37,16,54);
    rotate(33,38,13,53);
    rotate(36,39,10,52);
    rotate(1,7,9,3);
    rotate(2,4,8,6);
}

void executa()
{
    int i, len;
    len = strlen(mov);
    for(i=0;i<len;i++)
    {
        if(mov[i] == 'R') mv_r();
        else if(mov[i] == 'r') { mv_r(); mv_r(); mv_r();}
        else if(mov[i] == 'L') mv_l();
        else if(mov[i] == 'l') { mv_l(); mv_l(); mv_l();}
        else if(mov[i] == 'U') mv_u();
        else if(mov[i] == 'u') { mv_u(); mv_u(); mv_u();}
        else if(mov[i] == 'D') mv_d();
        else if(mov[i] == 'd') { mv_d(); mv_d(); mv_d();}
        else if(mov[i] == 'B') mv_b();
        else if(mov[i] == 'b') { mv_b(); mv_b(); mv_b();}
        else if(mov[i] == 'F') mv_f();
        else if(mov[i] == 'f') { mv_f(); mv_f(); mv_f();}
    }
}



int main()
{
    int i, cicl_cnt, a, mmc;
    while(scanf(" %s", mov) != EOF)
    {
        memset(vis,0,sizeof(vis));
        ciclos.clear();
        for(i=1;i<55;i++) cubos[i] = i;
        executa();
        //for(i=1;i<55;i++) printf("%d |", cubos[i]);
        //printf("\n\n");
        for(i=1;i<55;i++) if(!vis[i])
        {
            a = i;
            vis[i] = 1;
            cicl_cnt = 1;
            while(!vis[cubos[a]])
            {
                cicl_cnt++;
                a = cubos[a];
                vis[a] = 1;
            }
            if(cicl_cnt > 1) ciclos.push_back(cicl_cnt);
        }
        if(ciclos.size() == 0) printf("1\n");
        else if(ciclos.size() == 1) printf("%d\n", ciclos[0]);
        else
        {
            mmc = ciclos[0];
            for(i=1;i<ciclos.size();i++)
            {
                mmc = mmc*ciclos[i]/mdc(mmc,ciclos[i]);
            }
            printf("%d\n", mmc);
        }
    }
    return 0;
}
