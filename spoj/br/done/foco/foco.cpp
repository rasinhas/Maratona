#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int i;
	vector <pair<int,int> > intervalos;
	pair <int,int> intervalo;
	int n, fi, ff, fotos;
	while(scanf("%d", &n) != EOF)
	{
		fotos=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d", &fi, &ff);
			intervalo = make_pair(fi,ff);
			intervalos.push_back(intervalo);
		}
		sort(intervalos.begin(),intervalos.end());
		intervalo = intervalos[0];
		fotos++;
		for(i=0;i<n;i++)
		{
			if(intervalos[i].first <= intervalo.second) 
			{
				intervalo.first = intervalos[i].first;
				if(intervalos[i].second < intervalo.second) intervalo.second = intervalos[i].second;
			}
			else
			{
				intervalo = intervalos[i];
				fotos++;
			}
		}
		printf("%d\n", fotos);
		intervalos.clear();
	}
	return 0;
}
