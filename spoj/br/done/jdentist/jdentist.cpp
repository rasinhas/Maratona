#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int i;
	vector <pair<int,int> > horarios;
	pair <int,int> horario;
	int n, fi, ff, consultas;
    scanf("%d", &n);
    consultas=0;
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &fi, &ff);
        horario = make_pair(fi,ff);
        horarios.push_back(horario);
    }
    sort(horarios.begin(),horarios.end());
    horario = horarios[0];
    consultas++;
    for(i=0;i<n;i++)
    {
        if(horarios[i].first < horario.second) 
        {
            horario.first = horarios[i].first;
            if(horarios[i].second < horario.second) horario.second = horarios[i].second;
        }
        else
        {
            horario = horarios[i];
            consultas++;
        }
    }
    printf("%d\n", consultas);
    horarios.clear();
	return 0;
}
