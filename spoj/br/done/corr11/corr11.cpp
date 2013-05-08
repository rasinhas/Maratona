#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#define INF 0x3f3f3f3f
#define rep(i,k) for((i)=0;(i)<(k);(i)++)

using namespace std;

int main()
{
	vector<pair <int,int> > carros;
	int n, m, i, j, t, ttot;
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++)
	{
		ttot = 0;
		for(j=0;j<m;j++)
		{
			scanf("%d", &t);
			ttot += t;
		}
		carros.push_back(make_pair(ttot, i+1));
	}
	sort(carros.begin(),carros.end());
	printf("%d\n", carros.at(0).second);
	printf("%d\n", carros.at(1).second);
	printf("%d\n", carros.at(2).second);
	return 0;
}
