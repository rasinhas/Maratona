#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class LittleElephantAndBooks
{
    public:
    int getNumber(vector<int> pages,int number)
    {
        int r;
        sort(pages.begin(),pages.end());
        for(int i=0;i<number-1;i++) r += pages[i];
        r += pages[number];
        return r;
    }
}
