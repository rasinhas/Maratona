#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define INF 0x3f3f3f

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main()
{
	int reino[2][105][105];
	int i, j, x, y;
	int n, r, c, k;
	while(scanf("%d %d %d %d", &n, &r, &c, &k) && n)
	{
		for(i=1;i<=r;i++)
		{
			reino[0][i][0] = -2;
			reino[0][i][c+1] = -2;
			reino[1][i][0] = -2;
			reino[1][i][c+1] = -2;
			for(j=1;j<=c;j++)
			{
				scanf("%d", &reino[0][i][j]);
				reino[0][0][j] = -2;
				reino[0][r+1][j] = -2;
				reino[1][0][j] = -2;
				reino[1][r+1][j] = -2;
			}
		}
		for(i=0;i<k;i++)
		{
			for(x=1;x<=r;x++)
			{
				for(y=1;y<=c;y++)
				{
					reino[(i+1)%2][x][y] = reino[i%2][x][y] ;
					for(j=0;j<4;j++)
					{
						if((reino[i%2][x+dx[j]][y+dy[j]] + 1)%n == reino[i%2][x][y])
						{
							reino[(i+1)%2][x][y] = (reino[i%2][x+dx[j]][y+dy[j]]) ;
							break;
						}
					}
				}
			}
		}
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				printf("%d ", reino[k%2][i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}



