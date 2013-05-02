#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, len, vazios, i, pos, aux;
    string carta, ordem[500];
    scanf("%d", &n);
    aux = n;
    pos = 0;
    do
    {
        cin >> carta;
        len = carta.size();
        vazios = 0;
        pos = (pos+len-1)%aux;
        for(i=0;i<n;i++)
        {
            if(!ordem[i].size()) vazios++;
            if(pos+1 == vazios) 
            {
                ordem[i] = carta;
                break;
            }
        }
    }while(--aux);
    for(i=0;i<n;i++) cout << ordem[i] << endl;
    return 0;
}
