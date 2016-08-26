#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long sss[3333333];

class YetAnotherTwoTeamsProblem {
    public:
    long long count(vector <int> skill)
    {
        long long s = 0;
        long long mv=0;
        long long ret=0;
        for(int i=0;i<skill.size();i++) s += skill[i];
        sort(skill.begin(),skill.end(),greater<int>());
        sss[0] = 1;
        for(int i=0;i<skill.size();i++)
        {
            for(int j=mv;j>=0;j--)
            {
                sss[j+skill[i]] += sss[j];
                if(2*j+2*skill[i] > s && 2*j < s) ret += sss[j];
            }
            mv += skill[i];
        }
        return ret;
    }
};
