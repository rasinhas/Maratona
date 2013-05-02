#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t=1;
    string str;
    while(cin >> str && str != "*")
    {
        if(str == "Hajj") printf("Case %d: Hajj-e-Akbar\n", t++);
        else if(str == "Umrah") printf("Case %d: Hajj-e-Asghar\n", t++);
    }
    return 0;
}
