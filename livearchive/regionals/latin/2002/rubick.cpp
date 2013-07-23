#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

char rubick[60];
int base[6] = {46,28,1,10,19,37};

void rotate(int a, int b, int c, int d)
{
    swap(rubick[a],rubick[b]);
    swap(rubick[b],rubick[c]);
    swap(rubick[c],rubick[d]);
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

void print_cubo()
{
	int i, j, k;
	for(j=0;j<9;j++)
	{
		if(j%3 == 0) printf("\n   ");
		printf("%c",rubick[base[0]+j]);
	}
	printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++) for(k=0;k<3;k++) printf("%c",rubick[base[j+1]+3*i+k]);
		printf("\n");
    }
	for(j=0;j<9;j++)
	{
		if(j%3 == 0) printf("   ");
		printf("%c",rubick[base[5]+j]);
		if(j%3 == 2) printf("\n");
	}
}

int main()
{
    int n, i, j, k, l, m, flag;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<9;j++) scanf(" %c ", &rubick[46+j]);
        for(l=0;l<3;l++) for(j=0;j<4;j++) for(k=0;k<3;k++) scanf(" %c ", &rubick[base[j+1]+3*l+k]);
        for(j=0;j<9;j++) scanf(" %c ", &rubick[37+j]);
        while(scanf("%d", &m) && m)
        {
            if(m == 1) mv_l();
            else if(m == 2) mv_f();
            else if(m == 3) mv_r();
            else if(m == 4) mv_b();
            else if(m == 5) mv_u();
            else if(m == 6) mv_d();
            else if(m == -1) { mv_l(); mv_l(); mv_l(); }
            else if(m == -2) { mv_f(); mv_f(); mv_f(); }
            else if(m == -3) { mv_r(); mv_r(); mv_r(); }
            else if(m == -4) { mv_b(); mv_b(); mv_b(); }
            else if(m == -5) { mv_u(); mv_u(); mv_u(); } 
            else if(m == -6) { mv_d(); mv_d(); mv_d(); }
        }
		print_cubo();
        flag = 0;
        for(j=0;j<6;j++)
        {
            for(k=1;k<9;k++)
            {
                if(rubick[base[j]+k] != rubick[base[j]])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) printf("No, you are wrong!\n");
        else printf("Yes, grandpa!\n");
    }
    return 0;
}
